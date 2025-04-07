#include"header.h"



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