#include"header.h"

int main() {
	Liste* liste = malloc(sizeof(Liste));
	liste->premier = NULL;
	int loop = 4;
	for (int i = 0; i < loop; i++) {
		initMedoc(liste);
	}
	afficher(liste);
	liste = tri(liste);
	afficher(liste);

	libere(liste);
	free(liste);
	liste = NULL;

	return 0;
}