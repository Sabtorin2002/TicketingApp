#pragma once
#include <iostream>
#include <string>
using namespace std;

class Bilet
{
private:
	float pret;
	string nume;
	char* tipZona;
	int varsta;
	const int idBilet;
	static int idBiletCurent;
public:
	Bilet();
	Bilet(float pret, string nume, const char* tipZona, int varsta);
	Bilet(const Bilet& b);
	~Bilet();
	Bilet& operator=(const Bilet& b);
	void settipZona(const char* tipZona);
	char* gettipZona();
	void setNume(string nume);
	string getNume();
	void setVarsta(int varsta);
	int getVarsta();
	int getIdBilet() const;
	float getPret() const;
	static float profitBilete(float pret, int nrbilete,char* tipZona);
	float discountBilete(float pret, int procent, int varsta);
	float pretBilet(float pret);
	void operator+=(float valoare);
	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);

};