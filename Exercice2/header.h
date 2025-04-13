#ifndef TRI
#define TRI

#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char nom[50];
	char prenom[50];
	int matricule;
	double moyenne;
}Etudiant;

Etudiant* initEtud();
void affiche(Etudiant** tab, int taille);
void quicksort(Etudiant* tab[], int debut, int fin);

#endif