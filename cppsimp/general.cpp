#include "cppsimp.h"

void cppsimp::pause() {
	_getwch();
}

bool cppsimp::fileExists(const char *fileName)
{
	ifstream infile(fileName);
	return infile.good();
}

string cppsimp::itos(int i) {
	return static_cast<ostringstream*>(&(ostringstream() << i))->str();
}