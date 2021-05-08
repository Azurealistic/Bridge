#include <iostream>
#include <algorithm> // std::max

// Given an array nums, find the length of the longest sequence of zeroes recursively. (Hint: You are allowed to use the std::max function from STL).
// [0, 0, 1, 0, 0, 0] = len(6).. so we can go from right to left. 
int maxZeroLength(int nums[], int len, int startIdx) {
	int count = 0, i = startIdx;
	// So i is the starting index.. then what if we checked how many zeros there are to the right of i... until the end of the function.
	// and once it hits the first non-zero after a set of zeros, we stop at that point.

	while(nums[i] != 0 && i < len) {
		i++; // So we skip everything that isn't a zero to begin with.
	} 

	// Then we have to count how many zeros in a row we have..
	while(nums[i] == 0 && i < len) {
		count++;
		i++; // Go to next index..
	}

	// So at this point we have all length of a sequence of zeros that began from the given starting index until it encountered some non-zero value or end of array.
	// So if we reached this point then if the array is out of elements, we can just return this value.
	if(i >= len) {
		return count;
	}

	// If that case didn't return count.. then we can use recursion and the value of i as our new starting index.. so in our example it would start at index 3 the second time.
	return std::max(count, maxZeroLength(nums, len, i));
}

int main(int argc, char const *argv[]) {
	int arr[14] = {0, 0, 1, 0, 0, 0, 0, 2, 2, 3, 1, 0, 0, 0};
	std::cout << maxZeroLength(arr, 14, 0) << std::endl;
	return 0;
}
