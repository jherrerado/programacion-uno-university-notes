#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Medio
{
	private:

		// Atributos
		string tipo;
		int inventarioId;
		double costoUnitario;
		string estado;
		string proveedorUsual;

	public:
		// contructures
		Medio(string tipo, int inventarioId, double costoUnitario, string estado, string proveedorUsual)
		{
			this->tipo = tipo;
			this->inventarioId = inventarioId;
			this->costoUnitario = costoUnitario;
			this->estado = estado;
			this->proveedorUsual = proveedorUsual;
		}

		// getters
		string getTipo() { return tipo; }
		int getInventarioID() { return inventarioId; }
		double getCostoUnitario() { return costoUnitario; }
		string getEstado() { return estado; }
		string getProveedorUsual() { return proveedorUsual; }

		// setters
		void setTipo(string tp) { tipo = tp; }
		void setInventarioID(int inID) { inventarioId = inID; }
		void setCostoUnitario(double costoUni) { costoUnitario = costoUni; }
		void setEstado(string estado) { estado = estado; }
		void setProveedorUsual(string provUsual) { proveedorUsual = provUsual; }

		// metodos
		virtual double calcularCosto() { return 0.0; }
};

class EquipoElectrico : public Medio
{
	private: 
		string marca;
		vector<string> otrosProveedores;
		int garantiaEnMeses;

	public: 
		// constructor
		EquipoElectrico(string tipo, int inventarioId, double costoUnitario, string estado, string proveedorUsual, string marca, vector<string> otrosProveedores, int garantiaEnMeses):
			Medio(tipo, inventarioId, costoUnitario, estado, proveedorUsual)
		{
			this->marca = marca;
			this->otrosProveedores = otrosProveedores;
			this->garantiaEnMeses = garantiaEnMeses;
		}

		// getters
		string getMarca() { return marca; }
		vector<string> getOtrosProveedores() { return otrosProveedores; }
		int getGarantiaEnMeses() { return garantiaEnMeses; }

		// setters
		void setMarca(string mrc) { marca =	mrc; }
		void setOtrosProveedores(vector<string> otrProv) { otrosProveedores = otrProv; }
		int setGarantiaEnMeses(int garem) { garantiaEnMeses = garem; }

		// Metodos
		double calcularCosto() override 
		{
			double costo = getCostoUnitario() * getGarantiaEnMeses();
			return costo;
		}
};

class Mobiliarios : public Medio
{
	private:
		float tiempoEstimadoPorMeses;
		string local;

	public:

		// constructor
		Mobiliarios(string tipo, int inventarioId, double costoUnitario, string estado, string proveedorUsual, float tiempoEstimadoPorMeses, string local) :
			Medio(tipo, inventarioId, costoUnitario, estado, proveedorUsual)
		{
			this->tiempoEstimadoPorMeses = tiempoEstimadoPorMeses;
			this->local = local;
		}

		// getters
		float getTiempoEstimado() { return tiempoEstimadoPorMeses; }
		string getLocal() { return local; }

		// setters
		void setTiempoEstimado(float tiemEst) { tiempoEstimadoPorMeses = tiemEst; }
		void setLocal(string l) { local = l; }

		// Metodos
		double calcularCosto() override
		{
			double costo = 0.0;
			if (getLocal() == "aula" || getLocal() == "AULA")
			{
				costo = 250.00 + (getCostoUnitario() * getTiempoEstimado());
			}
			else if (getLocal() == "laboratorio" || getLocal() == "LABORATORIO")
			{
				costo = 320.00 + (getCostoUnitario() * getTiempoEstimado());
			}
			else if (getLocal() == "departamento" || getLocal() == "DEPARTAMENTO")
			{
				costo = 450.00 + (getCostoUnitario() * getTiempoEstimado());
			}
			else if (getLocal() == "oficina" || getLocal() == "OFICINA")
			{
				costo = 500.00 + (getCostoUnitario() * getTiempoEstimado());
			}
			else
			{
				cout << "El nombre del local debe estar escrito en mayusculas o en minuscula" << "\n";
			}
			return costo;
		}
};

class HardSoft
{
public:
	HardSoft() {}

