#ifndef LISTACANALES_H
#define LISTACANALES_H

#include "NodoCanal.h"
#include "ListaAnuncios.h"

class ListaCanales
{
private:
	int longitud;

	NodoCanal * cabeza;
	NodoCanal * ultimo;

	ListaAnuncios *lstAnuncios;
public:
	ListaCanales(void);

	int getlongitud(void) const;
	void setLongitud(int);

	NodoCanal *& getCabeza(void);
	void setCabeza(NodoCanal *);

	NodoCanal *& getUltimo(void);
	void setUltimo(NodoCanal *);

	ListaAnuncios *& getLstAnuncios(void);
	void setLstAnuncios(ListaAnuncios *);

	void addItem(NodoCanal *);
	NodoCanal * retrieveItem(unsigned int);
	NodoAnuncio * retrieveAnuncio(unsigned long);
	bool incluirContrato(unsigned long, unsigned int);
	ListaCanales * actualizarCobros();

	string toString_StartToEnd(void);
	string toString_EndToStart(void);

	string toString_Super(void);
	
};

#endif // !LISTACANALES_H
