#ifndef TRI
#define TRI

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct {
	char nom[50];
	int code;
	int fabrication[3];
	int peremption[3];
	double prix;
	int vendus;
	int restants;
	struct Medicament* suivant;
}Medicament;

typedef struct {
	struct Medicament* premier;
}Liste;

void initMedoc(Liste* liste);
void afficher(Liste* liste);
Liste* tri(Liste* liste);
void libere(Liste* liste);

#endif