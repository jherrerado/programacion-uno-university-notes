#include<iostream>
using namespace std;

int main()
{
	int POE, PF, AP, VA, PEF;

	// Recopilacion de datos
	cout << "Produccion oral y escrita (0 - 10)\n";
	cin >> POE;

	cout << "Proyecto final (0 - 15)\n";
	cin >> PF;

	cout << "Actividades practicas (0 - 20)\n";
	cin >> AP;

	cout << "Valores y actitudes (0 - 5)\n";
	cin >> VA;

	cout << "Prueva de evaluacion final (0 - 50)\n";
	cin >> PEF;

	// operacio o procesamiento
	int NF = POE + PF + AP + VA + PEF;

	// Presentacion de la informacion
	if (NF > 100)
	{
		cout << "*************************\n";
		cout << NF << "\n";
		cout << "Hay un error en el calulo\n";
		cout << "*************************\n";
	}
	else if (NF >= 90)
	{
		cout << "*************************\n";
		cout << NF << "\n";
		cout << "A\n";
		cout << "Aprobado\n";
		cout << "*************************\n";
	}
	else if (NF >= 80)
	{
		cout << "*************************\n";
		cout << NF << "\n";
		cout << "B\n";
		cout << "Aprobado\n";
		cout << "*************************\n";
	}
	else if (NF >= 70)
	{
		cout << "*************************\n";
		cout << NF << "\n";
		cout << "C\n";
		cout << "Aprobado\n";
		cout << "*************************\n";
	}
	else
	{
		cout << "*************************\n";
		cout << NF << "\n";
		cout << "F\n";
		cout << "Reprobado\n";
		cout << "*************************\n";
	}

	return 0;
}