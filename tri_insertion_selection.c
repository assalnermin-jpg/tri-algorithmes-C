#include <stdio.h>

// Tri par insertion
void tri_insertion(int *tab, int taille) {
    for (int i = 1; i < taille; i++) {
        int key = tab[i];
        int j = i - 1;

        while (j >= 0 && tab[j] > key) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = key;
    }
}

// Tri par sélection
void tri_selection(int *tab, int taille) {
    for (int i = 0; i < taille - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < taille; j++) {
            if (tab[j] < tab[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = tab[i];
            tab[i] = tab[min_idx];
            tab[min_idx] = temp;
        }
    }
}
