#ifndef TRI
#define TRI

#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char nom[50];
	int code;
	int fabrication[3];
	int peremption[3];
	int prix;
}Medicament;

void swap(Medicament** tab, int j);
void tri_a_bulles(Medicament** tab, int taille);

#endif