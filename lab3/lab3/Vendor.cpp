#include "Vendor.h"
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Vendor::Vendor(string n)
{
	Name = n;
}

void Vendor::Delete(string filename)
{
	char ch[5];
	string searchStr;
	int newAmount;
	vector<string> arrstr;
	string str;
	ifstream in;

	this->Show(filename);

	cout << "Enter name of flower:" << endl;
	cin >> searchStr;
	int count = 0;
	in.open(filename);

	int i = 0;
	if (in.is_open())
	{
		while (!in.eof())
		{
			getline(in, str);
			if (str != "")
			{
				arrstr.push_back(str);
				for (int j = 0; j < searchStr.size(); j++)
				{
					if (str[j] == searchStr[j])
					{
						count++;
					}
				}
				if (count == searchStr.size())
				{
					cout << "String was founded, deleting...\n";
					
					arrstr.pop_back();
					str = "";
					count = 0;
				}
			}
		}
	}
	else
		cout << "Open file failing" << endl;
	in.close();

	ofstream out;
	out.open(filename);
	if (out.is_open())
	{
		for (int j = 0; j < arrstr.size(); j++)
		{
			out << arrstr[j] << "\n";
		}
		cout << "Record was deleted" << endl;
	}
	else
		cout << "Open fale failing" << endl;
	out.close();
}

void Vendor::Edit(string filename)
{
	char ch[5];
	string searchStr;
	int newAmount;
	vector<string> arrstr;
	string str;
	ifstream in;

	this->Show(filename);

	cout << "Enter name of flower:" << endl;
	cin >> searchStr;
	int count = 0;
	in.open(filename);

	int i = 0;
	if (in.is_open())
	{
		while (!in.eof())
		{
			getline(in, str);
			if (str != "")
			{
				arrstr.push_back(str);
				for (int j = 0; j < searchStr.size(); j++)
				{
					if (str[j] == searchStr[j])
					{
						count++;
					}
				}
				if (count == searchStr.size())
				{
					cout << "String was founded, enter new amount\n";
					str = searchStr;
					cin >> newAmount;
					while (!cin.good() || newAmount < 0)
					{
						cout << "Enter agein: ";
						cin >> newAmount;
					}
					_itoa_s(newAmount, ch, 10);
					str = str + " / " + ch;
					arrstr.pop_back();
					arrstr.push_back(str);
					str = "";
					count = 0;
				}
			}
		}
	}
	else
		cout << "Open file failing" << endl;
	in.close();

	ofstream out;
	out.open(filename);
	if (out.is_open())
	{
		for (int j = 0; j < arrstr.size(); j++)
		{
			out << arrstr[j] << "\n";
		}
		cout << "Record was written" << endl;
	}
	else
		cout << "Open fale failing" << endl;
	out.close();

}

void Vendor::Edit(string filename, string searchStr, int newAmount)
{
	char ch[5];
	vector<string> arrstr;
	string str;
	ifstream in;

	int count = 0;
	in.open(filename);

	int i = 0;
	if (in.is_open())
	{
		while (!in.eof())
		{
			getline(in, str);
			if (str != "")
			{
				arrstr.push_back(str);
				for (int j = 0; j < searchStr.size(); j++)
				{
					if (str[j] == searchStr[j])
					{
						count++;
					}
				}
				if (count == searchStr.size())
				{
					str = searchStr;
					_itoa_s(newAmount, ch, 10);
					str = str + " / " + ch;
					arrstr.pop_back();
					arrstr.push_back(str);
					str = "";
					count = 0;
				}
			}
		}
	}
	else
		cout << "Open file failing" << endl;
	in.close();

	ofstream out;
	out.open(filename);
	if (out.is_open())
	{
		for (int j = 0; j < arrstr.size(); j++)
		{
			out << arrstr[j] << "\n";
		}
		cout << "Record was rewritten" << endl;
	}
	else
		cout << "Open fale failing" << endl;
	out.close();

}

