#pragma once
#include <iostream>
#include <string>
using namespace std;

class Locatie
{
private:
	int* zone;
	int sector;
	int loc;
	string numeLocatie;
	string numeZona;
	static string mesajInvalid;
public:
	Locatie();
	Locatie(int* zone,int sector,int loc, string numeLocatie, string numeZona);
	Locatie(const Locatie& l);
	~Locatie();
	Locatie& operator=(const Locatie& l);
	void setNumeZona(string numeZona);
	void setNumeLocatie(string numeLocatie);
	string getNumeLocatie();
	void setLoc(int loc);
	int getLoc();
	int getSector();
	void setSector(int sector);
	void setZone(int* zone,int loc);
	int* getZone();
	int getZone(int index);
	static int nrSectorPerZona(string numeZona, Locatie* zone, int nrZone);
	bool operator!();
	explicit operator string();
	friend ostream& operator<<(ostream&, Locatie);
	friend istream& operator>>(istream&, Locatie&);

};
//string Locatie::mesajInvalid = "Locul nu este valid";

