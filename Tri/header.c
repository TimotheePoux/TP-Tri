#include"header.h"

Medicament* initMedoc() {
	Medicament* newMedoc = malloc(sizeof(Medicament));
	printf("-----NOUVEAU MEDICAMENT-----\nNom: ");
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
	printf("Prix: ");
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

void afficher(Medicament** tab, int taille){
	for (int i = 0; i < taille; i++) {
		printf("%s -- %d -- %d/%d/%d -- %d/%d/%d -- %.2f\n", tab[i]->nom, tab[i]->code, tab[i]->fabrication[0], tab[i]->fabrication[1], tab[i]->fabrication[2], tab[i]->peremption[0], tab[i]->peremption[1], tab[i]->peremption[2], tab[i]->prix);
	}
}

void recherche_dicho(Medicament** tab, int taille) {
	int debut = 0;
	int fin = taille - 1;
	int trouve = 0;
	char atrouver[50] = "";
	scanf_s("%s", atrouver, 50);
	getchar();
	int peremption[3] = { 0,0,0 };
	printf("Date de Peremption:\n     Annee: ");
	scanf_s("%d", &(peremption[2]));
	printf("     Mois: ");
	scanf_s("%d", &(peremption[1]));
	printf("     Jour: ");
	scanf_s("%d", &(peremption[0]));
		int mil = (debut+fin)/2;
		if (strcmp(tab[mil]->nom, atrouver) == 0) {
			trouve = 1;
		}
		else if ((peremption[2] > tab[mil]->peremption[2]) || (peremption[2] == tab[mil]->peremption[2] && peremption[1] > tab[mil]->peremption[1]) || (peremption[2] == tab[mil]->peremption[2] && peremption[1] == tab[mil]->peremption[1] && peremption[0] > tab[mil]->peremption[0])) {
			debut = mil + 1;
		}
		else {
			fin = mil - 1;
		}
	if (trouve) {
		printf("La valeur %s est au rang %d", atrouver, mil);
	}
	else {
		printf("La valeur %s n'est pas dans le tableau", atrouver);
	}
}