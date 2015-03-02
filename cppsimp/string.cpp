#include "cppsimp.h"

// trim from start
string& str::triml(string &s) {
	s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
	return s;
}

// trim from end
string& str::trimr(string &s) {
	s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
	return s;
}

// trim from both ends
string& str::trim(string &s) {
	return triml(trimr(s));
}

vector<string> str::split(string s, string delim)
{
	vector<string> v = vector<string>();
	size_t pos = 0;
	string token;
	while ((pos = s.find(delim)) != string::npos)
	{
		v.push_back(s.substr(0, pos));
		s.erase(0, pos + delim.length());
	}
	v.push_back(s);
	return v;
}

bool str::instring(string s, string test)
{
	return s.find(test) != string::npos;
}

char* str::tochararray(string s)
{
	char* writable = new char[s.size() + 1];
	std::copy(s.begin(), s.end(), writable);
	writable[s.size()] = '\0'; // don't forget the terminating 0

	// don't forget to free the string after finished using it
	return writable;
}
string str::tostring(char* c)
{
	string s(c);
	return s;
}

bool str::doesmatch(string s, regex r)
{
	return regex_match(s, r);
}
bool str::isfound(string s, regex r)
{
	return regex_search(s, r);
}
string str::list(string s, regex r)
{
	//TODO search string and return array containing list of results
	return NULL;
}
int str::count(string s, regex r)
{
	//TODO search string and return matches
	return NULL;
}
string str::remove(string s, regex r)
{
	return regex_replace(s, r, "");
}
string str::replace(string s, regex r, string rep)
{
	return regex_replace(s, r, rep);
}