	int cantidadEquiposMismoTipo(vector<EquipoElectrico>& equipos, string tipo)
	{
		int cantidad = 0;
		for (auto& equipo : equipos)
		{
			if (equipo.getTipo() == tipo)
			{
				cantidad++;
			}
		}
		return cantidad;
	}

	int cantidadTotalMedios(vector<EquipoElectrico>& equipos, vector<Mobiliarios> mobiliarios)
	{
		int cantidad = 0;
		for (auto& equipo : equipos) { cantidad++; }
		for (auto& mobiliario : mobiliarios) { cantidad++; }
		return cantidad;
	}

	EquipoElectrico* mayorGarantia(vector<EquipoElectrico>& equipos)
	{
		int mayor = equipos[0].getGarantiaEnMeses();
		EquipoElectrico* mayorEquipo{};
		for (auto& equipo : equipos)
		{
			if (equipo.getGarantiaEnMeses() > mayor) 
			{ 
				mayor = equipo.getGarantiaEnMeses(); 
				mayorEquipo = &equipo;
			}
		}
		return mayorEquipo;
	}

	EquipoElectrico* menorGarantia(vector<EquipoElectrico>& equipos)
	{
		int mayor = equipos[0].getGarantiaEnMeses();
		EquipoElectrico* menorEquipo{};
		for (auto& equipo : equipos)
		{
			if (equipo.getGarantiaEnMeses() < mayor)
			{
				mayor = equipo.getGarantiaEnMeses();
				menorEquipo = &equipo;
			}
		}
		return menorEquipo;
	}

	double costoTotalEquipos(vector<EquipoElectrico>& equipos)
	{
		double sumaTotal = 0.0;
		for (auto& equipo : equipos)
		{
			sumaTotal += equipo.getCostoUnitario();
		}
		return sumaTotal;
	}

	double costoTotalMobiliario(vector<Mobiliarios>& mobiliarios)
	{
		double sumaTotal = 0.0;
		for (auto& mobiliario : mobiliarios)
		{
			sumaTotal += mobiliario.getCostoUnitario();
		}
		return sumaTotal;
	}

	double costoPromedioEquipos(vector<EquipoElectrico>& equipos)
	{
		double sumaTotal = 0.0;
		for (auto& equipo : equipos)
		{
			sumaTotal += equipo.getCostoUnitario();
		}
		return (sumaTotal / equipos.size());
	}

	double costoPromedioMobiliario(vector<Mobiliarios>& mobiliarios)
	{
		double sumaTotal = 0.0;
		for (auto& mobiliario : mobiliarios)
		{
			sumaTotal += mobiliario.getCostoUnitario();
		}
		cout << mobiliarios.size() << endl;
		return (sumaTotal / mobiliarios.size());
	}
};

int main()
{
	EquipoElectrico teclado("entrada", 59435, 600, "nuevo", "sirena", "lenovo", {}, 8);
	EquipoElectrico mause("entrada", 56985, 200, "nuevo", "sirena", "lenovo", {}, 5);
	EquipoElectrico pantalla("salida", 29655, 5000, "nuevo", "sirena", "lenovo", {}, 24);

	Mobiliarios mesa("mesa", 89587, 7000, "nuevo", "Tony", 32, "Av. Los Rieles");
	Mobiliarios silla("silla", 88987, 1000, "nuevo", "Tony", 32, "Av. Los Rieles");
	Mobiliarios sofa("sofa", 89543, 9000, "nuevo", "Tony", 32, "Av. Los Rieles");

	vector<EquipoElectrico> equipos = { teclado, mause, pantalla };
	vector<Mobiliarios> mobiliarios = {mesa, silla, sofa};

	HardSoft* inventario = new HardSoft();

	cout << "suma total de los equipos: " << inventario->costoTotalEquipos(equipos) << endl;
	cout << "suma total de los muebles: " << inventario->costoTotalMobiliario(mobiliarios) << endl;
	cout << "suma promedio de los equipos: " << inventario->costoPromedioEquipos(equipos) << endl;
	cout << "suma promedio de los muebles: " << inventario->costoPromedioMobiliario(mobiliarios) << endl;



	
	return 0;
}