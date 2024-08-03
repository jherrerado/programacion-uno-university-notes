#include<iostream>
using namespace std;
int main()
{
	// Declaracion de Variables
	float HT, PHT, HE, PHE, SB, AFP, ARS, ISR, TD, SN;

	// Dato de entrada
	cout << "Ingrese la cantidad de horas trabajadas:\n";
	cin >> HT;

	cout << "Ingrese el pago por horas trabajadas:\n";
	cin >> PHT;

	cout << "Ingrese la cantidad de horas extas:\n";
	cin >> HE;

	cout << "Ingrese el pago de horas extras:\n";
	cin >> PHE;

	// Procesos
	SB = (HT * PHT) + (HE * PHE);
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
	cout << "El sueldo base es: " << SB << "\n";
	cout << "El descuento de AFP es: " << AFP << "\n";
	cout << "El descuento de ARS es: " << ARS << "\n";
	cout << "El descuento de ISR es: " << ISR << "\n";
	cout << "El Total de Descuento: " << TD << "\n";
	cout << "El Sueldo Neto es: " << SN << "\n";
	return 0;
}