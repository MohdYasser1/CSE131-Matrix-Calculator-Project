#include <iostream>

using namespace std;

void Add(int A[][10], int B[][10], int row, int col){ //passing only the rows and coloumns from one matrix only as the both of them has to be equal to add
    
    int add[10][10]; // A new matrix to store the added matrices
    
    for (int i =0; i < row; i++){
        for (int j=0; j < col; j++){
            add[i][j] = A[i][j] + B[i][j];
            cout << add[i][j] << " ";
        }
        cout << endl;
    }
}

void Sub(int A[][10], int B[][10], int row, int col){ //passing only the rows and coloumns from one matrix only as the both of them has to be equal to subtract
    
    int sub[10][10]; // A new matrix to store the subtracted matrices
    
    for (int i =0; i < row; i++){
        for (int j=0; j < col; j++){
            sub[i][j] = A[i][j] - B[i][j];
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }
}

int main (){
    int rA, rB, cA, cB;
    int op;

    int matA [10][10];
    int matB [10][10];

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

        switch (op)
        {
        case 1:
            if (rA == rB && cA == cB)
                Add(matA, matB, rA, cA);
            else
                cout << "The operation you chose is invalid for the given matrices.\n";
            break;
        
        case 2:
            if (rA == rB && cA == cB)
                Sub(matA, matB, rA, cA);
            else
                cout << "The operation you chose is invalid for the given matrices.\n";
            break;
        
        default:
            break;
        }

    } while (op != 7);
    cout << "Thank you!";
}