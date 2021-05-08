#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class MinStack {
private:
	vector<int> _data, _minimums;
public:
	MinStack() { /* Nothing to really initalize. */ }

	void push(int x) {
		if(_data.empty() || _minimums.back() >= x) {
			_minimums.push_back(x);
		}
		_data.push_back(x);
	}

	void pop() {
		if(_minimums.back() == top()) {
			_minimums.pop_back();
		}
		_data.pop_back();
	}

	int top() {
		return _data.back();
	}

	int getMin() {
		return _minimums.back();
	}
};

int main(int argc, char const *argv[]) {
	MinStack obj;
	srand(time(NULL));

	cout << "Pushed: ";
	for(int i = 0; i < 20; i++) {
		int x = rand() % 10;
		obj.push(x);
		cout << x << " ";
	}

	cout << endl;

	for(int i = 0; i < 20; i++) {
		cout << "Top: " << obj.top() << " Minimum: " << obj.getMin() << endl;
		obj.pop();
	}

	return 0;
}