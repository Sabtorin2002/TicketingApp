#pragma once
#include <iostream>
#include <string>
using namespace std;

class Eveniment
{
private:
	char* numeEveniment;
	string dataEveniment;
	string ora;
	static string oras;
	const int idEveniment;
	static int idEvenimentCurent;
	static char charInvalid;
public:
	Eveniment();
	Eveniment(const char* numeEveniment, string dataEveniment, string ora);
	Eveniment(const Eveniment& e);
	~Eveniment();
	Eveniment& operator=(const Eveniment& e);
	void setNumeEveniment(const char* numeEveniment);
	char* getNumeEveniment();
	static int getidEvenimentCurent();
	string getOra();
	string getDataEveniment();
	static string getOras();
	bool operator!();
	char& operator[](int index);
	int getidEveniment();
	string getNumeEvenimentAsString();
	friend ostream& operator<<(ostream& out, Eveniment e);
	friend istream& operator>>(istream& in, Eveniment& e);

}; 