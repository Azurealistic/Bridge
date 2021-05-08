#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Type { // Covered in chapter 3 of Savitch, sure it's marked optional but I read it anyway! 
	ANT = 1,
	DOODLEBUG = 2
};

class Organism {
public:
	Organism(Type type) : _type{ type }, _breed{ 0 }, _recently_moved{ false} {};
	virtual ~Organism() = default; // Stops the program from crashing because reasons.
	virtual void move() = 0; // Virtual for you..
	virtual Type getType() const = 0; // And you..
	virtual bool getMoved() const = 0; // And you..
	virtual void resetMoveState() = 0; // And you...
	virtual void resetBreed() = 0;
	virtual int getBreed() const = 0;
	virtual	int getStarve() const { return 0; };
	virtual void resetStarve() {}; // And you!

protected:
	Type _type; // What kind of organism is this??!
	int _breed; // Time step till it can breed.
	bool _recently_moved; // They're like goldfish, swear to god.
};

class Ant : public Organism {
public:
	Ant() : Organism(Type::ANT) {} // I bet this bug has an IQ of 69.
	void move(); // Just increases some counters, really. Boring function.
	bool getMoved() const;
	void resetMoveState();
	void resetBreed();
	int getBreed() const;
	Type getType() const;
};

class Doodlebug : public Organism {
public:
	Doodlebug() : Organism(Type::DOODLEBUG), _starve{ 0 } {} // Probably has an IQ of like.. 70.
	void move(); 
	bool getMoved() const;
	void resetMoveState();
	void resetBreed();
	int getBreed() const;
	int getStarve() const;
	void resetStarve();
	Type getType() const;

private:
	int _starve;
};
	
class World {
public:
	World(int width, int height, int n, int m) : _width{ width }, _height{ height }, _timestep{ 0 } { // Size of world, also how many ants and doodlebugs to use.
		_world.resize(width * height, nullptr); // Resize the initial world vector to be all nullptrs initially.
		placeOrganisms(m, Type::ANT); // OH DUH I COULD USE ONE FUNCTION AND JUST PASS THE TYPE WHY DIDN'T I THINK OF THIS EARLIER?!
		placeOrganisms(n, Type::DOODLEBUG); // Samesies.
	}

	~World() { // Clean up the world.
		for(auto& location : _world) {
			if(location != nullptr) {
				delete location;
				location = nullptr;
			}
		}
	}

	void display(int width, int height); // Print out the current-state of the world, taking in the width/height of the world.
	void timeStep(); // Perform one singular time-step in our world.
	void setBugStarveTime(int n);
	void setOrganismBreedTimes(int m, int n);

private:
	int getIndex(int x, int y); // Convert an x/y coordinate into an index for the vector.
	void placeOrganisms(int n, Type type); // Amount and type to place into the world.
	void moveDoodlebugs(); // Move all the doodle-bugs according to rules.
	void moveAnts(); // Move all ants randomly.
	void resetMovementFlags(); // Reset movement flag for everything!
	void breedOrganisms(); // Breed all organisms 
	void starveOrganisms(); // Starve/kill off any doodlebugs that don't win the darwin award.

	vector<Organism*> _world; // A single dimensional vector that we simply use our coordinate system to check if it is out of bounds or not.
	int _width, _height;
	int _timestep;
	int _ant_breed, _doodlebug_breed, _doodlebug_starve;
};

int main(int argc, char const* argv[]) {
	srand(time(NULL)); // It's like vegas, but actually worse odds!
	const int W_WIDTH = 20, W_HEIGHT = 20, ANTS = 100, DOODLEBUGS = 5, ANT_BREED = 3, DOODLEBUG_BREED = 8, DOODLEBUG_STARVE = 3; // You can have a non-square world if you want!
	World camelot(W_WIDTH, W_HEIGHT, DOODLEBUGS, ANTS); // Would it be Queen Arthur? Or are we going full Fate/Stay Night here instead..
	camelot.setBugStarveTime(DOODLEBUG_STARVE); // Using a setter here cause I don't wanna muck up the constructor more.
	camelot.setOrganismBreedTimes(ANT_BREED, DOODLEBUG_BREED);
	camelot.display(W_WIDTH, W_HEIGHT);
	cout << "Please hit enter for next time-step, or any other key to exit!" << endl;
	while(cin.get() == '\n') {
		camelot.timeStep();
		camelot.display(W_WIDTH, W_HEIGHT);
		cout << "Please hit enter for next time-step, or any other key and then enter to exit!" << endl;
	}
	return 0;
}

