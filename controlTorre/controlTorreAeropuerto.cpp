#include <iostream>
#include <string.h>
using namespace std;

class Aeronave
{
private:
	string matricula;
	double capacidad;
	int kmRecorridos;
	int tipoAeronave;
	double impuesto;
public:
	Aeronave();
	Aeronave(string matricula, double capacidad, int kmRecorridos, int tipoaeronave, double impuesto);

	// getters
	string getMatricula();
	double getCapacidad();
	int getKmRecorridos();
	int getTipoAeronave();

	// setters
	void setMatricula(string m);
	void setCapacidad(double c);
	void setKmRecorridos(int k);
	void setTipoAeronave(int ti);

	// polimofismo
	virtual double getImpuesto();
	virtual void mostrarDatosAereonave();

};

class Pasajero : public Aeronave
{
private:
	int cantPrimera, cantTuristica;
public: 
	Pasajero();
	Pasajero(string matricula, double capacidad, int kmRecorridos, int tipoAeronave, double impuesto, int cantPrimera, int cantTuristica);

	// getters
	int getCantPrimera();
	int getCantTuristica();

	// setters
	void setCantPrimera(int cantP);
	void setCantTuristica(int cantT);

	// polimofismo
	void mostrarDatosAereonave() override;
	double getImpuesto() override;
};

class Jet : public Aeronave
{
private:
	string firma;
	double precio;
public:
	Jet();
	Jet(string matricula, double capacidad, int kmRecorridos, int tipoAeronave, double impuesto, string firma, double precio);

	//getters
	string getFirma();
	double getPrecio();

	// setters
	void setFirma(string fir);
	void getPrecio(double pre);

	// polimofismo
	void mostrarDatosAereonave() override;
	double getImpuesto() override;
};

class Torre
{
private:
	int cantReal;
	Aeronave** aeronaves;

public:
	Torre();
	~Torre();

	// Getters
	int getCantReal();
	void getDatosAeronaves();

	// Setters
	void setAeronaves(Aeronave* aero);
	
	// Metodos
	string matriculaAvionMayorImpuesto();
	int cantidadJetsVolandoEspacioAereo();

};

// Inicializando las clases

Aeronave::Aeronave()
{}

Aeronave::Aeronave(string matricula, double capacidad, int kmRecorridos, int tipoAeronave, double impuesto)
{
	this->matricula = matricula;
	this->capacidad = capacidad;
	this->kmRecorridos = kmRecorridos;
	this->tipoAeronave = tipoAeronave;
	this->impuesto = impuesto;
}

// getters
string Aeronave::getMatricula() { return matricula; }
double Aeronave::getCapacidad() { return capacidad; }
int Aeronave::getKmRecorridos() { return kmRecorridos; }
int Aeronave::getTipoAeronave() { return impuesto; }
double Aeronave::getImpuesto() { return impuesto; }

// setters
void Aeronave::setMatricula(string m) { matricula = m; }
void Aeronave::setCapacidad(double c) { capacidad = c; }
void Aeronave::setKmRecorridos(int k) { kmRecorridos = k; }
void Aeronave::setTipoAeronave(int ti) { impuesto = ti; }


void Aeronave::mostrarDatosAereonave()
{
	cout << "Matrícula: " << this->getMatricula() << '\t' << "Capacidad: " << this->getCapacidad() << 
		'\t' << "KmRecorridos: "<<this->getKmRecorridos()<<endl;
}


// Pasajero


Pasajero::Pasajero()
{
}

Pasajero::Pasajero(string matricula, double capacidad, int kmRecorridos, int tipoAeronave, double impuesto, int cantPrimera, int cantTuristica) :
	Aeronave(matricula, capacidad, kmRecorridos, tipoAeronave, impuesto)
{
	this->cantPrimera = cantPrimera;
	this->cantTuristica = cantTuristica;
}

// getters
int Pasajero::getCantPrimera() { return cantPrimera; }
int Pasajero::getCantTuristica() { return cantTuristica; }

// setters
void Pasajero::setCantPrimera(int cantP) { Pasajero::cantPrimera = cantP; }
void Pasajero::setCantTuristica(int cantT) { cantTuristica = cantT; }

// polimofismo

void Pasajero::mostrarDatosAereonave()
{
	cout << "Matrícula: " << this->getMatricula() << '\t' << "Capacidad: " << this->getCapacidad() << '\t' << "KmsRecorridos: "<<
		this->getKmRecorridos()<<'\t'<<"1er Clase : "<<this->getCantPrimera()<<'\t'<<"ClaseTurista : "<<this->getCantTuristica()<<endl;
		cout << "Impuesto espacio aéreo: " << (this->getCapacidad() * (this->getCantPrimera() + this ->getCantTuristica())) * this->getKmRecorridos() << "DOP" << endl;
}

double Pasajero::getImpuesto()
{
	double impues;
	int ca = getCapacidad();
	int pPC = getCantPrimera();
	int pCT = getCantTuristica();
	int kmr = getKmRecorridos();
	impues = (ca * (pPC + pCT)) * kmr;

	return impues;
}

Jet::Jet()
{}

