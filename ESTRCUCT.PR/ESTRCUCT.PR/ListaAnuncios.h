#ifndef LISTAANUNCIOS_H
#define LISTAANUNCIOS_H

#include "stdafx.h"
#include "NodoAnuncio.h"


class ListaAnuncios
{
private: 
	NodoAnuncio * cabeza;
	int longitud;

public:
	ListaAnuncios(void);

	NodoAnuncio* getCabeza(void);
	void setCabeza(NodoAnuncio *);

	int getlongitud(void) const;
	void setLongitud(int l);

	void addItem(NodoAnuncio *);
	void addItemASC(NodoAnuncio *);
	int searchItem(NodoAnuncio *);
	NodoAnuncio * retrieveItem(unsigned long);
	bool deleteItem(NodoAnuncio *);

	string toString(void);

};

#endif // LISTAANUNCIOS_H