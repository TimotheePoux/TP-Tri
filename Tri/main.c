#include"header.h"

int main() {
	Medicament* tab[80];
	int taille = 2;
	for (int i = 0; i < taille; i++) {
		tab[i] = initMedoc();
	}
	tri_a_bulles(tab, taille);
	afficher(tab, taille);

	return 0;
}