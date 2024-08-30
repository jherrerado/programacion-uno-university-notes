#include	<iostream>
#include <math.h>
#include <limits>
int main(){
	double x, resultado;
	std::cout << "Ingrese	el valor de x: ";
	while (! (std::cin >> x))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Entrada invalida. Por favor, ingrese un numero: ";
	}
	resultado = sqrt(abs(pow(x, 3) - 4));
	std::cout << "El resultado de f(x) es: " << resultado << "\n";
	return 0;
}