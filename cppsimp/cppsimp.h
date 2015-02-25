#include <stdio.h>
#include <iostream>

using namespace std;

namespace cppsimp
{
	//general functions
	void pause();

	//std IO
	template<class T>
	T read(istream& in = cin)
	{
		T x;
		in >> x;
		return x;
	}
	template<class T>
	void write(T out)
	{
		cout << out;
	}
	template<class T>
	void writeln(T out)
	{
		cout << out << endl;
	}

	//TODO file IO

}