#include<iostream>
using namespace std;

int main()
{
	float SB, AFP, ARS, ISR, TD, SN;

	//Dato de entrada
	cout << "Sueldo base:\n";
	cin >> SB;

	//Proceso
	AFP = SB * 0.0291;
	ARS = SB * 0.0304;

	if (SB > 33384)
	{
		ISR = (SB - 33384) * 0.15;
	}
	else
	{
		ISR = 0;
	}

	TD = AFP + ARS + ISR;
	SN = SB - TD;

	// Imprimir la salida del algoritmo
	cout << "\n";
	cout << "********************************************\n";
	cout << "El sueldo base es: " << SB << "\n";
	cout << "El descuento de AFP es: " << AFP << "\n";
	cout << "El descuento de ARS es: " << ARS << "\n";
	cout << "El descuento de ISR es: " << ISR << "\n";
	cout << "El total de descuento: " << TD << "\n";
	cout << "El sueldo neto es: " << SN << "\n";
	cout << "********************************************\n";
	return 0;
}