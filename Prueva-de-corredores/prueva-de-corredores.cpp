#include<iostream>
#include<vector>
#include<string.h>
#include<limits>
#include<math.h>

using namespace std;

void soloAdmiteNumero(string mensaje) {
	std::cin.clear();
	std::cin.ignore(numeric_limits<int>::max(), '\n');
	std::cout << mensaje;
}

int main() {
	// declaraciones de variables
	int corredores, corredoresClasificados = 0;
	float promedioTiempos = 0;

	cout << "Corredores: ";
	while (!(cin >> corredores))
	{
		soloAdmiteNumero("Ingres valor numerico: ");
	}

	// Uso de la libreria vector 
	vector<int> tiempos(corredores);

	// Proceso
	cout << " " << endl;
	cout << "*********************************************************" << endl;
	cout << "Tiempos de los jugadore durante los 100 metros (Segundos)" << endl;
	cout << "*********************************************************" << endl;
	cout << " " << endl;

	for (int i = 0; i < corredores; i++)
	{
		cout << i + 1 << ':' << " ";
		while (!(cin >> tiempos[i]))
		{
			soloAdmiteNumero("Valor numerico (segundos): ");
		}

		if (tiempos[i] <= 10) corredoresClasificados += 1;
		promedioTiempos += tiempos[i];
	}

	if (corredoresClasificados > (corredores / 2))
	{
		cout << " " << endl;
		cout << "***********************" << endl;
		cout << "  Este grupo es bueno" << endl;
		cout << "***********************" << endl;
		cout << " " << endl;
	}

	cout << "Clasificados\tPromedio del tiempo" << endl;
	cout << corredoresClasificados << "\t\t" << round(promedioTiempos / corredores) << endl;

	return 0;
}