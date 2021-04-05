#include "flower.h"
#include <iostream>
using namespace std;

Flower::Flower()
{
	name = "Empty";
}

Flower::Flower(string n, int a)
{
	name = n;
	amount = a;
}

void Flower::Show()
{
	cout << "Name: " << this->name << "\tAmount: " << this->amount << endl;
}
