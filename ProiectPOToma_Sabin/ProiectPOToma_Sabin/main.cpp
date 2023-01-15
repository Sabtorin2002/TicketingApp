#define _CRT_SECURE_NO_WARNINGS
#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
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

template<typename T>
istream& operator>>(istream& in, vector<T>& vec)
{
	vec.clear();
	int n;
	cout << "Introduceti numarul de elemente: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		T var;
		cin >> var;
		vec.push_back(var);
	}
	return in;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec)
{
	out << '[';
	for (auto& var : vec)
	{
		out << var << " ; ";
	}
	out << ']';
}

class BiletVIP :public IoBase
{
protected:
	float pretVIP;
	string nume;
	int varsta;
	int cod;
	string tipZona;
	string serie;
	unsigned int id;
	int tip;
	string sex;
	int anulnasterii;
	int lunanasterii;
	int ziuanasterii;
	static unsigned int idCurent;
public:
	BiletVIP() : id(++idCurent) {}
	
	BiletVIP(float pretVIP, const string& nume, int varsta, int cod, string tipZona,
		const string& serie,int tip, string sex, int anulnasterii,
		int lunanasterii, int ziuanasterii, unsigned int id) : pretVIP(pretVIP), nume(nume), varsta(varsta),
											cod(cod), tipZona(tipZona), serie(serie),tip(tip),sex(sex), 
											anulnasterii(anulnasterii), lunanasterii(lunanasterii),
											ziuanasterii(ziuanasterii),id(++idCurent) {}
	
	istream& read(istream& in) override
	{
		IoBase::read(in);
		cout << "Numele dumneavoastra: ";
		in >> nume;
		cout << "Varsta dumneavoastra: ";
		in >> varsta;
		cout << "Zona in care doriti sa stati: ";
		in >> tipZona;
		cout << "Introduceti codul evenimentului: ";
		in >> cod;
		cout << "Introduceti tipul de bilet pe care doriti sa-l achizitionati: ";
		in >> tip;
		cout << "Sexul dumneavoastra: ";
		in >> sex;
		cout << "Introduceti anul nasterii: ";
		in >> anulnasterii;
		cout << "Introuceti luna nasterii: ";
		in >> lunanasterii;
		cout << "Introduceti ziua nasterii: ";
		in >> ziuanasterii;

		return in;
	}
	
	ostream& write(ostream& out) const override
	{
		IoBase::write(out);
		cout << "Pret: ";
		out << pretVIP << endl;
		cout << "Nume: ";
		out << nume<<endl;
		cout << "Varsta: ";
		out << varsta << endl;
		cout << "Zona: ";
		out << tipZona << endl;
		cout << "Codul evenimentului: ";
		out << cod << endl;
		cout << "Seria: ";
		out << serie<<endl;
		cout << "Tip: ";
		out << tip << endl;
		cout << "ID: ";
		out << id<<endl;
		cout << "Sex:";
		out << sex << endl;
		cout << "Data nasterii: ";
		out << ziuanasterii << ".0" << lunanasterii << "." << anulnasterii << endl;

		return out;
	}

	virtual float calculatorPretVIP() {
		return 0;
	}
	virtual string generareSerie() {
		return 0;
	}

	float getPretVIP()const
	{
		return pretVIP;
	}
	const string& getSerie() const
	{
		return serie;
	}
	int getCod()const
	{
		return cod;
	}
	unsigned int getID()const
	{
		return id;
	}
	int getTip() const
	{
		return tip;
	}
	virtual void serialize() {}
};

unsigned int BiletVIP::idCurent = 0;

class BiletVIPMeciFotbal : public BiletVIP
{
private:
	int nrloc;
public:
	BiletVIPMeciFotbal(){}
	BiletVIPMeciFotbal (float pretVIP, const string& nume, int varsta, int cod, string tipZona,
		const string& serie,int tip, string sex, int anulnasterii,
		int lunanasterii, int ziuanasterii, unsigned int id,int nrloc) : BiletVIP(pretVIP, nume, varsta, cod, tipZona,
												serie,tip,sex,anulnasterii,lunanasterii,ziuanasterii, id), nrloc(nrloc) {}
	
	istream& read(istream& in) override
	{
		BiletVIP::read(in);
		cout << "Introduceti numarul locului: ";
		in >> nrloc;
		return in;

	}
	ostream& write(ostream& out) const override
	{
		BiletVIP::write(out);
		cout << "Numarul locului: ";
		out << nrloc;
		return out;
	}

