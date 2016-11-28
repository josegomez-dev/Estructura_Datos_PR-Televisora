// ESTRCUCT.PR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()

static ListaAnuncios * lstAnuncios = new ListaAnuncios();
static ListaCanales * lstCanales = new ListaCanales();

int main()
{
	bool noSalir = true;
	int opc;

	do {
		mostrarMenu();
		opc = leerOpcion();
		noSalir = ejecutarAccion(opc);
	} while (noSalir);
	
	system("pause");
    return 0;
}

void mostrarMenu(void) {

	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	cout << endl;
	cout << " __________________________________________________________ " << endl;
	cout << "  -------------------- PRINCIPAL MENU -------------------- " << endl;
	cout << "                                                          " << endl;
	cout << "   1. Crear Anuncio        |    7. Crear Contrato         " << endl;
	cout << "   2. Consultar Anuncio    |    8. Consultar Contrato     " << endl;
	cout << "   3. Eliminar Anuncio     |    9. Eliminar Contrato      " << endl;
	cout << "   4. Crear Canal          |    10. Desplegar Informacion " << endl;
	cout << "   5. Consultar Canal      |    11. Salir                 " << endl;
	cout << "   6. Elminar Canal        |		                       " << endl;
	cout << " ___________________________________________________________ " << endl;
	
	SetConsoleTextAttribute(console, FOREGROUND_GREEN );
}

int leerOpcion(void) {
	int opc;
	cout << "\nElije una opcion: "; cin >> opc;	cout << endl;
	return opc;
}

bool ejecutarAccion(int opc) {
	SetConsoleTextAttribute(console, FOREGROUND_INTENSITY);
	bool noSalir = true;

//	if (opc >= 2 && opc <= 7) {
//		return noSalir;
//	}
	
	switch (opc) {
		case 1: // Crear Anuncio
			
			lstAnuncios->addItemASC(crearAnuncio());
			
			cout << "\n*/!*/!*/! Anuncio creado exitosamente !/*!/*!/*\n" << endl;
			
			break;
		case 2: // Consultar Anuncio

			NodoAnuncio * c_nodo;
			unsigned long cod;

			cout << "Ingrese el codigo del anuncio que desea buscar: "; cin >> cod;
			c_nodo = lstAnuncios->retrieveItem(cod);

			if (c_nodo != nullptr) {
				cout << c_nodo->toString();
			}
			else {
				cout << "\n*/!*/!*/! Anuncio no encontrado !/*!/*!/* \n" << endl;
			}
			
			break;
		case 3: // Eliminar Anuncio
			
			NodoAnuncio * e_nodo;
			unsigned long codigo;

			cout << "Ingrese el codigo del anuncio que desea eliminar"; cin >> codigo;

			e_nodo = lstAnuncios->retrieveItem(codigo);
			
			if (e_nodo != nullptr) {
				lstAnuncios->deleteItem(e_nodo);
				cout << "\n */!*/!*/! Anuncio eliminado exitosamente !/*!/*!/* \n";
			}
			else {
				cout << "\n */!*/!*/! Anuncio no encontrado !/*!/*!/* \n";
			}

			break;

		case 4: // Crear Canal

			lstCanales->addItem(crearCanal());
			
			cout << "Canal registrado exitosamente" << endl;

			break;
		case 5: // Consultar Canal
			break;
		case 6: // Eliminar Canal
			break;

		case 7: // Crear Contrato
			try
			{
				lstAnuncios->addItemASC(crearAnuncio());
			}
			catch (const std::exception& ex)
			{
				cout << "EXCEPCION" << endl;
			}
			break;
		case 8: // Consultar Contrato
			break;
		case 9: // Eliminar Contrato
			break;
		case 10: // Desplegar informacion

			SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN);
			
			cout << "____________________________________________________" << endl;
			cout << "\n *** LISTA DE ANUNCIOS REGISTRADOS *** \n" << endl;
			cout << lstAnuncios->toString() << endl;
			cout << "____________________________________________________" << endl;

			cout << "____________________________________________________" << endl; 
			cout << "\n *** LISTA DE CANALES REGISTRADOS *** \n" << endl;
			cout << lstCanales->toString_StartToEnd() << endl;
			cout << "____________________________________________________" << endl;
			
			SetConsoleTextAttribute(console, FOREGROUND_INTENSITY);
			break;

		case 11: // Salir
			noSalir = false;
			break;
		default: // Opcion Invalida
			cout << "\n */!*/! Opcion Invalida !/*!/* \n" << endl;
			break;
	}

	SetConsoleTextAttribute(console, FOREGROUND_INTENSITY);
	return noSalir;
}

NodoAnuncio *& crearAnuncio(void) {
	NodoAnuncio * anuncio = new NodoAnuncio();
	string n; unsigned int c; int t;

	cout << "Ingrese el nombre de la empresa: "; cin >> n;
	cout << "Ingrese el codigo de la empresa: "; cin >> c;
	cout << "Ingrese el tiempo de duracion del anuncio (seg): "; cin >> t;
	
	anuncio->setNombreEmpresa(n); anuncio->setCodigoEmpresa(c); anuncio->setTiempoDuracion(t);
	
	return anuncio;
}

NodoCanal *& crearCanal(void) {
	NodoCanal * canal = new NodoCanal();
	unsigned int c; string n; string t; double m; unsigned int ttmin; unsigned int ttmax; double cm;

	cout << "Ingrese el codigo del canal: "; cin >> c;
	cout << "Ingrese el nombre del canal: "; cin >> n;
	cout << "Ingrese el telefono del canal: "; cin >> t;
	cout << "Ingrese el monto minimo del canal ($): "; cin >> m;
	cout << "Ingrese el tiempo de transmicion minima (seg): "; cin >> ttmin;
	cout << "Ingrese el tiempo de transmicion maxima (seg): "; cin >> ttmax;
	cout << "Ingrese el costo por minuto del canal ($): "; cin >> cm;

	canal->setCodigoCanal(c);
	canal->setNombreCanal(n);
	canal->setTelefono(t);
	canal->setMontoMinimo(m);
	canal->setTTransmicionMinima(ttmin);
	canal->setTTransmicionMaxima(ttmax);
	canal->setCostoPorMinuto(cm);
	
	return canal;
}