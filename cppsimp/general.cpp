#include "cppsimp.h"

void cppsimp::pause() {
	_getwch();
}

bool cppsimp::fileExists(const char *fileName)
{
	ifstream infile(fileName);
	return infile.good();
}