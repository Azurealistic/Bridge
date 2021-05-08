#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Queue {
public:
	// Constructor
	Queue() : _sidx {0}, _eidx {0} {}

	// Member functions, should have all of them pretty much.
	// Notes on swap and emplace: I could write these but I don't think they're in the scope of the assignment, 
	// furthermore we haven't covered std::forward in this lecture to implement emplace yet.
	
	// Element access.
	T front() const {
		return _data[_sidx];
	}

	T back() const {
		return _data[_eidx];
	}

	// Capacity 
	int size() const {
		return _data.size() - _sidx;
	}

	bool empty() const {
		return _data.empty();
	}

	// Modifiers.
	void push(T t) {
		_data.push_back(t);
		_eidx = _data.size() - 1;
	}

	void pop() {
		if(!_data.empty()) {
			_sidx += 1;
			if(_eidx + 1 == _sidx) {
				_data.clear();
				_sidx = 0;
				_eidx = 0;
			}
		}
	}
	
	void printQueue() {
		for(auto const& e : _data) {
			cout << e << " " << endl;
		}
	}

private:
	int _sidx, _eidx;
	vector<T> _data;
};

int main(int argc, char const *argv[]) {
	// Testing/driver code.
	Queue<int> queue; 

	// Perform a size check.
	std::cout << "Size: " << queue.size() << std::endl << std::endl;

	// Push some stuff and then check front/back.
	queue.push(5);
	queue.push(3);
	queue.push(6);
	queue.push(2);

	std::cout << "Front: " << queue.front() << std::endl;
	std::cout << "Back: " << queue.back() << std::endl;
	std::cout << "Size: " << queue.size() << std::endl << std::endl;

	// Pop a few things and then see what happens.
	queue.pop();
	queue.pop();

	std::cout << "Front: " << queue.front() << std::endl;
	std::cout << "Back: " << queue.back() << std::endl;
	std::cout << "Size: " << queue.size() << std::endl << std::endl;
	
	// Pop remaining and check if it's empty/size is good.
	queue.pop();
	queue.pop();

	std::cout << "Size: " << queue.size() << std::endl;
	std::cout << "Empty: " << queue.empty() << std::endl << std::endl;

	// A bit more testing.
	queue.push(3);
	queue.push(6);
	std::cout << "Front: " << queue.front() << std::endl;
	std::cout << "Back: " << queue.back() << std::endl;
	std::cout << "Empty: " << queue.empty() << std::endl;
	std::cout << "Size: " << queue.size() << std::endl << std::endl;

	// Final set.
	queue.pop();
	queue.pop();

	std::cout << "Size: " << queue.size() << std::endl;
	std::cout << "Empty: " << queue.empty() << std::endl << std::endl;

	queue.pop();

	return 0;
}