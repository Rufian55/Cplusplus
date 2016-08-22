#ifndef FIBONACCINR_HPP
#define FIBONACCINR_HPP

class FibonacciNR {
private:
	FibonacciNR();
	int Fibonacci(const int &n);
	const int* n_;

public:
	FibonacciNR(const int &n);
	virtual ~FibonacciNR();
	void PrintFibonacci();

};
#endif
