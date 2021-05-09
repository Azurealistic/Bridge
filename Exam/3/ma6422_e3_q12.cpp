#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

template <class T>
class Stack {
private:
	queue<T> q1, q2;
	int _size;

public:
	Stack() : _size {0} {}

	void push(T data) {
		_size += 1;

		// So the idea is to put newest item in q1, everything else is in q2. Then we push everything from q2 onto q1. Then we swap the queues around.
		q1.push(data);

		while(!q2.empty()) {
			q1.push(q2.front());
			q2.pop();
		}

		std::swap(q1, q2);
	}

	void pop() {
		// If no elements in q1 we just return, else we pop off it and decrease _size by 1.
		if(q2.empty()) {
			return;
		} else {
			q2.pop();
			_size -= 1;
		}
	}

	T top() {
		if(q2.empty()) {
			exit(1);
		} else {
			return q2.front();
		}
	}

	bool empty() {
		return q2.empty();
	} 

	int size() const {
		return _size;
	}  
};

int main(int argc, char const *argv[]) {
	Stack<int> s;

	for(int i = 0; i < 10; i++) {
		int n = rand() % 10;
		s.push(n);
		cout << "Pushed: " << n << endl;
	}

	while(!s.empty()) {
		cout << "Top: " << s.top() << endl;
		s.pop();
	}

	return 0;
}