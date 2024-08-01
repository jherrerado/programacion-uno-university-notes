/*Esta es la libreria de esntada y salida*/
#include<iostream>

/*namespace encapsula codigo para evitar repeticion de funciones con igual nombre.
con la palabra clave using se puede indicar que se esta utilizando de antemano, dicho
de otro modo no se necesita el hola:: */
namespace hola 
{
	void f()
	{
		std::cout << "hola\n";
	}
}

using namespace std;
void f()
{
	cout << "adios\n";
}


int main() 
{
	hola::f();
	f();

	/*Esta funcion no permite que se termine el proceso hasta que el usuario
	lo indique*/
	getchar();
	return 0;
}