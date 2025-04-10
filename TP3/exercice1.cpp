#include <iostream>

using namespace std;

class EnsembleEntiers {
private:
    int tableau[100]; // Tableau pour stocker les entiers
    int taille; // Nombre d'entiers dans l'ensemble

public:
    EnsembleEntiers() : taille(0) {} // Initialise la taille à 0

    void vider() {
        taille = 0; // Vide l'ensemble
    }

    void ajouter(int element) {
        if (taille < 100) {
            tableau[taille] = element; // Ajoute l'élément à la fin
            taille++; // Augmente la taille
        }
    }

    void retirer(int element) {
        for (int i = 0; i < taille; ++i) {
            if (tableau[i] == element) {
                // Remplace l'élément à retirer par le dernier élément
                tableau[i] = tableau[taille - 1];
                taille--; // Diminue la taille
                return;
            }
        }
    }

    void copier(const EnsembleEntiers& autre) {
        taille = autre.taille;
        for (int i = 0; i < taille; ++i) {
            tableau[i] = autre.tableau[i];
        }
    }

    bool est_present(int element) const {
        for (int i = 0; i < taille; ++i) {
            if (tableau[i] == element) {
                return true;
            }
        }
        return false;
    }

    bool est_egal(const EnsembleEntiers& autre) const {
        if (taille != autre.taille) {
            return false;
        }
        for (int i = 0; i < taille; ++i) {
            if (!autre.est_present(tableau[i])) {
                return false;
            }
        }
        return true;
    }

    void afficher() const {
        cout << "{";
        for (int i = 0; i < taille; ++i) {
            cout << tableau[i];
            if (i < taille - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }
};

int main() {
    EnsembleEntiers ens1, ens2;

    ens1.ajouter(1);
    ens1.ajouter(2);
    ens1.ajouter(3);

    cout << "Ensemble 1 : ";
    ens1.afficher(); // {1, 2, 3}

    cout << "2 est-il dans l'ensemble 1 ? " << (ens1.est_present(2) ? "Oui" : "Non") << endl; // Oui

    ens2.copier(ens1);
    cout << "Ensemble 2 (copie de 1) : ";
    ens2.afficher(); // {1, 2, 3}

    ens1.retirer(2);
    cout << "Ensemble 1 apres retrait de 2 : ";
    ens1.afficher(); // {1, 3}

    ens1.vider();
    cout << "Ensemble 1 apres vidage : ";
    ens1.afficher(); // {}

    return 0;
}
