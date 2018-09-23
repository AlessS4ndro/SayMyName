#include <iostream>

using namespace std;

// N^a
template <long N,unsigned int A>
struct pow
{
	static long const value = N * pow<N,A-1>::value;
};

// N^1 == N
template <long N>
struct pow<N,1>
{
	static long const value = N;
};

// N^0 == 1
template <long N>
struct pow <N,0>
{
	static long const value = 1;
};

int main(int argc , char ** argv)
{
	long a,b,c;
	a = pow <2,63>::value ; 		// 100
	b = pow <2,3>::value;			// 8
	c = pow<1234,0>::value;			// 1
	
	cout<<"\nla variable a es: "<<a
		<<"\nla variable b es : "<<b
		<< "\nla variable c es: "<<c;

	int arreglo[pow<2,10>::value] ; // un arreglo de 1024 elementos
	return 0;
}
