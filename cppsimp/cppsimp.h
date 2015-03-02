#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <vector>
#include <regex>
#include "stdio.h"

using namespace std;

namespace cppsimp
{
	//type definitions
	typedef unsigned int uint;
	
	//general functions
	void pause();
	bool fileExists(const char* filename);
	template <typename T>
	static string itos(T Number)
	{
		ostringstream ss;
		ss << Number;
		return ss.str();
	}
	template <typename T>
	T stoi(const string &Text)
	{
		istringstream ss(Text);
		T result;
		return ss >> result ? result : 0;
	}
	template<typename ArgType, typename Pred>
	static std::function<bool(ArgType)> invertpred(Pred &pred)
	{
		return [&pred](ArgType t)
		{ return !pred((ArgType)t); };
	}

	//standard in/out
	class io;

	//doubled reader
	class reader;

	//string functions
	class str;

	//array functions
	class arr;

	//math operations
	class math;

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

class cppsimp::arr abstract
{
	//TODO countif
	//TODO find
};

class cppsimp::math abstract
{
public:
	static bool isprime(unsigned int n);
};

class cppsimp::str abstract
{
public:
	static const char ASCII_space = 32;
	static const char ASCII_0 = 48;
	static const char ASCII_A = 65;
	static const char ASCII_Z = ASCII_A + 25;
	static const char ASCII_a = 97;
	static const char ASCII_z = ASCII_a + 25;

	static string& triml(string &s);
	static string& trimr(string &s);
	static string& trim(string &s);
	static vector<string> split(string s, string delim);
	static bool instring(string s, string test);

	static bool doesmatch(string s, regex r);
	static bool isfound(string s, regex r);
	static string list(string s, regex r);
	static int count(string s, regex r);
	static string remove(string s, regex r);
	static string replace(string s, regex r, string rep);

	static char* tochararray(string s);
	static string tostring(char* c);

	//TODO replaceif
	//TODO keepif
	//TODO countif
	//TODO regex match and replace methods
	//TODO reverse
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
	template<>
	char* read<char*>()
	{
		throw new exception("Cannot use read() on char*.  Use readsome() instead.");
		return NULL;
	}

	string readline();
	char* readuntil(char ch); //TODO implement
	string readall();

	//TODO implement
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