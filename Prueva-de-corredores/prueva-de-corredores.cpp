#include<iostream>
#include<vector>

using namespace std;

int main() {
	// declaraciones de variables
	int corredores, corredoresClasificados = 0;
	float promedioTiempos = 0;

	cout << "Corredores: ";
	cin >> corredores;

	// Uso de la libreria vector 
	vector<int> tiempos(corredores);

	// Proceso
	cout << " " << endl;
	cout << "**********************************************" << endl;
	cout << "Tiempos de los jugadore durante los 100 metros" << endl;
	cout << "**********************************************" << endl;
	cout << " " << endl;

	for (int i = 0; i < corredores; i++)
	{
		cout << i + 1 << ':' << " ";
		cin >> tiempos[i];
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
	cout << corredoresClasificados << "\t\t" << (promedioTiempos / corredores) << endl;

	return 0;
}