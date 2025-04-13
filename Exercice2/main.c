#include"header.h"

int main() {
	Etudiant* tab[100];
	int taille = 4;
	for (int i = 0; i < taille; i++) {
		tab[i] = initEtud();
	}
	affiche(tab, taille);
	quicksort(tab, 0, taille-1);
	affiche(tab, taille);

	for (int i = 0; i < taille; i++) {
		free(tab[i]);
		tab[i] = NULL;
	}
	
	return 0;
}