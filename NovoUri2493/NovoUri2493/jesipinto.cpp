#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> explode(const string& s, const char& c);
string implode(const string& glue, const vector<string>& pieces);

vector<string> explode(const string& s, const char& c)
{
	string buff{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n != c) buff += n; else
			if (n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if (buff != "") v.push_back(buff);

	return v;
}

string implode(const string& glue, const vector<string>& pieces)
{
	string a;
	int leng = pieces.size();
	for (int i = 0; i < leng; i++)
	{
		a += pieces[i];
		if (i < (leng - 1))
			a += glue;
	}
	return a;
}

int one()
{
	int rounds{};
	vector<string> outputs{};
	while (scanf_s("%d", &rounds) == 1)
	{
		int x{};
		vector<vector<int>> equations;
		for (int i = 0; i < rounds; i++)
		{
			string yz{};
			cin >> x >> yz;
			vector<string> v{ explode(yz, '=') };
			equations.push_back({ x, stoi(v[0]), stoi(v[1]) });
		}
		int choice{};
		string name{};
		char operation{};
		vector<string> loosers{};
		for (int i = 0; i < rounds; i++)
		{
			cin >> name >> choice >> operation;
			choice -= 1;
			vector<int> equation = equations[choice];
			switch (operation)
			{
			case '*':
				if (equation[0] * equation[1] != equation[2]) {
					loosers.push_back(name);
				}
				break;
			case 'I':
				if (equation[0] * equation[1] == equation[2] || (equation[0] + equation[1] == equation[2]) || equation[0] - equation[1] == equation[2])
				{
					loosers.push_back(name);
				}
				break;
			case '+':
				if (equation[0] + equation[1] != equation[2]) {
					loosers.push_back(name);
				}
				break;
			case '-':
				if (equation[0] - equation[1] != equation[2]) {
					loosers.push_back(name);
				}
				break;
			}
		}

		if (loosers.size() == 0)
		{
			outputs.push_back("You Shall All Pass!");
		}
		else if (loosers.size() == rounds)
		{
			outputs.push_back("None Shall Pass!");
		}
		else
		{
			int size = sizeof(loosers) / sizeof(loosers[0]);
			sort(loosers.begin(), loosers.end());
			outputs.push_back(implode(" ", loosers));
		}
	}
	for (string& output : outputs)
	{
		cout << output << endl;
	}
	return 0;
}