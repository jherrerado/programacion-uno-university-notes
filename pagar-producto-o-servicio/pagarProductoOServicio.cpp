#include<iostream>
#include<string>


using namespace std;

int main()
{
	int CP_S, LCP_S, PP_S, PD, EPI, ST, IP, TP;
	string NP_S;

	cout << "Digite el codigo del producto:\n";
	cin >> CP_S;

	cout << "Digite el nombre del producto o servicio:\n";
	cin >> NP_S;

	cout << "Digite el precio del producto:\n";
	cin >> PP_S;

	cout << "Cantidad que deceas:\n";
	cin >> LCP_S;
		
	cout << "Digite el descuento en porcentajes:\n";
	cin >> PD;

	cout << "Digiete el porcentaje de Itbis:\n";
	cin >> EPI;

	ST = LCP_S * PP_S;
	float DA = ST * (PD / 100.0);
	float I = (ST - DA) * (EPI / 100.0);
	TP = (ST - DA) + I;

	cout << "********************************************\n";
	cout << "Codigo: " << CP_S << "\n";
	cout << "Descripcion: " << NP_S << "\n";
	cout << "Precio: " << PP_S << "\n";
	cout << "Sub-Total: " << ST << "\n";
	cout << "Descuento Aplicado: " << DA << "\n";
	cout << "Itbis: " << I << "\n";
	cout << "Total a Pagar: " << TP << "\n";
	cout << "********************************************\n";

	return 0;
}