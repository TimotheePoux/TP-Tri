#include"header.h"

Etudiant* initEtud() {
    Etudiant* newEtud = malloc(sizeof(Etudiant));
    printf("-----NOUVEL ETUDIANT-----\nNom: ");
    scanf_s("%s", newEtud->nom, 50);
    getchar();
    printf("Prenom: ");
    scanf_s("%s", newEtud->prenom, 50);
    getchar();
    printf("Matricule: ");
    scanf_s("%d", &(newEtud->matricule));
    printf("Moyenne: ");
    scanf_s("%lf", &(newEtud->moyenne));
    return newEtud;
}

void affiche(Etudiant** tab, int taille) {
    printf("------AFFICHAGE------\n");
    for (int i = 0; i < taille; i++) {
        printf("%s %s: Matricule: %d - Moyenne: %.2lf\n", tab[i]->prenom, tab[i]->nom, tab[i]->matricule, tab[i]->moyenne);
    }
}

void echanger(Etudiant **a, Etudiant **b) {
    Etudiant *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Etudiant *tab[], int premier, int dernier) {
    double pivot = tab[dernier]->moyenne;
    int i = premier - 1;

    for (int j = premier; j <= dernier; j++) {
        if (tab[j]->moyenne < pivot) {
            i++;
            echanger(&tab[i], &tab[j]);
        }
    }
    echanger(&tab[i + 1], &tab[dernier]);
    return i + 1;
}

void quicksort(Etudiant *tab[], int premier, int dernier) {
    if (premier < dernier) {
        int pi = partition(tab, premier, dernier);
        quicksort(tab, premier, pi - 1);
        quicksort(tab, pi + 1, dernier);
    }
}