	float calculatorPretVIP() override
	{
		if (tipZona == "Peluza")
			pretVIP = 10;
		else if (tipZona == "Tribuna2")
			pretVIP = 30;
		else if (tipZona == "Tribuna1")
			pretVIP = 50;
		else if (tipZona == "Loja")
			pretVIP = 150;
		else if (tipZona == "LojaVIP")
			pretVIP = 400;
		return pretVIP;
	}

	string generareSerie() override
	{
		string sbv = to_string(this->id);
		string ann = to_string(this->anulnasterii);
		string ln = to_string(this->lunanasterii);
		string zn = to_string(this->ziuanasterii);
		string sir1 = "M";
		string sir2="F";		
		if (sex == sir1)

		{
			if (tip == 1 && tipZona == "LojaVIP")
				serie = "<Premium><Acces5>-<"+sbv + ann + ln + zn + ">";
			else serie = "<General><Acces5>-<"+ sbv + ann + ln + zn + ">";
		}
		else if (sex == sir2)
		{
			if (tip == 1 && tipZona == "LojaVIP")
				serie = "<Premium><Acces6>-<"+ sbv + ann + ln + zn + ">";
			else serie = "<General><Acces6>-<"+ sbv + ann + ln + zn + ">";
		}
		return serie;
	}

	void serialize() override
	{
		ofstream f("BiletVIPMeciFotbal.bin", ios::binary | ios::app);
		f.write((char*)&pretVIP, sizeof(pretVIP));

		short dim1 = this->nume.length();
		f.write((char*)&dim1, sizeof(dim1));
		f.write(nume.c_str(), dim1 + 1);

		f.write((char*)&varsta, sizeof(varsta));
		f.write((char*)&cod, sizeof(cod));

		short dim2 = this->tipZona.length();
		f.write((char*)&dim2, sizeof(dim2));
		f.write(tipZona.c_str(), dim2 + 1);

		short dim3 = this->serie.length();
		f.write((char*)&dim3, sizeof(dim3));
		f.write(serie.c_str(), dim3 + 1);

		f.write((char*)&tip, sizeof(tip));

		short dim4 = this->sex.length();
		f.write((char*)&dim4, sizeof(dim4));
		f.write((sex.c_str()), dim4 + 1);

		f.write((char*)&anulnasterii, sizeof(anulnasterii));
		f.write((char*)&lunanasterii, sizeof(lunanasterii));
		f.write((char*)&ziuanasterii, sizeof(ziuanasterii));
		f.write((char*)&id, sizeof(id));
		f.write((char*)&nrloc, sizeof(nrloc));

		f.close();

	}
};

class BiletVIPTeatru :public BiletVIP
{
private:
	int nrloc;
public:
	BiletVIPTeatru() {}
	BiletVIPTeatru(float pretVIP, const string& nume, int varsta, int cod, string tipZona,
		const string& serie, int tip, string sex, int anulnasterii,
		int lunanasterii, int ziuanasterii, unsigned int id, int nrloc) : BiletVIP(pretVIP, nume, varsta, cod, tipZona,
			serie, tip, sex, anulnasterii, lunanasterii, ziuanasterii, id), nrloc(nrloc) {}
	
	istream& read(istream& in) override
	{
		BiletVIP::read(in);
		cout << "Introduceti numarul locului: ";
		in >> nrloc;
		return in;

	}
	ostream& write(ostream& out) const override
	{
		BiletVIP::write(out);
		cout << "Numarul locului: ";
		out << nrloc;
		return out;
	}

	float calculatorPretVIP() override
	{
		if (tipZona == "Loja")
			pretVIP = 120;
		else pretVIP = 50;
		
		return pretVIP;
	}

	string generareSerie() override
	{
		string sbv = to_string(this->id);
		string ann = to_string(this->anulnasterii);
		string ln = to_string(this->lunanasterii);
		string zn = to_string(this->ziuanasterii);
		string sir1 = "M";
		string sir2 = "F";
		if (sex == sir1)

		{
			if (tip == 1 && tipZona == "LojaVIP")
				serie = "<Premium><Acces5>-<"+ sbv + ann + ln + zn + ">";
			else serie = "<General><Acces5>-<"+ sbv + ann + ln + zn + ">";
		}
		else if (sex == sir2)
		{
			if (tip == 1 && tipZona == "LojaVIP")
				serie = "<Premium><Acces6>-<" + sbv + ann + ln + zn + ">";
			else serie = "<General><Acces6>-<" + sbv + ann + ln + zn + ">";
		}
		return serie;
	}

