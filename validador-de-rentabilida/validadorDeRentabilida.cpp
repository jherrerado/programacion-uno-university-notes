#include<iostream>
#include<cmath>
#include<string.h>

int main()
{
	// Declaracciones de variables
	double CMP, CSC, TG, CGD, TI, PG, PZIE, PZVIP, PZG, CSCR;
	double GP, GE, GL, GS, GAS, PGD, APZVIP, APZIE;
	std::string R = "", D = "";
	std::cout << "													\n";
	std::cout << "****************************************************\n";
	std::cout << "*******    Bienvenido al validador de eventos   ****\n";
	std::cout << "****************************************************\n";

	// Proceso del programa
	std::cout << "Digite la cantidad minima de personas que asistiran al evento:\n";
	std::cin >> CMP;
	CSC = CMP / 3.0;

	// Cantidad de sillas por categoria
	if (fmod(CSC, 1) == 0)
	{
		CSCR = 0;
	}
	else
	{
		CSC = round(CSC);
		CSCR = fmod(CMP, 3.0);
	}
	std::cout << "													\n";
	std::cout << "****************************************************\n";
	std::cout << "*******     Digite los gastos previstos *************\n";
	std::cout << "****************************************************\n";


	std::cout << "Digite los gastos de la Publicidad:\n";
	std::cin >> GP;

	std::cout << "Degite los gastos de la Escenografia:\n";
	std::cin >> GE;

	std::cout << "Digite los gastos en las Luces\n";
	std::cin >> GL;

	std::cout << "Digite los gastos del Staff:\n";
	std::cin >> GS;

	std::cout << "Digite los gastos del Alquiler de las Sillas:\n";
	std::cin >> GAS;

	float GB;
	std::cout << "Digite los gastos de la Banda:\n";
	std::cin >> GB;

	// Total de los gastos
	TG = GP + GE + GL + GS + GAS + GB;

	std::cout << "													\n";
	std::cout << "****************************************************\n";
	std::cout << "*******     Precios deceados ***********************\n";
	std::cout << "****************************************************\n";

	std::cout << "Digite el porcentaje de ganancia que deceas (Recomendamos que esta sea mayor a 30%):\n";
	std::cin >> PGD;

	std::cout << "Con respecto al precio general (El mas economico) indica que tanto lo quieres multiplicar para genera el precio de la zona VIP:\n";
	std::cin >> APZVIP;

	std::cout << "Con respecto al precio general (El mas economico) indica que tanto lo quieres multiplicar para genera el precio de la zona Invitado Especial:\n";
	std::cin >> APZIE;

	// CGD es la cantidad de ganancias disponible
	// PGD es la porcentage de las ganancias disponible
	CGD = TG * (PGD / 100.0);

	// Ti es la cantidad de Ingresos, sin pagar los gastos
	TI = TG + CGD;

	// Este algoritmo determina a cuanto se puede cobrar cada silla, separandola por grupos
	// PG es el precio general
	PG = TI / ((CSC + CSCR) + CSC * APZVIP + CSC * APZIE);

	// PZIE Precio de la zona invitado especial
	// PZVip Precio de la zona VIP
	// PZG Precio de la zona general
	PZIE = APZIE * PG;
	PZVIP = APZVIP * PG;
	PZG = PG;

	std::cout << "													\n";
	std::cout << "****************************************************\n";
	std::cout << "Precio de la zona Invitado Especial: RD$" << round(PZIE) << "\n";
	std::cout << "Precio de la zona VIP: RD$" << round(PZVIP) << "\n";
	std::cout << "Precio de la zona General: RD$" << round(PZG) << "\n";
	std::cout << "****************************************************\n";

	// D es Disposicion de pago por parte de los usuarios
	std::cout << "Crees que los precios son alcanzable para el usuraio, si tu respuesta es si colocal una (y) si no coloca una (n)\n";
	std::cin >> D;

	// R es la rentabilidad de dicho concierto
	R = "ES RENTABLE";

	if (PGD < 30 && (D == "n" || D == "N"))
	{
		R = "NO ES RENTABLE, PORQUE VAS A GANAR MENOS DEL 30% Y EL USUARIO NO PODRA COMPRARLO\n";
	}
	else if (D == "n" || D == "N")
	{
		R = "NO ES RENTABLE, PORQUE EL USUARIO NO VA A PODER COMPRAR LAS VOLETAS\n";
	}

	std::cout << "													\n";
	std::cout << "****************************************************\n";
	std::cout << "                     " << R << "\n";
	std::cout << "****************************************************\n";
	std::cout << "Precio de la zona Invitado Especial (" << CSC << " sillas): RD$" << round(PZIE) << "\n";
	std::cout << "Precio de la zona VIP (" << CSC << " sillas): RD$" << round(PZVIP) << "\n";
	std::cout << "Precio de la zona General (" << (CSC + CSCR) << " sillas) : RD$" << round(PZG) << "\n";
	std::cout << "****************************************************\n";
	std::cout << "Ingresos: RD$" << round(TI) << "\n";
	std::cout << "Ganancias: RD$" << round(CGD) << "\n";
	std::cout << "Total de gastos: RD$" << round(TG) << "\n";
	std::cout << "****************************************************\n";
	std::cout << "Gastos en las Publicidad: RD$" << GP << "\n";
	std::cout << "Gastos en las Escenografia: RD$" << GE << "\n";
	std::cout << "Gastos en las Luces: RD$" << GL << "\n";
	std::cout << "Gastos en las Staff: RD$" << GS << "\n";
	std::cout << "Gastos en los alquileres de las sillas: RD$" << GAS << "\n";
	std::cout << "Gastos en las Banda: RD$" << GB << "\n";

	return 0;

}