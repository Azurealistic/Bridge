#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sorting {
public:
	virtual void sort(std::vector<int>& vec) = 0; // I made this a reference cause it makes more sense.
	virtual string worst_case_runtime() = 0;
};

/*
The concept of insertion sort is simple, you take some unsorted array and step through each item in the vector.
Once it comes across a situation where two numbers adjacent to each other are not sorted, it swaps them. 
It does this check after every swap and keeps swapping values until they are all sorted.
*/
class InsertionSort : public Sorting {
public:
	void sort(std::vector<int>& vec) {
		int i = 1;
		while(i < vec.size()) {
			int j = i;
			while(j > 0 && vec[j - 1] > vec[j]) {
				std::swap(vec[j], vec[j - 1]);
				j -= 1;
			}
			i += 1;
		}
	}

	string worst_case_runtime() {
		return "O(n^2)";
	}
};

/*
Merge sort simply breaks down the vector into left and right sub-vectors, and then merges them back up in a sorted order.
*/
class MergeSort : public Sorting {
public:
	void sort(std::vector<int>& vec) {
		vec = mergeSort(vec);
	}

	string worst_case_runtime() {
		return "O(n log n)";
	}

private:
	std::vector<int> mergeSort(std::vector<int>& vec) {
		if(vec.size() <= 1) {
			return vec; // Size of one or empty can stop here.
		} 

		vector<int> left, right;
		int middle = (vec.size() + 1) / 2; // Dividing point.

		for(int i = 0; i < middle; i++) {
			left.push_back(vec[i]); // Fill left sub-vector.
		}

		for(int i = middle; i < vec.size(); i++) {
			right.push_back(vec[i]);  // Fill right sub-vector.
		}

		// Recursively sort.
		left = mergeSort(left); 
		right = mergeSort(right);

		// Merge the two sub-vectors back up.
		return merge(left, right);
	} 

	// This merging function is fairly straight forward.
	std::vector<int> merge(std::vector<int> left, std::vector<int> right) {
		std::vector<int> res;
		while(left.size() > 0 || right.size() > 0) { // We essentially check to see that either left or right has some elements in it.
			if(left.size() > 0 && right.size() > 0) { // If they both have elements, we push the lower one to the merged vector and erase it from the original.
				if(left.front() <= right.front()) {
					res.push_back(left.front());
					left.erase(left.begin());
				} else {
					res.push_back(right.front());
					right.erase(right.begin());
				}
			} else if(left.size() > 0) { // If we have only one of the two vectors left over, we simply copy over the remaining numbers and then break out of the loop.
				res.insert(res.end(), left.begin(), left.end());
				break;
			} else if(right.size() > 0) {
				res.insert(res.end(), right.begin(), right.end());
				break;
			}
		} 
		return res;
	}
};

/*
Quick sort is also fairly straight forward. We assign the last element in the current vector as our pivot.
Then we go through the vectors and swap all elements around such that anything smaller than pivot is to the left, greateris to the right.
We then recursively call the function on the two sub-vectors not including the pivot and sort them. The result being that it will eventually sort the vector.
*/
class QuickSort : public Sorting {
public:
	void sort(std::vector<int>& vec) {
		quicksort(vec, 0, vec.size() - 1);
	}

	string worst_case_runtime() {
		return "O(n^2)";
	}

private:
	void quicksort(std::vector<int>& vec, int left, int right) {
		if(left < right) {
			int pivot = partition(vec, left, right);
			quicksort(vec, left, pivot - 1);
			quicksort(vec, pivot, right);
    	}
	}

	int partition(std::vector<int>& vec, int left, int right) {
		int pIdx = left + (right - left) / 2;
		int pVal = vec[pIdx];
		int temp;
		while(left <= right) {
			while(vec[left] < pVal) {
				left += 1;
			}
			while(vec[right] > pVal) {
				right -= 1;
			}
			if(left <= right) {
				std::swap(vec[left++], vec[right--]);
			}
		}
		return left;
	} 
};

int main(int argc, char const *argv[]) {
	// Make our three class objects to test with.
	{
		QuickSort s;
		vector<int> vec;
		for(int i = 0; i < 20; i++) {
			vec.push_back(rand() % 200);
		}
		s.sort(vec);
		cout << "Quick Sort:" << endl;
		for(auto it = vec.begin(); it != vec.end(); it++) {
			cout << *it << ' ';
		}
		cout << endl << s.worst_case_runtime() << endl << endl;
	}

	{
		MergeSort s;
		vector<int> vec;
		for(int i = 0; i < 20; i++) {
			vec.push_back(rand() % 200);
		}
		s.sort(vec);
		cout << "Merge Sort:" << endl;
		for(auto it = vec.begin(); it != vec.end(); it++) {
			cout << *it << ' ';
		}
		cout << endl << s.worst_case_runtime() << endl << endl;
	}

	{
		InsertionSort s;
		vector<int> vec;
		for(int i = 0; i < 20; i++) {
			vec.push_back(rand() % 200);
		}
		s.sort(vec);
		cout << "Insertion Sort:" << endl;
		for(auto it = vec.begin(); it != vec.end(); it++) {
			cout << *it << ' ';
		}
		cout << endl << s.worst_case_runtime() << endl;
	}

	return 0;
}