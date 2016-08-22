#include "FibonacciR.hpp"
#include <iostream>
using std::cout;

FibonacciR::FibonacciR() {}

FibonacciR::FibonacciR(const int &n) :n_(&n) {}

FibonacciR::~FibonacciR() {}

int FibonacciR::Fibonacci(const int &n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

//	cout << "Recursively determining Fibonaci sequence number: " << *n_ << " = " << Fibonacci(n - 1) + Fibonacci(n - 2) << "\n";

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void FibonacciR::PrintFibonacci() {
  	int FibonaciNum = Fibonacci(*n_);
  	cout << "Recursively determined Fibonaci number " << *n_ << " = " << FibonaciNum << "\n";
}