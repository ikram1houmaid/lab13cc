
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cassert>
#include <concepts>
using namespace std;

// 1. Concept Sortable
template<typename T>
concept Sortable = requires(T a, T b) {
    { a < b } -> convertible_to<bool>;
};

// 2. Foncteur pour le tri croissant
struct Asc {
    template<typename T>
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

// 3. Foncteur pour le tri decroissant
struct Desc {
    template<typename T>
    bool operator()(const T& a, const T& b) const {
        return a > b;
    }
};

// 4. Fonction de tri rapide QuickSort
template<Sortable T, typename Comp = less<T>>
void quickSort(vector<T>& v, Comp comp = Comp{}) {

    if (v.size() <= 1) {
        return;
    }

    T pivot = v[v.size() / 2];

    vector<T> gauche;
    vector<T> milieu;
    vector<T> droite;

    for (const T& element : v) {

        if (comp(element, pivot)) {
            gauche.push_back(element);
        }
        else if (comp(pivot, element)) {
            droite.push_back(element);
        }
        else {
            milieu.push_back(element);
        }
    }

    quickSort(gauche, comp);
    quickSort(droite, comp);

    v.clear();

    for (const T& element : gauche)
        v.push_back(element);

    for (const T& element : milieu)
        v.push_back(element);

    for (const T& element : droite)
        v.push_back(element);
}

// 5. Structure utilisateur
struct Etudiant {

    string nom;
    int note;

    // Operateur <
    bool operator<(const Etudiant& autre) const {
        return note < autre.note;
    }

    bool operator>(const Etudiant& autre) const {
        return note > autre.note;
    }
};

// Operateur << pour afficher un etudiant
ostream& operator<<(ostream& os, const Etudiant& e) {
    os << e.nom << " : " << e.note;
    return os;
}

// 6. Fonction pour afficher un vecteur
template<typename T>
void afficher(const vector<T>& v) {

    for (const T& element : v) {
        cout << element << " ";
    }

    cout << endl;
}

// 7. Tests unitaires simples
int main() {

    // TEST 1 : Entiers
    cout << "===== TEST DES ENTIERS =====" << endl;

    vector<int> nombres = {8, 3, 5, 1, 9, 2};

    quickSort(nombres, Asc{});

    cout << "Tri croissant : ";
    afficher(nombres);

    assert(is_sorted(nombres.begin(), nombres.end()));

    quickSort(nombres, Desc{});

    cout << "Tri decroissant : ";
    afficher(nombres);

    assert(is_sorted(nombres.begin(), nombres.end(),
                     greater<int>{}));


    // TEST 2 : Chaines de caracteres
    cout << "\n===== TEST DES STRINGS =====" << endl;

    vector<string> mots = {
        "Orange", "Banane", "Pomme", "Abricot"
    };

    quickSort(mots, Asc{});

    cout << "Tri croissant : ";
    afficher(mots);

    assert(is_sorted(mots.begin(), mots.end()));

    quickSort(mots, Desc{});

    cout << "Tri decroissant : ";
    afficher(mots);

    assert(is_sorted(mots.begin(), mots.end(),
                     greater<string>{}));


    // TEST 3 : Objets Etudiant
    cout << "\n===== TEST DES ETUDIANTS =====" << endl;

    vector<Etudiant> etudiants = {
        {"Sara", 15},
        {"Ikram", 18},
        {"Amine", 12},
        {"Youssef", 16}
    };

    quickSort(etudiants, Asc{});

    cout << "Tri par note croissante :" << endl;
    afficher(etudiants);

    // Verification du tri
    assert(is_sorted(etudiants.begin(), etudiants.end()));

    quickSort(etudiants, Desc{});

    cout << "Tri par note decroissante :" << endl;
    afficher(etudiants);

    assert(is_sorted(etudiants.begin(), etudiants.end(),
                     [](const Etudiant& a, const Etudiant& b) {
                         return a.note > b.note;
                     }));


    cout << "\nTous les tests sont reussis !" << endl;

    return 0;
}
