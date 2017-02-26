/* * It's an algorithm to multiply two numbers
 * * with O(n*lgn) complexity.
 * * Source for this particular one (i.e. where I learned it from):
 * * https://classroom.udacity.com/courses/cs215/lessons/48747095/concepts/487341140923
 * * 
 * * Author: Rifaz Nahiyan
 * */

#include <stdio.h>

long long int russian_recursive(long long int a, long long int b) {

	if (a == 0) return 0;

	if (a % 2 == 0) return 2 * russian_recursive( a / 2, b);

	return b + 2 * russian_recursive((a-1) / 2, b);
}

int main(void) {
	printf("4 * 2: %lld\n", russian_recursive(4, 2));
	printf("16 * 42: %lld\n", russian_recursive(16, 42));
	printf("999 * 999: %lld\n", russian_recursive(999, 999));

	return 0;
}
