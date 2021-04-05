#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "Vendor.h"
using namespace std;

int main()
{
	char choice;
	string filename = "ListOfFlowers.txt";
	Vendor* vendor = new Vendor("Vendor");
	while (true)
	{
		cout << "Choose an action:\n1 - Add\n2 - Edit\n3 - Delete\n4 - Show\n5 - Search\n6 - Exit\n";
		choice = _getch();
		if (choice < '1' || choice > '6')
		{
			cout << "Try again...\n";
			continue;
		}
		cout << endl;
		switch (choice)
		{
		case '1':
			vendor->Add(filename);
			system("pause");
			system("cls");
			break;
		case '2':
			vendor->Edit(filename);
			system("pause");
			system("cls");
			break;
		case '3':
			vendor->Delete(filename);
			system("pause");
			system("cls");
			break;
		case '4':
			vendor->Show(filename);
			system("pause");
			system("cls");
			break;
		case '5':
			vendor->Search(filename);
			system("pause");
			system("cls");
			break;
		case '6':
			return 0;
		}
	}
}
