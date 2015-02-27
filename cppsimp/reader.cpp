#include "cppsimp.h"

reader::reader(istream& in)
{
	this->in = &in;
}

reader::reader(const char* file, istream& in)
{
	ifstream* fin = new ifstream(file);
	this->in = choose(&in, fin);
}

istream* reader::choose(istream* in, ifstream* fin)
{
	if (fin != 0) { if (fin->good()) { return fin; } }
	if (in != 0) { return in; }
	else { throw new exception("No input streams found!"); }
}

istream* reader::stream() { return in; }

istringstream* reader::sstream()
{
	return (istringstream*)in;
}

bool reader::islocal()
{
	return (stream() == in);
}

bool reader::iseof()
{
	return stream()->eof();
}

string reader::readall()
{
	istream* is = stream();
	string str((istreambuf_iterator<char>(*is)), istreambuf_iterator<char>());
	return str;
}

string reader::readline()
{
	string line;
	getline(*in, line);
	return line;
}