	void serialize() override
	{
		ofstream f("BiletVIPTeatru.bin", ios::binary | ios::app);
		f.write((char*)&pretVIP, sizeof(pretVIP));

		short dim1 = this->nume.length();
		f.write((char*)&dim1, sizeof(dim1));
		f.write(nume.c_str(), dim1 + 1);

		f.write((char*)&varsta, sizeof(varsta));
		f.write((char*)&cod, sizeof(cod));

		short dim2 = this->tipZona.length();
		f.write((char*)&dim2, sizeof(dim2));
		f.write(tipZona.c_str(), dim2 + 1);

		short dim3 = this->serie.length();
		f.write((char*)&dim3, sizeof(dim3));
		f.write(serie.c_str(), dim3 + 1);

		f.write((char*)&tip, sizeof(tip));

		short dim4 = this->sex.length();
		f.write((char*)&dim4, sizeof(dim4));
		f.write((sex.c_str()), dim4 + 1);

		f.write((char*)&anulnasterii, sizeof(anulnasterii));
		f.write((char*)&lunanasterii, sizeof(lunanasterii));
		f.write((char*)&ziuanasterii, sizeof(ziuanasterii));
		f.write((char*)&id, sizeof(id));
		f.write((char*)&nrloc, sizeof(nrloc));

		f.close();

	}
};

class BiletVIPFilm : public BiletVIP
{
private:
	int nrloc;
public:
	BiletVIPFilm() {}
	BiletVIPFilm(float pretVIP, const string& nume, int varsta, int cod, string tipZona,
		const string& serie, int tip, string sex, int anulnasterii,
		int lunanasterii, int ziuanasterii, unsigned int id, int nrloc) : BiletVIP(pretVIP, nume, varsta, cod, tipZona,
			serie, tip, sex, anulnasterii, lunanasterii, ziuanasterii, id), nrloc(nrloc) {}

	istream& read(istream& in) override
	{
		BiletVIP::read(in);
		cout << "Introduceti numarul locului: ";
		in >> nrloc;
		return in;
	}
	ostream& write(ostream& out) const override
	{
		BiletVIP::write(out);
		cout << "Numarul locului: ";
		out << nrloc;
		return out;
	}

	float calculatorPretVIP() override
	{
		if (tipZona == "Cinema")
		{
			pretVIP = 28;
			if (varsta < 18)
				pretVIP = 19;
		}
		return pretVIP;
	}

	string generareSerie() override
	{
		string sbv = to_string(this->id);
		string ann = to_string(this->anulnasterii);
		string ln = to_string(this->lunanasterii);
		string zn = to_string(this->ziuanasterii);
		string sir1 = "M";
		string sir2 = "F";
		if (sex == sir1)

		{
			if (tip == 1 && tipZona == "LojaVIP")
				serie = "<Premium><Acces5>-<"  + sbv + ann + ln + zn + ">";
			else serie = "<General><Acces5>-<" + sbv + ann + ln + zn + ">";
		}
		else if (sex == sir2)
		{
			if (tip == 1 && tipZona == "LojaVIP")
				serie = "<Premium><Acces6>-<" + sbv + ann + ln + zn + ">";
			else serie = "<General><Acces6>-<" + sbv + ann + ln + zn + ">";
		}
		return serie;
	}

	void serialize() override
	{
		ofstream f("BiletVIPFilm.bin", ios::binary | ios::app);
		f.write((char*)&pretVIP, sizeof(pretVIP));

		short dim1 = this->nume.length();
		f.write((char*)&dim1, sizeof(dim1));
		f.write(nume.c_str(), dim1 + 1);

		f.write((char*)&varsta, sizeof(varsta));
		f.write((char*)&cod, sizeof(cod));

		short dim2 = this->tipZona.length();
		f.write((char*)&dim2, sizeof(dim2));
		f.write(tipZona.c_str(), dim2 + 1);

		short dim3 = this->serie.length();
		f.write((char*)&dim3, sizeof(dim3));
		f.write(serie.c_str(), dim3 + 1);

		f.write((char*)&tip, sizeof(tip));

		short dim4 = this->sex.length();
		f.write((char*)&dim4, sizeof(dim4));
		f.write((sex.c_str()), dim4 + 1);

		f.write((char*)&anulnasterii, sizeof(anulnasterii));
		f.write((char*)&lunanasterii, sizeof(lunanasterii));
		f.write((char*)&ziuanasterii, sizeof(ziuanasterii));
		f.write((char*)&id, sizeof(id));
		f.write((char*)&nrloc, sizeof(nrloc));

		f.close();
	}
};

