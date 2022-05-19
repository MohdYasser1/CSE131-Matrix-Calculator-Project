#include <iostream>

using namespace std;

int main (){
    int rA, rB, cA, cB;
    int op;

    int matA [100][100];
    int matB [100][100];

    cout << "Please enter dimentions of Matrix A:";
    cin >> rA >> cA;

    cout << "Please enter dimentions of Matrix B:";
    cin >> rB >> cB;

    cout << "Please enter values of Matrix A:";
    for (int i=0; i < rA; i++){
        for (int j=0; j < cA; j++)
            cin >> matA[i][j];
    }

    cout << "Please enter values of Matrix B:";
    for (int i=0; i < rB; i++){
        for (int j=0; j < cB; j++)
            cin>> matB[i][j];
    }
    do {
        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):";
        cin >> op;
    } while (op != 7);
    cout << "Thank you!";
}