#pragma once
#include <iostream>
#include "Flower.h"
using namespace std;

class Vendor
{
	string Name;
public:
	Vendor(string);

	void Add(string);
	void Edit(string);
	void Edit(string, string, int);
	void Delete(string);
	void Show(string);
	void Search(string);
	bool Search(string, string);

	friend istream& operator >>(istream& s, Flower& d);
	friend ostream& operator <<(ostream& s, Flower& d);
};

