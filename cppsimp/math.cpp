#include "cppsimp.h"

bool math::isprime(unsigned int number)
{
	if (number > 3) {
		if (number % 2 == 0) return false;

		const unsigned int MAX = (unsigned int)sqrt(number) + 1;
		for (unsigned int i = 3; i < MAX; i += 2)
			if ((number % i) == 0)
				return false;

		return true;
	}

	if (number < 2) return false;

	return true;
}