shared_ptr<BiletVIP> citireBilet()
{
	int ev;
	cout << "1.Fotbal\n2.Teatru\n3.Film\n";
	cout << endl;
	cin >> ev; 
	shared_ptr<BiletVIP> bv;
	if (ev == 1)
	{
		bv = make_shared < BiletVIPMeciFotbal > ();
	}
	else if (ev == 2) 
	{
		bv = make_shared < BiletVIPTeatru > ();
	}
	else if (ev == 3)
	{
		bv = make_shared<BiletVIPFilm>();
	}
	else
	{
		cout << "Categorie gresita! ";
		return nullptr;
	}
	cin >> *bv;
	bv->generareSerie();
	bv->calculatorPretVIP();
	bv->serialize();
	
	return bv;

}

class Meniu
{
private:
	vector<shared_ptr<BiletVIP>>bilete;
public:
	void showOptions()
	{
		cout << "Alege o optiune"<<endl;
		cout << "1.Adaugare bilet "<< endl;
		cout << "2.Afisare bilete" << endl;
		cout << "3.Afisare bilete dupa codul evenimentului" << endl;
		cout << "4.Stergere bilet dupa serie" << endl;
	}
	void run()
	{
		showOptions();
		int option;
		cin >> option;
		while (0 < option && option < 5)
		{
			if (option == 1)
				citire();
			else if (option == 2)
				afisare();
			else if (option == 3)
				afisareCod();
			else if (option == 4)
				stergere();
			else {
				cout << "Programul s-a incheiat!";
				break;
			}
				showOptions();
				cin >> option;	
		}
	}
	void citire()
	{
		bilete.push_back(citireBilet());
	}

	void afisare()
	{
		for (int i = 0; i < bilete.size(); i++)
			cout << *bilete[i] << endl;
	}

	void afisareCod()
	{
		int cod;
		cout << "Introduceti cod: ";
		cin >> cod;
		for (int i = 0; i < bilete.size(); i++)
		{
			if (bilete[i]->getCod() == cod)
			{
				cout << *bilete[i] << endl;
			}
		}
	}

	void stergere()
	{
		string serie;
		cout << "Introduceti seria: ";
		cin >> serie;
		for (auto it = bilete.begin(); it != bilete.end(); it++)
		{
			if (it->get()->getSerie() == serie)
			{
				bilete.erase(it, it + 1);
				break;
			}
		}
	}
};

int main()
{
	//Locatie l1;
	int v1[]{ 120,121,122,123,124 };
	int v2[]{ 1,2 };
	int v3[]{ 1 };
	Locatie l2(v1,5,29,"Stadion Otelul Galati","Tribuna 0");;
	cout << l2 << endl;
	//Locatie l3(l2);
	//Locatie l4 = l2;
	Locatie l5(v2, 2, 57, "Teatrul Dramatic", "Sala Spectacol");
	cout << l5 << endl;
	Locatie l6(v3, 1, 15, "Cinema City", "Sala 4");
	cout << l6 << endl;
	

	Eveniment e1;
	Eveniment e2("Matchday 15:Otelul Galati-Politehnica Timisoara", "3 Septembrie", "11:00");
	cout << e2 << endl;
	Eveniment e3("Piesa de teatru:Take, Ianke si Cadir", "15 Noiembrie", "20:00");
	cout << e3 << endl;
	Eveniment e4("Interstellar", "20 August", "22:40");
	cout << e4 << endl;
	
	Bilet b1;
	Bilet b2(20, "Toma Sabin", "Strada Anghel Saligny", 20);
	cout << b2<<endl;
	Bilet b3(50, "Popescu Ion", "Strada Domneasca", 32);
	cout << b3 << endl;
	Bilet b4(28, "Ionescu Pop", "Strada George Cosbuc", 27);
	cout << b4 << endl;

	ofstream f1("fisier1Evenimente.txt");
	f1 << e2<<endl << e3 <<endl<< e4;

	ofstream f2("fisier2.Bilete.txt");
	f2 << b2 <<endl<< b3 <<endl<< b4;

	ofstream f3("fisier3Locatii.txt");
	f3 << l2 << endl << l5 << endl << l6;
	
	Meniu meniu;
	meniu.run();
	return 0;
}
