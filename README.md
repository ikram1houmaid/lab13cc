# TP : Programmation Générique Avancée en C++

## Présentation

Ce projet regroupe quatre exercices pratiques en C++ portant sur la programmation générique (Templates), les conteneurs dynamiques, la surcharge des opérateurs, les pointeurs intelligents, les exceptions et les concepts C++20.

## Objectifs pédagogiques

- Maîtriser les templates de classes et de fonctions.
- Créer des conteneurs génériques.
- Surcharger les opérateurs en C++.
- Manipuler les pointeurs intelligents (`std::unique_ptr`).
- Gérer les erreurs avec les exceptions personnalisées.
- Utiliser les concepts C++20.
- Implémenter des foncteurs et des algorithmes de tri.

---

## Exercice 1 : Conteneur dynamique générique avec itérateur personnalisé

### Objectif
Créer un conteneur générique `ArrayDyn<T>` similaire à `std::vector`, sans utiliser directement la STL pour le stockage.

### Fonctionnalités
- Constructeur par défaut.
- Constructeur avec capacité initiale.
- Constructeur de copie.
- Opérateur d'affectation.
- Destructeur.
- Ajout d'éléments avec `push_back()`.
- Suppression avec `pop_back()`.
- Accès aux éléments avec `operator[]` et contrôle des bornes.
- Création d'un itérateur personnalisé `Iterator`.
- Parcours avec `begin()`, `end()` et `for(auto &e : array)`.

### Tests réalisés
- Tableau d'entiers (`int`).
- Tableau de chaînes de caractères (`std::string`).
- Tableau d'objets personnalisés (`Etudiant`).

### Notions utilisées
`Templates`, `new[]`, `delete[]`, `Rule of Three`, `Iterators`, `Operator Overloading`.

---

## Exercice 2 : Matrice générique et surcharge des opérateurs

### Objectif
Créer une classe générique `Matrice<T, N, M>` permettant de manipuler des matrices de dimensions fixes.

### Fonctionnalités
- Stockage dans un tableau statique `T data[N][M]`.
- Constructeur par défaut avec initialisation à zéro.
- Constructeur avec valeurs initiales.
- Surcharge de l'opérateur `+` pour l'addition.
- Surcharge de l'opérateur `-` pour la soustraction.
- Surcharge de l'opérateur `*` pour la multiplication matricielle.
- Surcharge de l'opérateur `<<` pour l'affichage.

### Tests réalisés
- Matrices d'entiers (`int`).
- Matrices de nombres décimaux (`double`).
- Addition et soustraction de matrices.
- Multiplication de matrices de dimensions compatibles.
- Affichage formaté des résultats.

### Notions utilisées
`Class Templates`, `Multiple Template Parameters`, `Operator Overloading`, `Friend Functions`, `Static Arrays`.

---

## Exercice 3 : Pile générique sécurisée avec std::unique_ptr

### Objectif
Créer une pile générique `Stack<T>` avec une gestion automatique de la mémoire à l'aide de `std::unique_ptr`.

### Fonctionnalités
- Stockage dynamique avec `std::unique_ptr<T[]>`.
- Gestion de la capacité et du sommet de la pile.
- Constructeur avec capacité par défaut.
- Constructeur avec itérateurs `begin` et `end`.
- Ajout d'éléments avec `push()`.
- Suppression avec `pop()`.
- Consultation du sommet avec `peek()`.
- Vérification de la pile avec `empty()`.
- Gestion des exceptions personnalisées :
  - `StackOverflow` : pile pleine.
  - `StackUnderflow` : pile vide.

### Tests réalisés
- Pile d'entiers.
- Pile de chaînes de caractères.
- Initialisation à partir d'un tableau avec des itérateurs.
- Test avec 100 000 éléments.
- Vérification de la gestion automatique de la mémoire.

### Notions utilisées
`Templates`, `std::unique_ptr`, `Smart Pointers`, `Exceptions`, `try/catch`, `LIFO`.

---

## Exercice 4 : Foncteur générique de tri avec contraintes C++20

### Objectif
Créer un algorithme de tri générique `quickSort()` utilisant les concepts C++20 et les foncteurs pour paramétrer l'ordre de comparaison.

### Fonctionnalités
- Définition du concept `Sortable`.
- Vérification de la présence de l'opérateur `<`.
- Implémentation de l'algorithme QuickSort.
- Création du foncteur `Asc` pour le tri croissant.
- Création du foncteur `Desc` pour le tri décroissant.
- Utilisation d'un comparateur par défaut `std::less<T>`.
- Tests avec plusieurs types de données.

### Tests réalisés
- Tri d'un `std::vector<int>`.
- Tri d'un `std::vector<std::string>`.
- Tri d'objets personnalisés `Etudiant`.
- Vérification du tri avec `assert()` et `std::is_sorted()`.

### Notions utilisées
`C++20 Concepts`, `Function Templates`, `Functors`, `operator()`, `QuickSort`, `std::vector`, `Unit Testing`.

---

## Technologies utilisées

- **Langage :** C++
- **Compilateur :** GCC / G++
- **Environnement de développement :** Eclipse IDE
- **Standard :** C++20 pour l'exercice 4
- **Bibliothèques :** STL (`vector`, `string`, `memory`, `functional`, `algorithm`, `cassert`, etc.).

## Compilation et exécution

### Exercices 1, 2 et 3

```bash
g++ -std=c++14 main.cpp -o main
```

### Exercice 4

```bash
g++ -std=c++20 main.cpp -o main
```

### Exécution

Sous Linux :

```bash
./main
```

Sous Windows :

```bash
main.exe
```

## Structure du projet

```text
Projet_CPP/
│
├── Exercice1/
│   └── main.cpp
│
├── Exercice2/
│   └── main.cpp
│
├── Exercice3/
│   └── main.cpp
│
├── Exercice4/
│   └── main.cpp
│
└── README.md
```

## Conclusion

Ce TP permet de mettre en pratique les principales notions de la programmation générique avancée en C++.

Les quatre exercices couvrent la création de conteneurs personnalisés, les opérations sur les matrices, la gestion sécurisée de la mémoire et l'utilisation des concepts C++20 pour développer des algorithmes génériques et réutilisables.

---
**Fin du TP – Programmation Générique Avancée en C++**
<img width="960" height="540" alt="image" src="https://github.com/user-attachments/assets/fb4fabc0-d352-462f-89b9-55078fb684d6" />
<img width="960" height="540" alt="image" src="https://github.com/user-attachments/assets/6b97f509-f273-4594-9029-4b7481094b9c" />
<img width="960" height="540" alt="image" src="https://github.com/user-attachments/assets/76215298-799e-40a3-b857-ad9e48a642e3" />
<img width="960" height="540" alt="image" src="https://github.com/user-attachments/assets/45b52350-1e75-465a-9ab7-59204a13a905" />
