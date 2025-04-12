#include"header.h"

void initMedoc(Liste* liste) {
	Medicament* newMedoc = malloc(sizeof(Medicament));
	if (newMedoc == NULL) {
		return;
	}
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
	printf("Unites vendues:");
	scanf_s("%d", &(newMedoc->vendus));
	printf("Unites restants en stock: ");
	scanf_s("%d", &(newMedoc->restants));
	newMedoc->suivant = liste->premier;
	liste->premier = newMedoc;
}

void afficher(Liste* liste) {
	printf("-----AFFICHAGE-----\n");
	Medicament* medicament = liste->premier;
	while (medicament != NULL) {
		printf("%s -- %d -- %d/%d/%d -- %d/%d/%d -- %.2f -- %d -- %d\n", medicament->nom, medicament->code, medicament->fabrication[0], medicament->fabrication[1], medicament->fabrication[2], medicament->peremption[0], medicament->peremption[1], medicament->peremption[2], medicament->prix, medicament->vendus, medicament->restants);
		medicament = medicament->suivant;
	}
}

int greater(Liste* liste) {
	Medicament* medicament = liste->premier;
	int greatercode = medicament->code;
	while (medicament != NULL) {
		if (greatercode < medicament->code) {
			greatercode = medicament->code;
		}
		medicament = medicament->suivant;
	}
	return greatercode;
}

Liste* tri(Liste* liste) {
	Liste* newListe = malloc(sizeof(Liste));
	newListe->premier = NULL;
	while (liste->premier != NULL) {
		int greatercode = greater(liste);
		Medicament* medicament = liste->premier;
		while (1) {
			if (medicament->code == greatercode) {
				if (medicament == liste->premier) {
					liste->premier = medicament->suivant;
				}
				else {
					Medicament* post = medicament->suivant;
					Medicament* pre = liste->premier;
					while (pre->suivant != medicament) {
						pre = pre->suivant;
					}
					pre->suivant = post;
				}
				medicament->suivant = newListe->premier;
				newListe->premier = medicament;
				break;
			}
			medicament = medicament->suivant;
		}
	}
	free(liste);
	liste = NULL;
	return newListe;
}

void libere(Liste* liste) {
	while (liste->premier != NULL) {
		Medicament* temp = liste->premier;
		liste->premier = temp->suivant;
		free(temp);
		temp = NULL;
	}
}
