// Programul reprezinta o baza de date pentru un Minimarket de fructe si legume
#include <iostream>
#include <vector>
#include <algorithm> // Librarie de care foloseste functii de sortare, cautare, numarare si manipulare a elementelor 

using namespace std;
// Vom folosi structuri pentru realizarea programului prin urmare declaram structura Produs
struct Produs {
    int id;
    string denumire;
    string categorie;
    int cantitate;
    int pret;
    string data_livrarii;
    string data_expirarii;
};
// Clasa de lucru cu operatii CRUD
class BazaDeDateProduse {
private:
    vector<Produs> produse; // Vectorul de stocare a produselor
    
public:
	// Functia de tip CREATE (Crearea produselor)
    void creeazaProdus() {
        Produs p;
        cout << "Introduceti numele produsului: ";
        cin >> p.denumire;
        cout << "Introduceti categoria produsului: ";
        cin >> p.categorie;
        cout << "Introduceti cantitatea produsului (kg): ";
        cin >> p.cantitate;
        cout << "Introduceti pretul produsului (lei): ";
        cin >> p.pret;
        cout << "Introduceti data livrarii (zz-ll-aaaa): ";
        cin >> p.data_livrarii;
        cout << "Introduceti data expirarii (zz-ll-aaaa): ";
        cin >> p.data_expirarii;

        // Id-ul nu poate fi modificat, prin urmare se atribuie o variabile de tip static pentru un Id unic 
        static int nextId = 1;
        p.id = nextId++;
        // Adaugarea produselor
        produse.push_back(p);
        cout << "Produs creat cu succes.\n";
    }
    // Functia de afisare a produselor, READ
    void afiseazaProduse() {
    	// Se verifica mai intai daca vectorul este gol sau nu
        if (produse.empty()) {
            cout << "Niciun produs in baza de date.\n";
        } else {
            cout << "Produse in baza de date:\n";
            // Avem mai multe tipuri de variabile prin urmare folosim in iteratie o variabile de tip auto
            for (const auto &produs : produse) {
                cout << "ID: " << produs.id << ", Nume: " << produs.denumire << ", Categorie: " << produs.categorie
                     << ", Cantitate: " << produs.cantitate << ", Pret: " << produs.pret
                     << ", Data Livrarii: " << produs.data_livrarii << ", Data Expirarii: " << produs.data_expirarii << endl;
            }

            // Numararea produselor dupa categorie
            cout << "\nNumar de produse pe categorii:\n";
            vector<string> categorii; // Declararea vectorului de stocare pentru fiecare categorie
            for (const auto &produs : produse) {
            	// Utilizam functia find pentru a selecta prosusele dupa categorie
                if (find(categorii.begin(), categorii.end(), produs.categorie) == categorii.end()) {
                    categorii.push_back(produs.categorie);
                }
            }
            // Sortarea produselor dupa categorie
            for (const auto &categorie : categorii) {
            	// Folosim count_if in intervalul specificat si tipul categoriei pentru a numara produsele
                int numar = count_if(produse.begin(), produse.end(),
                                     [&categorie](const Produs &p) { return p.categorie == categorie; });
                cout << "Categorie: " << categorie << ", Numar: " << numar << endl;
            }
        }
    }
    // Functia de eliminare a produselor, DELETE
    void stergeProdus() {
        int id;
        cout << "Introduceti ID-ul produsului de sters: ";
        cin >> id;

        auto it = find_if(produse.begin(), produse.end(),
                          [&id](const Produs &p) { return p.id == id; });

        if (it != produse.end()) {
            produse.erase(it);
            cout << "Produs sters cu succes.\n";
        } else {
            cout << "Produsul nu a fost gasit.\n";
        }
    }
    // Functia UPDATE
    void modificaProdus() {
        int id;
        cout << "Introduceti ID-ul produsului de modificat: ";
        cin >> id;
        // Gasim produsul dupa id cu ajutorul functiei din libraria algorithm
        auto it = find_if(produse.begin(), produse.end(),
                          [&id](const Produs &p) { return p.id == id; });
        // Modificam produsul pana la sfarsitul caracteristicilor sale
        if (it != produse.end()) {
            cout << "Introduceti noile informatii pentru produs:\n";
            cout << "Introduceti numele produsului: ";
            cin >> it->denumire;
            cout << "Introduceti categoria produsului: ";
            cin >> it->categorie;
            cout << "Introduceti cantitatea produsului: ";
            cin >> it->cantitate;
            cout << "Introduceti pretul produsului: ";
            cin >> it->pret;
            cout << "Introduceti data livrarii (zz-ll-aaaa): ";
            cin >> it->data_livrarii;
            cout << "Introduceti data expirarii (zz-ll-aaaa): ";
            cin >> it->data_expirarii;

            cout << "Produs modificat cu succes.\n";
        } else {
            cout << "Produsul nu a fost gasit.\n";
        }
    }
};
// Functia principala
int main() {
	// Declarea instantei de stocare a produselor
    BazaDeDateProduse bazaDate;
    int optiune;


    do {
        cout << "\n  ===========Minimarket Meniu:============\n";
        cout << "             1. Adauga Produs\n";
        cout << "             2. Afiseaza Produse\n";
        cout << "             3. Modifica Produs\n";
        cout << "             4. Elimina Produs\n";
        cout << "             0. Iesire\n";
        cout << "           Introduceti optiunea: ";
        cin >> optiune;

        switch (optiune) {
            case 1:
                bazaDate.creeazaProdus();
                break;
            case 2:
                bazaDate.afiseazaProduse();
                break;
            case 3:
                bazaDate.modificaProdus();
                break;
            case 4:
                bazaDate.stergeProdus();
                break;
            case 0:
                cout << "Iesire din program.\n";
                break;
            default:
                cout << "Optiune invalida. Incercati din nou.\n";
        }

    } while (optiune != 0);

    return 0;
}
