#ifndef LISTACANALES_H
#define LISTACANALES_H

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
	void setLongitud(int);

	NodoCanal *& getCabeza(void);
	void setCabeza(NodoCanal *);

	NodoCanal *& getUltimo(void);
	void setUltimo(NodoCanal *);

	void addItem(NodoCanal *);

	string toString_StartToEnd(void);
	string toString_EndToStart(void);
	
};

#endif // !LISTACANALES_H
