#pragma once
#include<iostream>
#include <string>
using namespace std;

class IoBase
{
public:
	virtual istream& read(istream& in);
	virtual ostream& write(ostream& out);
	friend ostream& operator<<(ostream& out, const IoBase& base);
	friend istream& operator>>(istream& in, IoBase& base);
};