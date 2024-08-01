#include <iostream>

using namespace std;

int main()
{
	int N1, N2;
	char opt;
	do
	{
		cout << "Ingresar primer numero:\n"; 
		cin >> N1;
		cout << "Ingresar el segundo numero:\n";
		cin >> N2;

		// Realizar operaciones
		int S = N1 + N2;
		int R = N1 - N2;
		int M = N1 * N2;
		int D = N1 / N2;

		// Mostrar en pantalla las operacion

		/* \n es la forma de realizar el salto de linea
		y esta tiene que ser obligatoria para que la presentacion
		sea clara */

		cout << "***************************\n";
		cout << "   TODAS LAS OPERACIONES\n";
		cout << "***************************\n";
		cout << "La Suma es: " << S << "\n";
		cout << "La Resta es: " << R << "\n";
		cout << "La Multiplicacion es: " << M << "\n";
		cout << "La Division es: " << D << "\n";
		cout << "\n";
		cout << "deceas reiniciar marcar (Y) si no (N)\n";
		cin >> opt;
		cout << "\n";
	} while (opt == 'Y' || opt == 'y');
	cout << "***************************\n";
	cout << "La operacion finalizo\n";
	cout << "***************************\n";
	cout << "\n";

	return 0;
}