#include"header.h"

int main() {
	Medicament* tab[80];
	int taille = 80;
	for (int i = 0; i < taille; i++) {
		tab[i] = initMedoc();
	}
	tri_a_bulles(tab, taille);
	afficher(tab, taille);
	taux_vendus(tab, taille);

	for (int i = 0; i < taille; i++) {
		free(tab[i]);
		tab[i] = NULL;
	}

	return 0;
}