int Ant::getBreed() const {
	return _breed;
}

void Ant::resetBreed() {
	_breed = 0; // If only it was this easy to use birth control.
}

void Ant::move() {
	_breed += 1; // Look Ma! I can count!
	_recently_moved = true;
}

bool Ant::getMoved() const {
	return _recently_moved; // Swear I was over there..
}

Type Ant::getType() const {
	return _type;
}

void Ant::resetMoveState() {
	_recently_moved = false;
}

int Doodlebug::getStarve() const {
	return _starve; // Gib noms please.
}

void Doodlebug::resetStarve() {
	_starve = 0;
}

int Doodlebug::getBreed() const {
	return _breed;
}

void Doodlebug::resetBreed() {
	_breed = 0;	
}

bool Doodlebug::getMoved() const {
	return _recently_moved;
}

void Doodlebug::move() {
	_breed += 1;
	_starve += 1;
	_recently_moved = true;
}

Type Doodlebug::getType() const {
	return _type;
}

void Doodlebug::resetMoveState() {
	_recently_moved = false;
}

void World::setBugStarveTime(int n) {
	_doodlebug_starve = n;
}

void World::setOrganismBreedTimes(int m, int n) {
	_ant_breed = m;
	_doodlebug_breed = n;
}

void World::breedOrganisms() { // Function that will go through everything and try to breed each item, as possible.
	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			if(_world[getIndex(x, y)] == nullptr) {
				continue;
			}
			bool breed = false;
			std::vector<int> nxy = { x + 1, y, x - 1, y, x, y + 1, x, y - 1 }; // Vector for places to check.
			for (int i = 0, j = 1; i < 8; i += 2, j += 2) { // Loop through the four possibilities.
				if ((nxy[i] < 0) || (nxy[i] > _width) || (nxy[j] < 0) || (nxy[j] >= _height) || breed) {
					continue; // If our spot next to us is out of bounds, check next spot.
				} else if (_world[getIndex(nxy[i], nxy[j])] == nullptr && _world[getIndex(x, y)]->getType() == Type::ANT &&  _world[getIndex(x, y)]->getBreed() >= _ant_breed) {
					_world[getIndex(nxy[i], nxy[j])] = new Ant(); // If that spot is empty, create a new ant in that location.
					_world[getIndex(x, y)]->resetBreed(); // Reset this particular ant back to 0. Doesn't reset if it didn't breed.
					breed = true;
				}  else if (_world[getIndex(nxy[i], nxy[j])] == nullptr && _world[getIndex(x, y)]->getType() == Type::DOODLEBUG &&  _world[getIndex(x, y)]->getBreed() >= _doodlebug_breed) {
					_world[getIndex(nxy[i], nxy[j])] = new Doodlebug();
					_world[getIndex(x, y)]->resetBreed();
					breed = true;
				}
			}
		}
	}
}

void World::resetMovementFlags() {
	for(auto& location : _world) {
		if(location != nullptr) {
			location->resetMoveState(); // AMNESIA TIME
		}
	}
}

