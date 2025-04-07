#include"header.h"

Medicament* initMedoc() {
	Medicament* newMedoc = malloc(sizeof(Medicament));
	printf("Nom: ");
	scanf_s("%s", newMedoc->nom, 50);
	getchar();
	printf("Code-medicament: ");
	scanf_s("%d", &(newMedoc->code));
	printf("Date de fabrication:\n     Annee: ");
	scanf_s("%d", &(newMedoc->fabrication[2]));
	printf("     Mois: ");
	scanf_s("%d", &(newMedoc->fabrication[1]));
	printf("     Jour: ");
	scanf_s("%d", &(newMedoc->fabrication[0]));
	printf("Date de Peremption:\n     Annee: ");
	scanf_s("%d", &(newMedoc->peremption[2]));
	printf("     Mois: ");
	scanf_s("%d", &(newMedoc->peremption[1]));
	printf("     Jour: ");
	scanf_s("%d", &(newMedoc->peremption[0]));
	printf("Code-medicament: ");
	scanf_s("%lf", &(newMedoc->prix));
	return newMedoc;
}

void swap(Medicament** tab, int j) {
	Medicament* temp = tab[j];
	tab[j] = tab[j + 1];
	tab[j + 1] = temp;
}

void tri_a_bulles(Medicament** tab, int taille) {
	int trie = 1;
	for (int i = taille - 1; i >= 1; i--) {
		trie = 1;
		for (int j = 0; j < i; j++) {
			if ((tab[j]->peremption[2] > tab[j + 1]->peremption[2]) || (tab[j]->peremption[2] == tab[j + 1]->peremption[2] && tab[j]->peremption[1] > tab[j + 1]->peremption[1]) || (tab[j]->peremption[2] == tab[j + 1]->peremption[2] && tab[j]->peremption[1] == tab[j + 1]->peremption[1] && tab[j]->peremption[0] > tab[j + 1]->peremption[0])) {
				swap(tab, j);
				trie = 0;
			}
		}
		if (trie) {
			return;
		}
	}
}