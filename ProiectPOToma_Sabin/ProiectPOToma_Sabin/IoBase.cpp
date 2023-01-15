#include <iostream>
#include <string>
using namespace std;

class IoBase
{
public:
	virtual istream& read(istream& in)
	{
		return in;
	}
	virtual ostream& write(ostream& out)const
	{
		return out;
	}
	friend ostream& operator<<(ostream& out, const IoBase& base)
	{
		return base.write(out);
	}
	friend istream& operator>>(istream& in, IoBase& base)
	{
		return base.read(in);
	}
	
};