#define _CRT_SECURE_NO_WARNINGS
#include "Bilet.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Bilet::Bilet() :idBilet(idBiletCurent)
{
	this -> idBiletCurent++;
	nume = "";
	varsta = 0;
	tipZona = nullptr;
	pret = 0;
}

Bilet::Bilet(float pret, string nume, const char* tipZona, int varsta) :idBilet(idBiletCurent)
{
	this->idBiletCurent++;
	this->pret = pret;
	this->varsta = varsta;
	this->nume = nume;
	if (tipZona != nullptr)
	{
		this->tipZona = new char[strlen(tipZona) + 1];
		strcpy_s(this->tipZona, strlen(tipZona) + 1, tipZona);
	}
	else
	{
		this->tipZona = nullptr;
	}
}
Bilet::Bilet(const Bilet & b) :idBilet(b.idBiletCurent)
{
	this->pret = b.pret;
	this->nume = b.nume;
	this->varsta = b.varsta;
	if (b.tipZona != nullptr)
	{
		this->tipZona = new char[strlen(b.tipZona) + 1];
		strcpy_s(this->tipZona, strlen(b.tipZona) + 1, b.tipZona);
	}
	else
	{
		this->tipZona = nullptr;
	}
}
Bilet::~Bilet()
{
	if (tipZona != nullptr)
	{
		delete[] this->tipZona;
		tipZona = nullptr;
	}
}
Bilet& Bilet::operator=(const Bilet & b)
{
	if (this != &b)
	{
		if (b.tipZona != nullptr)
		{
			if (tipZona != nullptr)
			{
				delete[] tipZona;
			}
			this->tipZona = new char[strlen(b.tipZona) + 1];
			strcpy_s(this->tipZona, strlen(b.tipZona) + 1, b.tipZona);
		}
		this->pret = b.pret;
		this->nume = b.nume;
		this->varsta = b.varsta;
	}
	return *this;
}
void Bilet::settipZona(const char* tipZona)
{
	if (tipZona != nullptr)
	{
		if (this->tipZona != nullptr)
		{
			delete[] tipZona;
		}
	}
	this->tipZona = new char[strlen(tipZona) + 1];
	strcpy_s(this->tipZona, strlen(tipZona) + 1, tipZona);
}

char* Bilet::gettipZona()
{
	if (tipZona != nullptr)
	{
		char* copy = new char[strlen(tipZona) + 1];
		strcpy_s(this->tipZona, strlen(tipZona) + 1, tipZona);
		return copy;
	}
	return nullptr;
}


void Bilet::setNume(string nume)
{
	this->nume = nume;
}

string Bilet::getNume()
{
	return nume;
}

void Bilet::setVarsta(int varsta)
{
	this->varsta = varsta;
}

int Bilet::getVarsta()
{
	return varsta;
}

int Bilet::getIdBilet() const
{
	return idBilet;
}


float Bilet::getPret() const
{
	return pret;
}

float Bilet::profitBilete(float pret, int nrbilete, char* tipZona)
{
	float sumaprofit = 0;
	if (pret > 0 && nrbilete > 0)
		sumaprofit = pret * nrbilete;
	return sumaprofit;
}

float Bilet::discountBilete(float pret, int procent, int varsta)
{
	if (varsta < 18)
		pret = pret - pret / procent;
	return pret;
}

float Bilet::pretBilet(float pret)
{
	pret=(int)pret;
	return pret;
}

void Bilet::operator+=(float valoare)
{
	this->pret += valoare;
}

int Bilet::idBiletCurent = 0;

ostream& operator<<(ostream& out, Bilet b)
{
	out << "IDul biletului: " << b.idBilet << endl;
	out << "Numele persoanei: " << b.nume << endl;
	out << "Varsta persoanei: " << b.varsta << endl;
	out << "Pretul: " << b.pret << endl;
	out << "Zona: ";
	if (b.tipZona != nullptr)
	{
		out << b.tipZona;
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Bilet& b)
{
	cout << "Numele persoane: ";
	in >> b.nume;

	cout << "Varsta persoanei: ";
	in >> b.varsta;

	cout << "Pret:";
	in >> b.pret;

	cout << "Zona:";
	string buffer;
	in >> buffer;
	b.settipZona(buffer.c_str());

	return in;
}