void World::moveDoodlebugs() { // Most of this is similar to moveAnts.
	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			int random = rand() % 4; // 0 to 3.
			int delta_x = 0, delta_y = 0;
			if(random == 0) {
				delta_x += 1;
			} else if (random == 1) {
				delta_x -= 1;
			} else if (random == 2) {
				delta_y += 1;
			} else if (random == 3) {
				delta_y -= 1;
			}
			if (_world[getIndex(x, y)] == nullptr) {
				continue;
			}
			bool exists = (_world[getIndex(x, y)]->getType() == Type::DOODLEBUG);
			if(!exists || _world[getIndex(x, y)]->getMoved()) {
				continue;
			}
			std::vector<int> nxy = { x + 1, y, x - 1, y, x, y + 1, x, y - 1 };
			bool ate_something = false;
			for (int i = 0, j = 1; i < 8; i += 2, j += 2) {
				if(ate_something) {
					continue;
				} else if ((nxy[i] < 0) || (nxy[i] > _width) || (nxy[j] < 0) || (nxy[j] >= _height)) {
					continue;
				} else if(_world[getIndex(nxy[i], nxy[j])] == nullptr || _world[getIndex(nxy[i], nxy[j])]->getType() == Type::DOODLEBUG) {
					continue;
				} else if(_world[getIndex(nxy[i], nxy[j])]->getType() == Type::ANT) {
					delete _world[getIndex(nxy[i], nxy[j])]; 
					_world[getIndex(nxy[i], nxy[j])] = _world[getIndex(x, y)]; // Move doodlebug to that specific new position.
					_world[getIndex(x, y)] = nullptr; // Mark old position as nullptr.
					_world[getIndex(nxy[i], nxy[j])]->move();
					_world[getIndex(nxy[i], nxy[j])]->resetStarve(); // Since we ate we reset the starving
					ate_something = true;
				}
			}
			if(!ate_something) { // If we have not eaten anything, then we do the following:
				int new_x = x + delta_x;
				int new_y = y + delta_y;
				if ((new_x < 0) || (new_x > _width) || (new_y < 0) || (new_y >= _height)) {
					continue; // Skip to next cell.
				}
				bool next_square = (_world[getIndex(new_x, new_y)] == nullptr);
				if(exists && next_square) {
					_world[getIndex(new_x, new_y)] = _world[getIndex(x, y)];
					_world[getIndex(x, y)] = nullptr;
					_world[getIndex(new_x, new_y)]->move();
				}
			}
		}
	}
}

void World::moveAnts() {
	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			int random = rand() % 4; // 0 to 3.
			int delta_x = 0, delta_y = 0;
			if(random == 0) { // This was a switch but that had more lines so I got annoyed and changed it.
				delta_x += 1;
			} else if (random == 1) {
				delta_x -= 1;
			} else if (random == 2) {
				delta_y += 1;
			} else if (random == 3) {
				delta_y -= 1;
			}
			if (_world[getIndex(x, y)] == nullptr) { // I KNEW nullptrs would burn me later on.
				continue;
			}
			bool exists = (_world[getIndex(x, y)]->getType() == Type::ANT);
			int new_x = x + delta_x;
			int new_y = y + delta_y;
			if ((new_x < 0) || (new_x > _width) || (new_y < 0) || (new_y >= _height) || _world[getIndex(x, y)]->getMoved()) {
				continue; // Skip to next cell.
			}
			bool next_square = (_world[getIndex(new_x, new_y)] == nullptr);
			if (exists && next_square) {
				_world[getIndex(new_x, new_y)] = _world[getIndex(x, y)];
				_world[getIndex(x, y)] = nullptr;
				_world[getIndex(new_x, new_y)]->move();
			}
		}
	}
}

void World::timeStep() {
	_timestep += 1; // BLACK SHEEP OF THE FUNCTION. HOW DARE IT NOT BE A FUNCTION CALL!?
	moveDoodlebugs();
	moveAnts();
	breedOrganisms();
	starveOrganisms();
	resetMovementFlags();
}

void World::starveOrganisms() {
	for(auto& creature : _world) {
		if(creature != nullptr && creature->getType() == Type::DOODLEBUG && creature->getStarve() >= _doodlebug_starve) { // I bet I could make this longer.
			delete creature;
			creature = nullptr;
		}
	}
}

void World::placeOrganisms(int n, Type type) {
	while(n) {
		int x = rand() % _width;
		int y = rand() % _height;
		if (_world[getIndex(x, y)] == nullptr) {
			n -= 1;
			if(type == Type::DOODLEBUG) {
				_world[getIndex(x, y)] = new Doodlebug(); // A BUG FOR YOU
			} else if(type == Type::ANT) {
				_world[getIndex(x, y)] = new Ant(); // AND A BUG FOR YOU!
			}
		}
	}
}

void World::display(int width, int height) {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (_world[getIndex(x, y)] == nullptr) { // I'm going to get so many nullptr issues aren't I? 
				cout << '-' << ' '; // Woops forgot a space..
			} else {
				if (_world[getIndex(x, y)]->getType() == Type::ANT) {
					cout << 'o' << ' ';
				} else if (_world[getIndex(x, y)]->getType() == Type::DOODLEBUG) {
					cout << 'X' << ' '; 
				}
			}
		}
		cout << endl;
	}
}

int World::getIndex(int x, int y) {
	return (_width * y) + x; // Just basic math, pretty easy to figure out, it's like taking a building and making it a train.
}