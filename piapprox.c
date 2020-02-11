// Ben Mikailenko

// to make - 'make'

// to run - './piapprox'

// note: make sure terminal is of sufficient size

// to clean - 'make clean'

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288 /* pi */
#endif

long double func(long double x) {
	return 4.0L / (1.0L + (x*x));
}

long double trap(long double(*f) (long double), long double a, long double b, int n) {
	const long double h = (b-a)/n;
	long double sum = 0.5*(f(a) + f(b));
	long double inc = h;
	long double x;
	for (int i = 1; i < n; i++, inc += h) {
		x = a + inc;
		sum = sum + f(x);
	}
	sum = sum * h;
	return sum;
}

long double simp(long double(*f) (long double), long double a, long double b, int n) {
	const long double h = (b-a)/n;
	long double sum = (f(a) + f(b));
	long double inc = h;
	long double x;
	int k = 0;
	for (int i = 1; i < n; i++, inc += h) {
		x = a + inc;
		if (k == 0){
			sum += (4 * f(x));
			k = 1;
			continue;
		}
		if (k == 1){
			sum += (2 * f(x));
			k = 0;
			continue;
		}
	}

	sum = (sum * h) / 3;
	return sum;
}

long double simp3(long double(*f) (long double), long double a, long double b, int n) {
	const long double h = (b-a)/n;
	long double sum = (f(a) + f(b));
	long double inc = h;
	long double x;
	int k = 0;
	for (int i = 1; i < n; i++, inc += h) {
		x = a + inc;

		if (k == 0){
			sum = sum + (3 * f(x));
			k = 1;
			continue;
		}
		if (k == 1){
			sum = sum + (3 * f(x));
			k = 2;
			continue;
		}
		if (k == 2){
			sum = sum + (2 * f(x));
			k = 0;
			continue;
		}
	}
	sum = sum * (( 3 * h ) / 8);
	return sum;
}

long double boole(long double(*f) (long double), long double a, long double b, long n) {
	const long double h = (b-a)/n;
	long double sum = 7 * (f(a) + f(b));
	long double inc = h;
	long double x;
	int k = 0;
	for (int i = 1; i < n; i++, inc += h) {
		x = a + inc;
		if (k == 0){
			sum = sum + (32 * f(x));
			k = 1;
			continue;
		}
		if (k == 1){
			sum = sum + (12 * f(x));
			k = 2;
			continue;
		}
		if (k == 2){
			sum = sum + (32 * f(x));
			k = 3;
			continue;
		}
		if (k == 3){
			sum = sum + (14 * f(x));
			k = 0;
			continue;
		}
	}
	sum = sum * ((2*h)/45);
	return sum;
}

int main(int argc, char *argv[]) {

	for (int i = 0; i < 17; i++ ) {
		int n = 12 * pow(2, i);
		printf("%d     ", n);
		printf("%0.10Le     ", trap(func, 0, 1, n) - M_PI);
		printf("%0.10Le     ", simp(func, 0, 1, n) - M_PI);
		printf("%0.10Le     ", simp3(func, 0, 1, n) - M_PI);
		printf("%0.10Le\n", boole(func, 0, 1, n) - M_PI);
	}

	return 0;
}
