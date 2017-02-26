/* * It's an algorithm to multiply two numbers
 * * with O(n*lgn) complexity.
 * * Source for this particular one (i.e. where I learned it from):
 * * https://classroom.udacity.com/courses/cs215/lessons/48747095/concepts/487341140923
 * * 
 * * Author: Rifaz Nahiyan
 * */

#include <stdio.h>

long long int russian(long long int a, long long int b) {
	long long int x = a;
	long long int y = b;
	long long int z = 0;

	while (x > 0) {
		if (x % 2 == 1) z += y;
		y = y << 1;
		x = x >> 1;
	}
	return z;
}

int main(void) {
	printf("4 * 2: %lld\n", russian(4, 2));
	printf("16 * 42: %lld\n", russian(16, 42));
	printf("999 * 999: %lld\n", russian(999, 999));

	return 0;
}
