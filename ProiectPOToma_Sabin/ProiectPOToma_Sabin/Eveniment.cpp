#define _CRT_SECURE_NO_WARNINGS
#include "Eveniment.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
Eveniment::Eveniment() :idEveniment(idEvenimentCurent)
{
	this->idEvenimentCurent++;
	numeEveniment = nullptr;
	dataEveniment = "";
	ora = "";
}

Eveniment::Eveniment(const char* numeEveniment, string dataEveniment, string ora) :idEveniment(idEvenimentCurent)
{
	this->idEvenimentCurent++;
	this->dataEveniment = dataEveniment;
	this->ora = ora;
	if (numeEveniment != nullptr)
	{
		this->numeEveniment = new char[strlen(numeEveniment) + 1];
		strcpy_s(this->numeEveniment, strlen(numeEveniment) + 1, numeEveniment);
	}
	else
	{
		this->numeEveniment = nullptr;
	}
}
Eveniment::Eveniment(const Eveniment& e) :idEveniment(e.idEvenimentCurent)
{
	this->dataEveniment = e.dataEveniment;
	this->ora = e.ora;
	if (e.numeEveniment != nullptr)
	{
		this->numeEveniment = new char[strlen(e.numeEveniment) + 1];
		strcpy_s(this->numeEveniment, strlen(e.numeEveniment) + 1, e.numeEveniment);
	}
	else
	{
		this->numeEveniment = nullptr;
	}
}
Eveniment::~Eveniment()
{
	if (numeEveniment != nullptr)
	{
		delete[]numeEveniment;
		numeEveniment = nullptr;
	}
}
Eveniment& Eveniment::operator=(const Eveniment& e)
{
	if (this != &e)
	{
		this->dataEveniment = e.numeEveniment;
		this->ora = e.ora;
		if (e.numeEveniment != nullptr)
		{
			if (numeEveniment != nullptr)
			{
				delete[]numeEveniment;
			}
			this->numeEveniment = new char[strlen(e.numeEveniment) + 1];
			strcpy_s(this->numeEveniment, strlen(e.numeEveniment) + 1, e.numeEveniment);
		}
	}
	return *this;
}
void Eveniment::setNumeEveniment(const char* numeEveniment)
{
	if (numeEveniment != nullptr)
	{
		if (this->numeEveniment != nullptr)
		{
			delete[]this->numeEveniment;
		}
		this->numeEveniment = new char[strlen(numeEveniment) + 1];
		strcpy_s(this->numeEveniment, strlen(numeEveniment), numeEveniment);
	}
}

char* Eveniment::getNumeEveniment()
{
	if (numeEveniment != nullptr)
	{
		char* copy = new char[strlen(numeEveniment) + 1];
		strcpy_s(this->numeEveniment, strlen(numeEveniment) + 1, numeEveniment);
		return copy;
	}
	return nullptr;
}

int Eveniment::getidEvenimentCurent()
{
	return idEvenimentCurent;
}

string Eveniment::getOra()
{
	return ora;
}

string Eveniment::getDataEveniment()
{
	return dataEveniment;
}

string Eveniment::getOras()
{
	return oras;
}

bool Eveniment::operator!()
{
	if (this->oras == "Bucuresti")
		return true;
	return false;
}

char& Eveniment::operator[](int index)
{
	if (numeEveniment != nullptr && index >= 0 && index < strlen(numeEveniment))
	{
		return numeEveniment[index];
	}
	return charInvalid;
}
int Eveniment::getidEveniment()
{
	return idEveniment;
}

string Eveniment::getNumeEvenimentAsString()
{
	string copie = numeEveniment;
	return copie;
}


ostream& operator<<(ostream& out, Eveniment e)
{
	if (e.numeEveniment != nullptr)
	{
		out << "Nume evenimentului: " <<e.numeEveniment<< endl;
	}
	out << "Data Evenimentului: " << e.dataEveniment << endl;
	out << "Ora Evenimentului: " << e.ora<<endl;
	out << "IDul Evenimentului: " << e.idEveniment<<endl;
	
	return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Data Evenimentului: ";
	in >> e.dataEveniment;

	cout << "Ora Evenimentului: ";
	in >> e.ora;

	cout << "Nume Evenimentului: ";
	string buffer;
	in >> buffer;
	e.setNumeEveniment(buffer.c_str());
	return in;
}

string Eveniment::oras = "Bucuresti";
int Eveniment::idEvenimentCurent = 0;
char Eveniment::charInvalid = -1;