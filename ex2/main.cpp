
#include <iostream>
using namespace std;

// Classe generique Matrice
template <typename T, int N, int M>
class Matrice {

private:
    T data[N][M];

public:

    // Constructeur par defaut : initialiser a 0
    Matrice() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] = 0;
            }
        }
    }

    // Constructeur avec liste d'initialisation
    Matrice(T valeurs[N][M]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                data[i][j] = valeurs[i][j];
            }
        }
    }

    // Operateur + : addition de deux matrices
    Matrice operator+(const Matrice& autre) const {

        Matrice resultat;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                resultat.data[i][j] = data[i][j] + autre.data[i][j];
            }
        }

        return resultat;
    }

    // Operateur - : soustraction de deux matrices
    Matrice operator-(const Matrice& autre) const {

        Matrice resultat;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                resultat.data[i][j] = data[i][j] - autre.data[i][j];
            }
        }

        return resultat;
    }

    // Operateur * : multiplication de matrices
    template <int P>
    Matrice<T, N, P> operator*(const Matrice<T, M, P>& autre) const {

        Matrice<T, N, P> resultat;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++) {

                resultat.data[i][j] = 0;

                for (int k = 0; k < M; k++) {
                    resultat.data[i][j] += data[i][k] * autre.data[k][j];
                }
            }
        }

        return resultat;
    }

    // Operateur << pour afficher la matrice
    friend ostream& operator<<(ostream& os, const Matrice& mat) {

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                os << mat.data[i][j] << "\t";
            }
            os << endl;
        }

        return os;
    }

    // Autoriser les autres dimensions a acceder aux donnees
    template <typename U, int L, int C>
    friend class Matrice;
};


int main() {

    // TEST 1 : Matrices d'entiers

    cout << "===== MATRICES D'ENTIERS =====" << endl;

    int a[2][2] = {
        {1, 2},
        {3, 4}
    };

    int b[2][2] = {
        {5, 6},
        {7, 8}
    };

    Matrice<int, 2, 2> A(a);
    Matrice<int, 2, 2> B(b);

    cout << "Matrice A :" << endl;
    cout << A;

    cout << "Matrice B :" << endl;
    cout << B;

    cout << "A + B :" << endl;
    cout << A + B;

    cout << "A - B :" << endl;
    cout << A - B;

    cout << "A * B :" << endl;
    cout << A * B;


    // TEST 2 : Matrices de double

    cout << "\n===== MATRICES DE DOUBLE =====" << endl;

    double x[2][2] = {
        {1.5, 2.5},
        {3.5, 4.5}
    };

    double y[2][2] = {
        {2.0, 1.0},
        {1.0, 2.0}
    };

    Matrice<double, 2, 2> X(x);
    Matrice<double, 2, 2> Y(y);

    cout << "Matrice X :" << endl;
    cout << X;

    cout << "Matrice Y :" << endl;
    cout << Y;

    cout << "X + Y :" << endl;
    cout << X + Y;

    cout << "X * Y :" << endl;
    cout << X * Y;


    // TEST 3 : Multiplication de dimensions differentes

    cout << "\n===== MULTIPLICATION 2x2 PAR 2x3 =====" << endl;

    int c[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    Matrice<int, 2, 3> C(c);

    cout << "A * C :" << endl;
    cout << A * C;

    return 0;
}
