#include "hpcodewars17.h"

//TODO array searching
//TODO char to integer (via ASCII)
//TODO define starting ASCII values for letters, numbers, etc.

int main()
{
	p8();

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

//TODO NOT COMPLETE
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
	char lookup[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	int amps[10] = { 2, 5, 5, 4, 5, 6, 3, 7, 6, 6 };
	int c = in.read<int>();

	for (int i = 0; i < c; i++)
	{
		string s = in.readline();
		int ma = 0;
		for (uint j = 0; j < s.length(); j++)
		{
			char k = s.at(j);
			if (k == ':') { ma += 20; continue; }
			for (int l = 0; l < 10; l++)
			{
				if (k == lookup[l]) 
				{ ma += (15 * amps[l]); break; }
			}
		}
		cout << ma << " milliamps" << endl;
	}
}

void p4()
{
	reader in = reader("datasets/prob04-2-in.txt");
	int jar = in.read<int>();
	int c = in.read<int>();
	string closest = "";
	int closesti = 999999;

	for (int i = 0; i < c; i++)
	{
		int cnt = in.read<int>();
		string name = in.read<string>();
		if (abs(cnt - jar) == closesti) { closest = closest.append(" ").append(name); continue; }
		if (abs(cnt - jar) < closesti) { closest = name; closesti = abs(cnt - jar); }
	}
	cout << closest << endl;
}

void p5()
{
	char a[26];
	for (int i = 0; i < 26; i++)
	{
		a[i] = str::ASCII_A + i;
	}

	reader in = reader("datasets/prob05-1-in.txt");
	while (!in.iseof())
	{
		string line = in.readline();
		if (line.at(0) == '.') { return; }
		bool b[26]; for (int j = 0; j < 26; j++) { b[j] = false; }
		bool perfect = true;
		for (int i = 0; i < line.length(); i++)
		{
			int k = (int)line.at(i);
			if ((k < (int)str::ASCII_A) || (k >= (int)str::ASCII_A + 26)) { continue; }
			if (b[(int)k - str::ASCII_A]) { perfect = false; }
			b[(int)k - str::ASCII_A] = true;
		}
		bool pangram = true;
		for (int i = 0; i < 26; i++)
		{
			if (b[i] == false) { pangram = false; break; }
		}
		string status = pangram ? (perfect ? "PERFECT" : "PANGRAM") : "NEITHER";
		cout << status << ": " << line << endl;
	}
}

void p6()
{
	//auto alphanumeric = [&](char i) { return true; };

	regex alnum_apos("[^A-Za-z0-9' ]");

	string list[] = { "DON'T", "CAN'T", "ISN'T", "HAVEN'T", "CANNOT", "WOULDN'T", "COULDN'T", "WON'T", "NO", "NOT", "NEVER", "NOBODY", "NOWHERE", "NEITHER", "AIN'T" };
	reader in("datasets/prob06-1-in.txt");
	while (!in.iseof())
	{
		string line = in.readline();
		string linemod = "";
		if (line.at(0) == '.') { return; }
		linemod = str::remove(line, alnum_apos);
		vector<string> words = str::split(linemod, " ");
		int c = 0;
		for (int i = 0; i < words.size(); i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (words.at(i) == list[j])
				{ c++; }
			}
		}
		cout << c << ": " << line << endl;
	}
}

//TODO not complete
void p7()
{
	int n[6] = { 1, 5, 10, 100, 1000, 10000 };
	char* l = "IPDHCM";
	reader in("datasets/prob07-1-in.txt");
	regex isnum("[0-9]");
	int c = in.read<int>();
	for (int i = 0; i < c; i++)
	{
		string s = in.read<string>();
		if (str::doesmatch(s, isnum))
		{
			//number -> roman
			int k = stoi(s);
			
		}
		else
		{

		}
	}
}

void p8() 
{
	reader in("datasets/prob08-1-in.txt");
	while (!in.iseof())
	{
		int c = in.read<int>();
		if (c == 0) { return; }
		vector<string> v = vector<string>();
		while (true)
		{
			string s = in.read<string>();
			if (s == "$") {
				cout << v.at(v.size() - c) << endl; break;
			}
			v.push_back(s);
		}
	}
}