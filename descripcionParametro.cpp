#include <iostream>

using namespace std;

template <typename T>
struct type_descriptor
{
	template <typename OS>
	OS& write (OS& os) const{return os<<"unknow-type";}
};

template <>
struct type_descriptor<int>
{
	template <typename OS>
	OS& write(OS& os) const{return os<<"int";}
}; 

template <>
struct type_descriptor<char>
{
	template <typename OS>
	OS& write(OS& os) const {return os<<"char";}
};
template <>
struct type_descriptor<long>
{
	template <typename OS>
	OS& write(OS& os) const {return os<<"long";}
};
template <>
struct type_descriptor<short>
{
	template <typename OS>
	OS& write(OS& os) const {return os<<"short";}
};
template <typename T>
struct type_descriptor<T const>
{
	template <typename OS>
	OS& write(OS& os) const {return os<<"const "<<type_descriptor<T>();}
};
template <typename T>
struct type_descriptor<T volatile>
{
	template <typename OS> 
	OS& write(OS& os) const {return os<<"volatile "<<type_descriptor<T>();}
};
template <typename T>
struct type_descriptor<T&>
{
	template <typename OS>
	OS& write(OS& os) const {return os<<"reference to "<<type_descriptor<T>();}
};
template <typename T>
struct type_descriptor<T*>
{
	template <typename OS>
	OS& write(OS& os) const {return os<<"pointer to "<<type_descriptor<T>();}
};
template <typename T>
struct type_descriptor<T[]>
{
	template <typename OS>
	OS& write(OS& os) const {return os<<"array of "<<type_descriptor<T>();}
};

template <typename T, int N>
struct type_descriptor<T[N]>
{
	template <typename OS>
	OS& write(OS& os) const {return os<<"array ["<<N<<"] of "<<type_descriptor<T>();}
};
template <typename R>
struct type_descriptor<R ()>
{
	template <typename OS>
	OS& write(OS& os) const {return os<<"function returning "<<type_descriptor<R>();}
};
template <typename OS, typename T>
OS& operator << (OS& os, type_descriptor<T> const &type)
{
	return type.write(os);
}

int main(int argc, char *argv[])
{
	cout << type_descriptor<int *>() << endl;
	cout << type_descriptor<long *(* const)()>() << endl;
	cout << type_descriptor<int volatile * const& (*[10])()>() << endl;
	
	return 0;

} 
