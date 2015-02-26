#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include "stdio.h"

using namespace std;

namespace cppsimp
{
	//general functions
	void pause();
	bool fileExists();

	//standard in/out
	class io;

	//doubled reader
	class reader;

	//string functions
	class str;

	//Stardard Console IO
	template<class T>
	static T read(istream& in)
	{
		T x;
		in >> x;
		return x;
	}
	template<class T>
	static void write(T out)
	{
		cout << out;
	}
	template<class T>
	static void write(string out)
	{
		cout << out;
	}
	static void write(char* out, int length)
	{
		cout.write(out, length);
	}

	template<class T>
	static void writeln(T out)
	{
		write<T>(out);
		cout << endl;
	}
}

class cppsimp::str abstract
{
public:
	static string& str::triml(string &s);
	static string& str::trimr(string &s);
	static string& str::trim(string &s);
};

class cppsimp::reader
{
private:
	istream* in;

public:
	reader(istream& in = cin);
	reader(const char* file, istream& in = cin);

	template<class T>
	T read()
	{
		T x;
		istream* s = stream();
		*s >> x;
		return x;
	}
	template<>
	string read<string>()
	{
		string x;
		istringstream* s = sstream();
		*s >> x;
		return x;
	}

	char* readline()
	{
		//TODO implement
		char* x = 0;
		istream* s = stream();
		s->getline(x, 1);
		return x;
	}

	char* readuntil(char ch)
	{
		//TODO implement
	}

	string readall();

	//istream& operator>> (streambuf* sb );

	//TODO string to char* and char* to string

	template<class T>
	T operator>>(T& other)
	{
		return read<T>();
	}

	bool iseof();
	bool islocal();
	istream* stream();
	istringstream* sstream();

private:
	istream* choose(istream* in, ifstream* fin);
};

using namespace cppsimp;