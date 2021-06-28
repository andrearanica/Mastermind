#include <iostream>
using namespace std;

const int DIM = 4;                                      //Indica la dimensione max del codice

void generaCodice(int codice[]) {
    for (int i = 0; i < DIM; i++) {
        codice[i] = rand() % 10;
    }
}

void stampaTabella(int codice[]) {
    cout << "| ";
    for (int i = 0; i < DIM; i++) {
        cout << codice[i];
    }
    cout << " |";
    cout << endl;
    cout << "--------";
    cout << endl;
}

bool turno(int input[], int codice[]) {
    for (int i = 0; i < DIM; i++) {
        if (input[i] != codice[i]) {
            return true;
        }
    }
    return false;
}

int main()
{
    int codice[4];
    int input[4];
    int tentativi = 7;
    bool gameOver = false, continua;

    cout << "Benvenuto nel gioco MASTERMIND\n";
    system("pause");

    srand(time(NULL));

    generaCodice(codice);

    //cout << codice;

    do {

        system("cls");
        stampaTabella(codice);
        
        for (int i = 0; i < DIM; i++) {
            cout << "Inserisci la " << i+1 << " cifra del codice: ";
            cin >> input[i];
        }

        continua = turno(input, codice);                                                    //Se continua vale TRUE, allora si continua

        if (continua == false) {
            cout << "HAI VINTO! HAI INDOVINATO IL CODICE!" << endl;
        }
        else {
            cout << "Codice non corretto!"<<endl;
            system("pause");
        }

    } while (continua == true);

    return 0;
}