#include <stdio.h>
#include <stdlib.h>

// Tri par dénombrement
void tri_denumeration(int *tab, int taille, int min, int max) {
    int range = max - min + 1;
    int *count = (int*)calloc(range, sizeof(int));

    // Comptage des occurrences
    for (int i = 0; i < taille; i++) {
        count[tab[i] - min]++;
    }

    // Reconstruction du tableau trié
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            tab[index++] = i + min;
            count[i]--;
        }
    }

    free(count);
}
