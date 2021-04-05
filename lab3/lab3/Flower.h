#pragma once
#include <iostream>
using namespace std;

class Flower
{
public:
	int amount;
	string name;
	Flower();
	Flower(string, int); 

	void Show();
};
