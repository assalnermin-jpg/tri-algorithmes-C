# Comparaison expérimentale d'algorithmes de tri — C

**C (C99) · Algorithmique · GNUPlot** — Projet universitaire, L3 CMI-D3S, Université Paris Nanterre (novembre 2025)

Implémentation et benchmark de **8 algorithmes de tri** pour vérifier expérimentalement leurs complexités théoriques.

## Résultat clé

**QuickSort est environ 300 fois plus rapide que le tri à bulle** sur 10 000 éléments aléatoires (0,00108 s contre 0,345 s), ce qui confirme l'écart entre une complexité O(n log n) et O(n²).

| Algorithme | Complexité | Temps moyen, 10 000 éléments aléatoires |
|---|---|---|
| Tri rapide (QuickSort) | O(n log n) en moyenne | **0,00108 s** |
| Tri fusion (MergeSort) | O(n log n) | 0,00268 s |
| Tri par insertion | O(n²) | 0,0545 s |
| Tri par sélection | O(n²) | 0,105 s |
| Tri cocktail | O(n²) | 0,191 s |
| Tri à bulle (optimisé arrêt) | O(n²) | 0,241 s |
| Tri à bulle (optimisé boucle) | O(n²) | 0,249 s |
| Tri à bulle (basique) | O(n²) | 0,345 s |

Le tri par dénombrement a également été implémenté.

## Démarche

1. **Génération des données :** tableaux croissants, décroissants, constants et 500 tableaux aléatoires, pour des tailles de 1 000, 5 000 et 10 000 éléments. Les données sont générées une seule fois puis stockées dans des fichiers texte, pour que tous les algorithmes soient testés sur les mêmes tableaux.
2. **Mesure :** temps d'exécution du tri seul avec `clock()` (`time.h`), moyenné sur les tableaux aléatoires.
3. **Visualisation :** courbes de performance par type de tableau avec GNUPlot.

## Enseignements

- Les tris quadratiques deviennent rapidement inefficaces quand la taille augmente.
- Parmi eux, le tri par insertion est le plus performant.
- QuickSort est le plus rapide en moyenne ; MergeSort offre des performances très stables quel que soit le type de tableau.

## Contenu du dépôt

- Code source en C des algorithmes de tri

**Environnement :** MacBook Pro (ARM64), macOS, Apple clang 15, standard C99, GNUPlot 6.0.

---
**Nermin Assal** — Étudiante en M1 CMI Data Science, Université Paris Nanterre
