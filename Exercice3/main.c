#include<stdio.h>
#include<stdlib.h>

int* merge(int* uno, int tuno, int* dos, int tdos) {
	int i = 0;
	int j = 0;
	int* newTab = malloc(sizeof(int) * (tuno+tdos));
	for (int k = 0; k < (tuno + tdos) -1; k++) {
		if (uno[i] < dos[j]) {
			newTab[k] = uno[i];
			i++;
		}
		else {
			newTab[k] = dos[j];
			j++;
		}
	}
	if (uno[tuno - 1] < dos[tdos - 1]) {
		newTab[tuno + tdos - 1] = dos[tdos - 1];
	}
	else {
		newTab[tuno + tdos - 1] = uno[tuno - 1];
	}
	return newTab;
}

int main() {
	int uno[] = { 1,3,6,7,9 };
	int tuno = 5;
	int dos[] = { 0,2,4,5,8,10 };
	int tdos = 6;

	int* tab = merge(uno, tuno , dos, tdos);
	int taille = tuno + tdos;
	for (int i = 0; i < taille; i++) {
		printf("%d ", tab[i]);
	}

	free(tab);

	return 0;
}