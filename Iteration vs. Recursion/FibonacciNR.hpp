/* (2)
FibonacciNR.hpp
Created on: Sep 11, 2010
Author: julian  
joseph.arul83@gmail.com
 */
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
#endif // FIBONACCINR_HPP