#include <stdio.h>
#include <stdlib.h>

void fusion(int *tab, int gauche, int milieu, int droite) {
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = tab[gauche + i];
    for (int j = 0; j < n2; j++) R[j] = tab[milieu + 1 + j];

    int i = 0, j = 0, k = gauche;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) tab[k++] = L[i++];
        else tab[k++] = R[j++];
    }
    while (i < n1) tab[k++] = L[i++];
    while (j < n2) tab[k++] = R[j++];

    free(L);
    free(R);
}

void tri_fusion_rec(int *tab, int gauche, int droite) {
    if (gauche < droite) {
        int milieu = gauche + (droite - gauche) / 2;
        tri_fusion_rec(tab, gauche, milieu);
        tri_fusion_rec(tab, milieu + 1, droite);
        fusion(tab, gauche, milieu, droite);
    }
}

void tri_fusion(int *tab, int taille) {
    tri_fusion_rec(tab, 0, taille - 1);
}


int partition(int *tab, int low, int high) {
    int pivot = tab[(low + high) / 2];
    int i = low, j = high;
    while (i <= j) {
        while (tab[i] < pivot) i++;
        while (tab[j] > pivot) j--;
        if (i <= j) {
            int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++; j--;
        }
    }
    return i;
}

void tri_rapide_rec(int *tab, int low, int high) {
    if (low < high) {
        int pi = partition(tab, low, high);
        tri_rapide_rec(tab, low, pi - 1);
        tri_rapide_rec(tab, pi, high);
    }
}

void tri_rapide(int *tab, int taille) {
    tri_rapide_rec(tab, 0, taille - 1);
}
