
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Classe generique ArrayDyn
template <typename T>
class ArrayDyn {

private:
    T* data;
    size_t capacite;
    size_t taille;

    // Augmenter la capacite
    void agrandir() {
        capacite = (capacite == 0) ? 1 : capacite * 2;

        T* nouveau = new T[capacite];

        for (size_t i = 0; i < taille; i++) {
            nouveau[i] = data[i];
        }

        delete[] data;
        data = nouveau;
    }

public:

    // Constructeur par defaut
    ArrayDyn() {
        data = nullptr;
        capacite = 0;
        taille = 0;
    }

    // Constructeur avec capacite initiale
    ArrayDyn(size_t cap) {
        capacite = cap;
        taille = 0;
        data = (capacite > 0) ? new T[capacite] : nullptr;
    }

    // Constructeur de copie
    ArrayDyn(const ArrayDyn& autre) {
        capacite = autre.capacite;
        taille = autre.taille;

        data = (capacite > 0) ? new T[capacite] : nullptr;

        for (size_t i = 0; i < taille; i++) {
            data[i] = autre.data[i];
        }
    }

    // Operateur d'affectation
    ArrayDyn& operator=(const ArrayDyn& autre) {

        if (this != &autre) {

            T* nouveau = (autre.capacite > 0)
                         ? new T[autre.capacite] : nullptr;

            for (size_t i = 0; i < autre.taille; i++) {
                nouveau[i] = autre.data[i];
            }

            delete[] data;

            data = nouveau;
            capacite = autre.capacite;
            taille = autre.taille;
        }

        return *this;
    }

    // Destructeur
    ~ArrayDyn() {
        delete[] data;
    }

    // Ajouter un element
    void push_back(const T& valeur) {

        if (taille == capacite) {
            agrandir();
        }

        data[taille] = valeur;
        taille++;
    }

    // Supprimer le dernier element
    void pop_back() {

        if (taille == 0) {
            throw out_of_range("Le tableau est vide !");
        }

        taille--;
    }

    // Acces avec controle de bornes
    T& operator[](size_t index) {

        if (index >= taille) {
            throw out_of_range("Indice invalide !");
        }

        return data[index];
    }

    const T& operator[](size_t index) const {

        if (index >= taille) {
            throw out_of_range("Indice invalide !");
        }

        return data[index];
    }

    // Classe interne Iterator
    class Iterator {

    private:
        T* ptr;

    public:

        Iterator(T* p = nullptr) {
            ptr = p;
        }

        // Acces a l'element
        T& operator*() const {
            return *ptr;
        }

        // Incrementer
        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        // Decrementer
        Iterator& operator--() {
            --ptr;
            return *this;
        }

        // Comparaison
        bool operator!=(const Iterator& autre) const {
            return ptr != autre.ptr;
        }
    };

    // Retourner le premier element
    Iterator begin() {
        return Iterator(data);
    }

    // Retourner la position apres le dernier element
    Iterator end() {
        return Iterator(data + taille);
    }

    // Afficher la taille
    size_t getTaille() const {
        return taille;
    }
};

// Classe maison pour tester
class Etudiant {

private:
    string nom;
    int age;

public:

    Etudiant(string n, int a) {
        nom = n;
        age = a;
    }

    void afficher() const {
        cout << nom << " - " << age << " ans" << endl;
    }
};

// Programme principal
int main() {

    // Test avec int
    cout << "===== Tableau des entiers =====" << endl;

    ArrayDyn<int> nombres;

    nombres.push_back(10);
    nombres.push_back(20);
    nombres.push_back(30);

    for (auto &e : nombres) {
        cout << e << " ";
    }

    cout << endl;

    // Test avec string
    cout << "\n===== Tableau des chaines =====" << endl;

    ArrayDyn<string> mots;

    mots.push_back("Bonjour");
    mots.push_back("C++");
    mots.push_back("Eclipse");

    for (auto &e : mots) {
        cout << e << " ";
    }

    cout << endl;

    // Test avec un objet maison
    cout << "\n===== Tableau des etudiants =====" << endl;

    ArrayDyn<Etudiant> etudiants;

    etudiants.push_back(Etudiant("Ikram", 21));
    etudiants.push_back(Etudiant("Sara", 22));

    for (auto &e : etudiants) {
        e.afficher();
    }

    // Test de pop_back
    nombres.pop_back();

    cout << "\nApres suppression : ";

    for (auto &e : nombres) {
        cout << e << " ";
    }

    cout << endl;

    return 0;
}
