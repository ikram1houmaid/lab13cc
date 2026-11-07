
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
using namespace std;

// Exception : pile pleine
class StackOverflow : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : la pile est pleine !";
    }
};

// Exception : pile vide
class StackUnderflow : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : la pile est vide !";
    }
};

// Classe generique Stack
template <typename T>
class Stack {

private:
    unique_ptr<T[]> data;
    size_t capacity;
    size_t top;

public:

    // Constructeur avec capacite par defaut
    Stack(size_t cap = 100)
        : data(cap > 0 ? make_unique<T[]>(cap) : nullptr),
          capacity(cap), top(0) {
    }

    // Constructeur avec iterateurs
    template <typename Iterator>
    Stack(Iterator begin, Iterator end)
        : capacity(0), top(0) {

        // Calculer le nombre d'elements
        for (Iterator it = begin; it != end; ++it) {
            capacity++;
        }

        data = capacity > 0 ? make_unique<T[]>(capacity) : nullptr;

        // Copier les elements dans la pile
        for (Iterator it = begin; it != end; ++it) {
            push(*it);
        }
    }

    // Ajouter un element
    void push(const T& valeur) {

        if (top >= capacity) {
            throw StackOverflow();
        }

        data[top] = valeur;
        top++;
    }

    // Retirer le dernier element
    void pop() {

        if (empty()) {
            throw StackUnderflow();
        }

        top--;
    }

    // Consulter le sommet
    const T& peek() const {

        if (empty()) {
            throw StackUnderflow();
        }

        return data[top - 1];
    }

    // Verifier si la pile est vide
    bool empty() const {
        return top == 0;
    }

    // Retourner le nombre d'elements
    size_t size() const {
        return top;
    }

    // Retourner la capacite
    size_t getCapacity() const {
        return capacity;
    }
};


// Programme principal
int main() {

    cout << "===== TEST 1 : PILE D'ENTIERS =====" << endl;

    Stack<int> s(3);

    try {

        s.push(10);
        s.push(20);
        s.push(30);

        cout << "Sommet : " << s.peek() << endl;

        // Tester le depassement
        s.push(40);

    }
    catch (const StackOverflow& e) {
        cout << e.what() << endl;
    }

    cout << "\n===== TEST 2 : SUPPRESSION =====" << endl;

    try {

        while (!s.empty()) {
            cout << "Element supprime : " << s.peek() << endl;
            s.pop();
        }

        // Tester pile vide
        s.pop();

    }
    catch (const StackUnderflow& e) {
        cout << e.what() << endl;
    }


    cout << "\n===== TEST 3 : PILE DE CHAINES =====" << endl;

    Stack<string> mots(3);

    mots.push("Bonjour");
    mots.push("C++");
    mots.push("Eclipse");

    cout << "Sommet : " << mots.peek() << endl;


    cout << "\n===== TEST 4 : INITIALISATION AVEC ITERATEURS =====" << endl;

    int nombres[] = {1, 2, 3, 4, 5};

    Stack<int> s2(nombres, nombres + 5);

    cout << "Nombre d'elements : " << s2.size() << endl;
    cout << "Sommet : " << s2.peek() << endl;


    cout << "\n===== TEST 5 : GRAND NOMBRE D'OBJETS =====" << endl;

    Stack<int> grandePile(100000);

    for (int i = 0; i < 100000; i++) {
        grandePile.push(i);
    }

    cout << "Nombre d'elements : " << grandePile.size() << endl;
    cout << "Sommet : " << grandePile.peek() << endl;

    cout << "\nFin du programme !" << endl;

    return 0;
}