Jet::Jet(string matricula, double capacidad, int kmRecorridos, int tipoAeronave, double impuesto, string firma, double precio) :
	Aeronave(matricula, capacidad, kmRecorridos, tipoAeronave, impuesto)
{
	this->firma = firma;
	this->precio = precio;
}
// getters

string Jet::getFirma() { return firma; }
double Jet::getPrecio() { return precio; }

// setters
void Jet::setFirma(string fir) { firma = fir; }
void Jet::getPrecio(double pre) { precio = pre; }

// polimorfismo
void Jet::mostrarDatosAereonave()
{
	cout << "Matrícula: " << this->getMatricula() << '\t' << "Capacidad: " << this->getCapacidad() << '\t' << "KmsRecorridos: "<<
		this->getKmRecorridos()<<'\t'<<"Firma : "<<this->getFirma()<<'\t'<<"Precio : "<<this-> getPrecio() << endl; 
	cout << "Impuesto espacio aéreo: " << (this->getCapacidad() * this -> getPrecio()) / getKmRecorridos() << "DOP" << endl;
}

double Jet::getImpuesto()
{
	return (getCapacidad() * getPrecio()) / getKmRecorridos();
}


Torre::Torre()
{
	cantReal = 0;
	aeronaves = new Aeronave * [100];
}

// Destructural arreglo

Torre::~Torre()
{
	for (int i = 0; i < cantReal; i++)
	{
		delete aeronaves[i];
		delete[]aeronaves;
	}
}

// getters
int Torre::getCantReal()
{ return 0; }

void Torre::getDatosAeronaves()
{
	cout << "**********************************************************************************************"<<endl;
		cout << "***********************************" << "CONTROL DE VUELOS"<<" **********************************"<<endl;
		cout << "**********************************************************************************************"<<endl;

		for (int i = 0; i < cantReal; i++)
		{
			cout << "Datos de la Aeronave" << i + 1 << endl;
			if (aeronaves[i]->getTipoAeronave() == 1)
			{
				cout << "Aeronave de pasajero" << endl;
				aeronaves[i]->mostrarDatosAereonave();
			}
			else
			{
				cout << "Aeronave Jet" << endl;
				aeronaves[i]->mostrarDatosAereonave();
			}
		}
}

// setters

void Torre::setAeronaves(Aeronave* aero)
{
	aeronaves[cantReal] = aero;
	cantReal++;
}

// metodos
string Torre::matriculaAvionMayorImpuesto()
{
	double mayor_impuesto;
	string mat_aer;
	mayor_impuesto = 0;
	for (int i = 0; i < cantReal; i++)
	{
		if (aeronaves[i]->getImpuesto() > mayor_impuesto)
		{
			mayor_impuesto = aeronaves[i]->getImpuesto();

		}
		mat_aer = aeronaves[i]->getMatricula();
	}
	return mat_aer;
}

int Torre::cantidadJetsVolandoEspacioAereo()
{
	int cant_jets_vol = 0;
	for (int i = 0; i < cantReal; i++)
	{
		if (aeronaves[i]->getTipoAeronave() == 2) cant_jets_vol++;
	}
	return cant_jets_vol;
}


int main()
{
	string ma;
	double ca;
	int kmr;
	int tip;
	int imp;
	int cantAeronaves = 0;
	int i = 0;

	//Datos Aeronave de Pasajeros
	int cP;
	int cT;

	//Datos Aeronave Jets
	string fir;
	double pre;
	Aeronave* aernuevo;

	//Entrar datos de la Aeronave
	cout << "Cantidad de aeronaves dentro del corredor aéreo: ";
	cin >> cantAeronaves;
	Torre* to = new Torre();
	do
	{
		cout << "Datos de la Aeronave: " << i + 1 << endl;
		cout << "Matrícula: ";
		cin >> ma;
		cout << "Capacidad: ";
		cin >> ca;
		cout << "Kilómetros: ";
		cin >> kmr;
		cout << "Tipo Aeronave: ";
		cin >> tip;
		if (tip == 1)
		{
			Pasajero* p = new Pasajero();
			cout << "Cantidad Pasajeros en Primera Clase: ";
			cin >> cP;
			cout << "Cantidad Pasajeros en Clase Turista: ";
			cin >> cT;
			imp = p->getImpuesto();
			aernuevo = new Pasajero(ma, ca, kmr, tip, imp, cP, cT);
		}
		else
		{
			Jet* j = new Jet();
			cout << "Firma del Jet: ";
			cin >> fir;
			cout << "Precio del Jet: ";
			cin >> pre;
			imp = j->getImpuesto();
			aernuevo = new Jet(ma, ca, kmr, tip, imp, fir, pre);
		}
		to->setAeronaves(aernuevo);
		cantAeronaves--;
		i++;
	} while (cantAeronaves != 0);

	to->getDatosAeronaves();

	cout << "Matrícula del avión que pagará un mayor impuesto por la utilización del espacio aéreo: " << to -> matriculaAvionMayorImpuesto() << endl;
	cout << "Cantidad de Jets que están sobrevolando el espacio aéreo: " << to -> cantidadJetsVolandoEspacioAereo();

	return 0;
}