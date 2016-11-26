#ifndef LISTACANALES_H
#define LISTACANALES_H

#include "Canal.h"
#include "NodoCanal.h"

class ListaCanales
{
private: 
	int longitud;

	NodoCanal * cabeza;
	NodoCanal * ultimo;
public:
	ListaCanales(void);
	
	int getlongitud(void) const;
	void setLongitud(int l);

	NodoCanal * getCabeza(void) const;
	void setCabeza(NodoCanal * cabeza);

	NodoCanal * getUltimo(void) const;
	void setUltimo(NodoCanal * ultimo);

	void addItem(Canal *&);
	string toString_StartToEnd(void);
	string toString_EndToStart(void);

};

#endif // !LISTACANALES_H
