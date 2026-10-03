#include <stdio.h>
#include <stdbool.h>

// Tri cocktail
void tri_cocktail(int *tab, int taille) {
    bool echange = true;
    int debut = 0;
    int fin = taille - 1;

    while (echange) {
        echange = false;

        // Aller
        for (int i = debut; i < fin; i++) {
            if (tab[i] > tab[i + 1]) {
                int temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                echange = true;
            }
        }

        if (!echange) break; // tableau trié

        echange = false;
        fin--;

        // Retour
        for (int i = fin - 1; i >= debut; i--) {
            if (tab[i] > tab[i + 1]) {
                int temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                echange = true;
            }
        }
        debut++;
    }
}
