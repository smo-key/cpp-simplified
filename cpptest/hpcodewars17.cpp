#include "hpcodewars17.h"

int main()
{
	p3();

	pause();
	return 0;
}

void p0()
{
	cout << "Team 1234 is ready for CodeWars 17!" << endl;
}

void p1()
{
	reader in = reader("datasets/prob01-1-in.txt");
	while (!in.iseof()) {
		int n = in.read<int>();
		if (n == 0) { return; }
		cout << n << " " << p1_formula(n) << endl;
	}
}
int p1_formula(int t)
{
	return 100 * sqrt(t) + 201 / (t + 1) + 1;
}

//NOT COMPLETE
void p2()
{
	reader in("datasets/prob02-1-in.txt");
	int c = in.read<int>();
	for (int i = 0; i < c; i++)
	{
		int a[11];
		int evens = 0;
		int odds = 0;

		for (int j = 0; j < 11; j++)
		{
			a[j] = in.read<int>();
			if (j + 1 % 2 == 0) { odds += a[j]; } //even
			else { evens += a[j]; }
			cout << a[j] << " ";
		}
		int remain = ((3 * odds) + evens) % 10;
		if (remain != 0) { remain = 10 - remain; }
		cout << remain << endl;
	}
}

void p3()
{
	reader in("datasets/prob03-1-in.txt");
	char lookup[11] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	//TODO array searching
	//TODO char to integer (via ASCII)
	int amps[11] = { 2, 5, 5, 4, 5, 6, 3, 7, 6, 6 };
	int c = in.read<int>();

	for (int i = 0; i < c; i++)
	{
		string s = in.readline();
		int ma = 0;
		for (int j = 0; j < s.length(); j++)
		{
			char k = s.at(j);
			if (k == ':') { ma += 20; break; }
			for (int l = 0; l < 11; l++)
			{
				if (k == lookup[l]) { ma += 15 * amps[l]; break; }
			}
		}
		cout << ma << " milliamps" << endl;
	}
}