#include <stdio.h>
#include <stdbool.h>

long long factorial(int n) {
	long long result = 1;
	for (int i = 1; i <= n; ++i) {
		result *= i;
	}
	return result;
}
bool is_prime(int num) {
	if (num < 2) return false;
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) return false;
	}
	return true;
}
int main() {
	int n;
	printf("Enter n: ");
	if (scanf("%d", &n) != 1) {
		printf("Invalid input.\n");
		return 1;
	}
	if (n < 0) {
		printf("Error: n must be non-negative.\n");
		return 1;
	}
	printf("%d! = %lld\n", n, factorial(n));
	printf("Primes less than or equal to %d:\n", n);
	for (int i = 2; i <= n; ++i) {
		if (is_prime(i)) {
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}