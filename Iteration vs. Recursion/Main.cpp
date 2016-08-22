#include "FibonacciNR.hpp"
#include "FibonacciR.hpp"
#include "Recursions.hpp"
#include<iostream>
using std::cout;
using std::cin;
#include <time.h>
#define BILLION 1E9
#include <cstdio>


int main() {
	int i;
	int input1;
	int input2;
	double accum1, accum2, accum3, accum4;
	Recursions rec;					// Recursions object.
	struct timespec requestStart;			// Start		
	struct timespec requestEnd;			// End 

/************************************************************************
*		Recursion vs. Iteration with Fibonacci Numbers		*
*************************************************************************/
	input1 = rec.collect_1(0, 40);

	FibonacciR fr(input1); 

	cout << "\nFinding Fibonacci sequence number '" << input1 << "'...\n"
		<< "Calling Recursive Fibonacci implementation!" << "\n";

	/* Calculate time taken by a Recursive Function Call. */
	clock_gettime(CLOCK_REALTIME, &requestStart);
	fr.PrintFibonacci(); // "Recursive"
	clock_gettime(CLOCK_REALTIME, &requestEnd);

	/* Display time taken by a Recursive Function Call. */
	accum1 = (requestEnd.tv_sec - requestStart.tv_sec)
		+ (requestEnd.tv_nsec - requestStart.tv_nsec)
		/ BILLION;
	std::printf("%lf\n", accum1);

	cout << "\nCalling Non-Recursive Fibonacci implementation!" << "\n";

	FibonacciNR fnr(input1);

	/* Calculate time taken by a Recursive Function Call. */
	clock_gettime(CLOCK_REALTIME, &requestStart);
	fnr.PrintFibonacci(); // "Non Recursive (Iterative)"
	clock_gettime(CLOCK_REALTIME, &requestEnd);

	/* Display time taken by a Recursive Function Call. */
	accum2 = (requestEnd.tv_sec - requestStart.tv_sec)
		+ (requestEnd.tv_nsec - requestStart.tv_nsec)
		/ BILLION;
	std::printf("%lf\n", accum2);


/************************************************************************
*		Tail Recursion vs. Non Tail Recursion.			*
*************************************************************************/
	input2 = rec.collect_2(0, 50);

	cout << "\nCalling Non Tail Recursive Factorial Function\n";

	/* Calculate time taken by a Non Tail Recursive Factorial Function Call. */
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &requestStart);
	
	for (i = 1; i < 1000; i++) {
		rec.rfactorial(input2); // "Non Tail Recursive"
	}

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &requestEnd);

	/* Display time taken by a Recursive Function Call. */
	accum3 = (requestEnd.tv_sec - requestStart.tv_sec)
		+ (requestEnd.tv_nsec - requestStart.tv_nsec);
	std::printf("%lf\n", accum3);
	cout << "\nNon Tail recursion function for int " << input2 << " = "
		<< rec.rfactorial(input2) << "\n";
	
	cout << "\nCalling Tail Recursive Factorial Function\n";

	/* Calculate time taken by a Tail Recursive Factorial Function Call. */
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &requestStart);

	for (i = 1; i < 1000; i++) {
		rec.factorial(input2); 	// "Tail Recursive"
	}
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &requestEnd);

	/* Display time taken by a Recursive Function Call. */
	accum4 = (requestEnd.tv_sec - requestStart.tv_sec)
		+ (requestEnd.tv_nsec - requestStart.tv_nsec);
	std::printf("%lf\n", accum4);

	cout << "\nTail recursion function for int " << input2 << " = "
		<< rec.factorial(input2) << "\n";
}
