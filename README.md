# 📦 push_swap

**push_swap** est un projet algorithmique de l'école 42 qui consiste à trier une pile de nombres en utilisant un nombre minimal d'opérations prédéfinies. Il permet de se familiariser avec les structures de données, la gestion de la mémoire, et l’optimisation d’algorithmes.

## 🧠 Objectif

Créer un programme capable de trier des entiers passés en arguments, en utilisant uniquement un ensemble restreint d'opérations sur deux piles (A et B), et en produisant l’algorithme le plus efficace possible en nombre de coups.

## 🧩 Les opérations autorisées

Tu peux utiliser uniquement ces opérations sur les piles :

- `sa` / `sb` / `ss` — swap le haut de la pile A ou B (ou les deux)
- `pa` / `pb` — push (déplace l'élément en haut de B vers A ou inversement)
- `ra` / `rb` / `rr` — rotate (décale tous les éléments vers le haut)
- `rra` / `rrb` / `rrr` — reverse rotate (décale tous les éléments vers le bas)

## 🧪 Compilation et Utilisation

### Compilation

Le projet utilise un `Makefile` pour faciliter la compilation.

```bash
make
```

Pour nettoyer les fichiers objets :

```bash
make clean
```

Pour supprimer tous les fichiers compilés (objets + exécutable) :

```bash
make fclean
```

Pour recompiler le projet :

```bash
make re
```

### 📄 Utilisation

```bash
./push_swap 3 2 1
```

Cela affichera les instructions nécessaires pour trier la pile {3, 2, 1} (par exemple : sa ra).
