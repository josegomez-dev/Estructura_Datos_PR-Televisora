// ESTRCUCT.PR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()

static ListaCanales * lstCanales = new ListaCanales();

int main()
{
	lstCanales->setLstAnuncios(new ListaAnuncios());
	bool noSalir = true;
	int opc;

	do {
		mostrarMenu();
		opc = leerOpcion();
		noSalir = ejecutarAccion(opc);
	} while (noSalir);
	
	system("pause");
	cin.get();
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
	cout << "   6. Elminar Canal        |	 12. TEST				   " << endl;
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
			
			lstCanales->getLstAnuncios()->addItemASC(crearAnuncio());
			
			cout << "\n*/!*/!*/! Anuncio creado exitosamente !/*!/*!/*\n" << endl;
			
			break;
		case 2: // Consultar Anuncio

			NodoAnuncio * c_nodo;
			unsigned long cod;

			cout << "Ingrese el codigo del anuncio que desea buscar: "; cin >> cod;
			c_nodo = lstCanales->getLstAnuncios()->retrieveItem(cod);

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

			e_nodo = lstCanales->getLstAnuncios()->retrieveItem(codigo);
			
			if (e_nodo != nullptr) {
				lstCanales->getLstAnuncios()->deleteItem(e_nodo);
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

			unsigned int asdcod;

			cout << "Ingrese el codigo del canal: "; cin >> asdcod;
			
			NodoCanal * asd;
			asd = lstCanales->retrieveItem(asdcod);
			cout << ((asd != NULL ) ? asd->getNombreCanal() : "No encontrado") << endl;


			break;
		case 6: // Eliminar Canal
			break;

		case 7: // Crear Contrato
			
			crearContrato();

			break;
		case 8: // Consultar Contrato
			break;
		case 9: // Eliminar Contrato
			break;
		case 10: // Desplegar informacion

			desplegarInformacionListas();
			
			break;

		case 11: // Salir
			noSalir = false;
			break;
		case 12: // TEST
			fillBaseData();
			cout << "\n SE REGISTRARON DATOS BASE \n" << endl;
			break;
		default: // Opcion Invalida
			cout << "\n */!*/! Opcion Invalida !/*!/* \n" << endl;
			break;
	}

	SetConsoleTextAttribute(console, FOREGROUND_INTENSITY);
	return noSalir;
}

void crearContrato(void) {

	unsigned long codigoAn;	cout << "Ingrese el codigo del anuncio: "; cin >> codigoAn;
	unsigned int codigoC; cout << "Ingrese el codigo del canal: "; cin >> codigoC;

	lstCanales->incluirContrato(codigoAn, codigoC, lstCanales->getLstAnuncios());
}

NodoAnuncio *& crearAnuncio(void) {

	string n; unsigned int c; int t;

	cout << "Ingrese el codigo de la empresa: "; cin >> c;
	cout << "Ingrese el nombre de la empresa: "; cin >> n;
	cout << "Ingrese el tiempo de duracion del anuncio (seg): "; cin >> t;
	
	NodoAnuncio * anuncio = new NodoAnuncio(c, n);

	anuncio->setNombreEmpresa(n); anuncio->setCodigoEmpresa(c); anuncio->setTiempoDuracion(t);
	
	return anuncio;
}

NodoCanal *& crearCanal(void) {
	
	unsigned int c; string n; string t; double m; unsigned int ttmin; unsigned int ttmax; double cm;

	cout << "Ingrese el codigo del canal: "; cin >> c;
	cout << "Ingrese el nombre del canal: "; cin >> n;
	cout << "Ingrese el telefono del canal: "; cin >> t;
	cout << "Ingrese el monto minimo del canal ($): "; cin >> m;
	cout << "Ingrese el tiempo de transmicion minima (seg): "; cin >> ttmin;
	cout << "Ingrese el tiempo de transmicion maxima (seg): "; cin >> ttmax;
	cout << "Ingrese el costo por minuto del canal ($): "; cin >> cm;

	NodoCanal * canal = new NodoCanal(c);
	canal->setNombreCanal(n);
	canal->setTelefono(t);
	canal->setMontoMinimo(m);
	canal->setTTransmicionMinima(ttmin);
	canal->setTTransmicionMaxima(ttmax);
	canal->setCostoPorMinuto(cm);
	
	return canal;
}

void desplegarInformacionListas(void) {
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << "\n *** SUPER LISTA *** \n" << endl;
	cout << lstCanales->toString_Super() << endl;
	cout << "____________________________________________________" << endl;
	SetConsoleTextAttribute(console, FOREGROUND_INTENSITY);
}

void fillBaseData() {
	NodoCanal * warner = new NodoCanal(35); warner->setNombreCanal("WARNER");
	NodoCanal * mtv = new NodoCanal(30); mtv->setNombreCanal("MTV");
	NodoCanal * acme = new NodoCanal(4); acme->setNombreCanal("ACME");
	NodoCanal * teletica = new NodoCanal(7); teletica->setNombreCanal("TELETICA");

	lstCanales->addItem(warner); lstCanales->addItem(mtv); lstCanales->addItem(acme);

	NodoAnuncio * a1 = new NodoAnuncio(1, "FRIENDS");
	NodoAnuncio * a2 = new NodoAnuncio(2, "WEEDS");
	NodoAnuncio * a3 = new NodoAnuncio(3, "CORRECAMINOS");

	lstCanales->getLstAnuncios()->addItemASC(a1); lstCanales->getLstAnuncios()->addItemASC(a2); lstCanales->getLstAnuncios()->addItemASC(a3);

	NodoAnuncioContratado * c1 = new NodoAnuncioContratado(1);
	NodoAnuncioContratado * c2 = new NodoAnuncioContratado(2);
	NodoAnuncioContratado * c3 = new NodoAnuncioContratado(3);

	lstCanales->incluirContrato(1, 30, lstCanales->getLstAnuncios());
	lstCanales->incluirContrato(2, 30, lstCanales->getLstAnuncios());
	lstCanales->incluirContrato(3, 4, lstCanales->getLstAnuncios());
}