#include	<iostream>
#include <math.h>

int main(){
	double x, resultado;
	std::cout << "Ingrese	el valor de x: "; 
	std::cin >> x;
	resultado = sqrt(abs(pow(x, 3) - 4));
	std::cout << "El resultado de f(x) es: " << resultado << "\n";
	return 0;
}