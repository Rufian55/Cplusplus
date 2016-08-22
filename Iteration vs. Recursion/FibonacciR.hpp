#ifndef FIBONACCIR_HPP
#define FIBONACCIR_HPP

class FibonacciR {
private:
	FibonacciR();
	int Fibonacci(const int &n);
	const int *n_;
public:
	FibonacciR(const int &n);
	virtual ~FibonacciR();
	void PrintFibonacci();
};
#endif // FIBONACCIR_HPP
