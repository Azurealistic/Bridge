#include <iostream>

/*
Q7
The question is as follows:

What is the worst-case runtime of the following algorithm?
(a) O(n^2) 
(b) O(n * m)
(c) O(m^2)
(d) O(n + m)

fun f(n: IntArray, m: IntArray) {
	for (i in 0..n.lastIndex) {
		for (j in 0..m.lastIndex) {
			// does something
		}
	}
}

We can translate this to the following code:
*/

void func(int n[], int m[]) {
	/*
	I've taken a couple of liberties here but the point remains..
	Since the problem is passing IntArray we know function is gonna take n[] and m[].
	If we are iterating from 0 to n.lastindex that means we are doing size of n - 1 loops, and size of m - 1 loops:
	Thus we can just check for i < n.size(); (This isn't possible in actual code, since you can't do this with an array, but again... a point)
	Thus the outer loop has n iterations and inner has m. So we multiply and we have a total of n * m so thus runtime is O(n * m) = option b.
	*/
	for(int i = 0; i < n.size(); i++) {
		for(int j = 0; j < m.size(); j++) {
			// Do something.
		}
	}
}

/*
Q8
The question is as follows:
What is the worst-case runtime of the following algorithm?

(a) O(n)
(b) O(n^2)
(c) O(log n)
(d) O(sqrt(n))

fun f(n: IntArray) {
	var i = 0
	var j = n.lastIndex
	while (i < j) {
		if (n[i] % 2 == 0) {
			i++
		} else {
			j--
		}
	}
}

We can mostly translate this the same way with just a little bit of artistic license:
*/

void func(int n[]) {
	int i = 0;
	int j = n.size() - 1; // The last index will be one less than the size of the array to begin with..
	while(i < j) { // So this will run until i == j.
		if(n[i] % 2 == 0) {  // If the array value at index i is even, we will increase i, else decrease j.
			i++;
		} else {
			j--;
		}
	}
}

/*
Thoughts:
Lets assume that we have the following array (size 10)
[2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

If we start at i = 0 and j = 9.
Then we will loop through and since the entire array is even we will have to keep increasing i each time..
That means we will have 10 i++, so this instance will run in O(n)..

Then it also follows that since we have an all odd array, we will need to decrease j 10 times, so that is also in O(n)

But what happens if we have evens and odds mixed? We will end up increasing i and decreasing j some amount.. so for example:

[1, 2, 3, 4, 5, 6, 7, 8, 9, 10] = n[]

Then for the following we have:

1 j--
2 i++
3 j--
4 i++
5 j--
6 i++
7 j--
8 i++
9 j--
10 i++

We say that we have 5 i++ and 5 j--, thus a total of 10, and so the runtime is still O(n). Thus the answer and worst-case runtime is going to be (a) O(n)
*/