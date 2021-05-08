#include <iostream>

// Template typename vs template class
template <typename T>
T max(T x, T y) {
	return (x > y) ? x : y;
}

template <class T>
class Cake {
public:
	Cake(T slices) : _slices{slices} {} 

	T getSlices() const {
		return _slices;
	}

private:
	T _slices;
};

int main(int argc, char const *argv[]) {
	auto m = max<int>(10, 11);
	std::cout << m << std::endl;
	Cake<double> cake(5.24);
	std::cout << cake.getSlices() << std::endl;
	return 0;
}