void Vendor::Search(string filename)
{
	char choice;
	string strFromFile, searchStr;
	int searchAmount;
	ifstream in;

	cout << "Select search type:\n1 - By name\n2 - By amount" << endl;
	choice = _getch();
	while (choice < '1' || choice > '2')
	{
		cout << "Select search type again: ";
		cin >> choice;
	}

	switch (choice)
	{
	case '1':
		cout << "Enter name of flower: ";
		cin >> searchStr;

		in.open(filename);

		if (in.is_open())
		{
			bool is_found = false;
			int count = 0;
			while (!in.eof())
			{
				strFromFile = "";
				getline(in, strFromFile);
				for (int i = 0; i < searchStr.length(); i++)
				{
					if (searchStr[i] == strFromFile[i])
					{
						count++;
						continue;
					}
					else
						break;
				}
				if (searchStr.length() == count)
				{
					cout << strFromFile << endl;
				}
				count = 0;
			}
		}
		else
			cout << "Open file failing" << endl;
		in.close();
		break;
	case '2':
		bool active = false;
		char LessOrMore;
		char str[10];

		cout << "Enter amount of flowers: ";
		cin >> searchAmount;
		while (!cin.good() || searchAmount < 0)
		{
			cout << "Enter amount of flowers again" << endl;
			cin >> searchAmount;
		}

		cout << "Choose:\n1 - less, then " << searchAmount << "\n2 - more, then " << searchAmount << endl;
		cin >> LessOrMore;
		while (LessOrMore < '0' || LessOrMore > '2')
		{
			cout << "Choose again" << endl;
			cin >> LessOrMore;
		}

		in.open(filename);

		if (in.is_open())
		{
			cout << "Results of founding:" << endl;
			while (!in.eof())
			{
				int n = 0;
				strFromFile = "";
				getline(in, strFromFile);
				for (int i = 1; i < strFromFile.length(); i++)
				{
					if (active)
					{
						str[n] = strFromFile[i];
						n++;
					}
					if (strFromFile[i - 1] == '/')
					{
						active = true;
					}
				}
				active = false;
				str[n] = '\0';
				if (LessOrMore == '1' ? atoi(str) <= searchAmount : atoi(str) >= searchAmount)
				{
					cout << strFromFile << endl;
				}
			}
		}
		else
			cout << "Open file failing" << endl;
		in.close();
		break;
	}
}

bool Vendor::Search(string filename, string searchStr)
{
	string strFromFile;
	int searchAmount;
	ifstream in;
	in.open(filename);

	if (in.is_open())
	{
		bool is_found = false;
		int count = 0;
		while (!in.eof())
		{
			strFromFile = "";
			getline(in, strFromFile);
			for (int i = 0; i < searchStr.length(); i++)
			{
				if (searchStr[i] == strFromFile[i])
				{
					count++;
					continue;
				}
				else
					break;
			}
			if (searchStr.length() == count)
			{
				return true;

			}
			count = 0;
		}
	}
	else
		cout << "Open file failing" << endl;
	in.close();
	return false;
}

void Vendor::Show(string filename)
{
	string str;
	ifstream in;

	in.open(filename);

	if (in.is_open())
	{
		while (!in.eof())
		{
			str = "";
			getline(in, str);
			cout << str << endl;
		}
	}
	else
		cout << "Open file failing" << endl;
	in.close();
}

void Vendor::Add(string filename)
{
	ofstream out;
	string flower;
	int amount;
	cout << "Enter name of flower: ";
	cin >> flower;
	cout << "Enter amount of " << flower << ": ";
	cin >> amount;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore();
		cout << "Enter amount of " << flower << " again: ";
		cin >> amount;
	}
	if (Search(filename, flower))
	{
		Edit(filename, flower, amount);
	}
	else
	{
		out.open(filename, ofstream::app);
		if (out.is_open())
		{
			out << flower << " / " << amount << "\n";
			cout << "Record was written" << endl;
		}
		else
			cout << "Open fale failing" << endl;
		out.close();
	}
}

istream& operator>>(istream& s, Flower& d) {
	char dummy;
	s >> d.name >> dummy >> d.amount;
	return s;
}


ostream& operator<<(ostream& s, Flower& d) {
	s << d.name << "/" << d.amount;
	return s;
}