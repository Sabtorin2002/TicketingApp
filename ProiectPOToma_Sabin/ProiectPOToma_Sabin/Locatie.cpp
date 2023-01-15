#define _CRT_SECURE_NO_WARNINGS
#include "Locatie.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Locatie::Locatie()
{
	zone = nullptr;
	loc = 0;
	numeLocatie = "";
	numeZona = "";
	sector = 0;
}

Locatie::Locatie(int* zone, int sector,int loc, string numeLocatie, string numeZona)
{
	this->numeZona = numeZona;
	this->numeLocatie = numeLocatie;
	this->loc = loc;
	if (zone != nullptr && sector > 0)
	{
		this->zone = new int [sector];
		for (int i = 0; i < sector; i++)
		{
			this->zone[i] = zone[i];
		}
		this->sector = sector;
	}
	else
	{
		this->zone = nullptr;
		this->sector = 0;
	}
}

Locatie::Locatie(const Locatie& l)
{
	this->numeZona = l.numeZona;
	this->numeLocatie = l.numeLocatie;
	this->loc = loc;
	if (l.zone != nullptr && l.sector> 0)
	{
		this->zone = new int [l.sector];
		for (int i = 0; i < l.sector; i++)
		{
			this->zone[i] = l.zone[i];
		}
		this->sector = sector;
	}
	else
	{
		this->zone = nullptr;
		this->sector= 0;
	}
}

Locatie::~Locatie()
{
	if (zone != nullptr)
	{
		delete[]this->zone;
	}
}

Locatie& Locatie::operator=(const Locatie& l)
{
	if (this != &l)
	{
		if (this->zone != nullptr)
		{
			delete[]this->zone;
		}
		this->numeZona = l.numeZona;
		this->numeLocatie = l.numeLocatie;
		this->loc = loc;
		if (l.zone != nullptr && l.sector > 0)
		{
			this->zone = new int [l.sector];
			for (int i = 0; i < l.sector; i++)
			{
				this->zone[i] = l.zone[i];
			}
			this->sector = sector;
		}
		else
		{
			this->zone = nullptr;
			this->sector = 0;
		}
	}
	return *this;
}

void Locatie::setNumeZona(string numeZona)
{
	this->numeZona = numeZona;
}

void Locatie::setNumeLocatie(string numeLocatie)
{
	this->numeLocatie = numeLocatie;
}

string Locatie::getNumeLocatie()
{
	return numeLocatie;
}

void Locatie::setLoc(int loc)
{
	this->loc = loc;
}

int Locatie::getLoc()
{
	return loc;
}

int Locatie::getSector()
{
	return sector;
}
void Locatie::setSector(int sector)
{
	this->sector = sector;
}

void Locatie::setZone(int* zone,int sector)
{
	if (zone != nullptr && sector > 0)
	{
		delete[] this->zone;
		this->zone = new int [sector];
		for (int i = 0; i < sector; i++)
		{
			this->zone[i] = zone[i];
		}
		this->sector = sector;
	}
}

int* Locatie::getZone()
{
	if (zone != nullptr)
	{
		int* copy = new int [sector];
		for (int i = 0; i < sector; i++)
		{
			copy[i] = zone[i];
		}
		return copy;
	}
	else return nullptr;
}

int Locatie::getZone(int index)
{
	if (index >= 0 && index <= sector && zone != nullptr)
	{
		return zone[index];
	}
	else return -1;
}

int Locatie::nrSectorPerZona(string numeZona, Locatie * zone, int nrZone)
{
	int maxim = 0;
	if (zone != nullptr && nrZone > 0)
	{
		for (int i = 0; i < nrZone; i++)
		{
			maxim = maxim + zone[i].sector;
		}
	}
	return maxim;
}


bool Locatie::operator!()
{
	return sector <= 0;
}

Locatie::operator string()
{
	return numeZona;
}
string mesajInvalid = "Locul nu este valid";

ostream& operator<<(ostream& out, Locatie l)
{
	//out << "Sectorul: " << l.sector << endl;
	//out << "Locul: " << l.loc << endl;
	out << "Locatia: "<<l.numeLocatie << endl;
	out << l.numeZona << endl;
	out << endl;
	return out;
}

istream& operator>>(istream& in, Locatie& l)
{
	//cout << "Sectorul ";
	//in >> l.sector;

	cout << "Locul: ";
	in >> l.loc;

	cout << "Numele locatiei: ";
	in >> l.numeLocatie;

	in >> l.numeZona;

	if (l.zone != nullptr)
	{
		for (int i = 0; i < l.sector; i++)
		{
			delete[]l.zone;
			l.zone = nullptr;
		}
		
	}

	l.zone = new int[l.sector];
	cout << "Zone:";
	for (int i = 0; i < l.sector; i++)
	{
		in >> l.zone[i];
	}
	return in;

}