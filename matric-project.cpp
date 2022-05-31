#include <iostream>

using namespace std;

    long long ans = 0, ans1 = 0, ans2 = 0; // a global varible to store the final determinant used in determinant function


/// A function to Add 2 Matrix of any size
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

//// a function to Subtract 2 Matrix of any size
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

/// A function to Multiply 2 Matrix of any size
void Mult(int A[][10], int B[][10], int rA, int rB, int cA, int cB){

    int sum;

    for (int i=0; i < rA; i++){
            for (int l=0; l < cB; l++){

                sum = 0;
                
                for (int k=0; k < cA; k ++){ // Because Column of Matrix A = Rows of Matrix B we can use either of them

                    sum += A[i][k] * B[k][l];
                }


                cout << sum << " ";
        }
        cout << endl;
    }
} 


/**
 * Gets a determinant of any matrix by minimizing it to a 2x2 matrix
 * @param mat the matrix needed to get the determinant from
 * @param dim number of rows/ columns of the matrix that indicates its dimensions (dim x dim)
 * @return int 
 */
long long det(int mat[][10], int dim){
    
    int factors[10] ; // an array to store the factors that will be multiplied with at the end
    int red_mat[10][10]; // an array to store the reduced matrix to be put in the function again
    int sign[10] = {1,-1,1,-1,1,-1,1,-1,1,-1}; // an array to change the sign of the factors
    long long ans_arr[10] = {0} ; //an array to store the answers and try to avoid the error  
    int f; // detrmines we are in the which factor

    if (dim == 1)
        return mat[0][0];
    if (dim == 2){
        ans1 = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        return ans1;
        }
    else {
        for (int i = 0; i < dim; i++){
            factors[i] = mat[0][i];
        }

        for (int z = 0; z < dim; z++){
            factors[z] = factors[z] * sign[z];
        }

        int m = 0, n = 0; // varibles to change the rows and columns of the reduced matrix
        for(f = 0; f < dim; f++){
            for (int k = 1; k < dim; k++){ // for loop to go through the matrix except the first row
                    for(int l = 0; l < dim; l++){
                        if (l == f)
                            continue; 
                        red_mat[n][m] = mat[k][l];
                        m++;
                    }
                n++;
                m=0;
            }
            n=0;
                ans_arr[f] = (factors[f] * det(red_mat,dim -1)); // ERROR: Not working adding 2 times after completing the 3x3 matrix of the first 4x4
        }
    }
    ans = 0;
    for (int y = 0; y < dim ; y++)
        ans += ans_arr[y];
    if (f == (dim -1)){
        for (int y = 0; y < dim ; y++)
        ans2 += ans_arr[y];
        return ans2;
    }

    return ans;

}


int main (){
    int rA, rB, cA, cB;
    int op;

    int matA [10][10];
    int matB [10][10];

    cout << "Please enter dimensions of Matrix A:\n";
    cin >> rA >> cA;

    cout << "Please enter dimensions of Matrix B:\n";
    cin >> rB >> cB;

    cout << "Please enter values of Matrix A:\n";
    for (int i=0; i < rA; i++){
        for (int j=0; j < cA; j++)
            cin >> matA[i][j];
    }

    cout << "Please enter values of Matrix B:\n";
    for (int i=0; i < rB; i++){
        for (int j=0; j < cB; j++)
            cin>> matB[i][j];
    }
    do {
        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
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
        
        case 3:
            if (cA == rB)
                Mult(matA, matB, rA, rB, cA, cB);
            else
                cout << "The operation you chose is invalid for the given matrices.\n";
            break;
        
        case 4:
            break;

        case 5:
            if (rA == cA)
                cout << det(matA, rA) << endl;
            else
                cout << "The operation you chose is invalid for the given matrices.\n";
                ans = 0; // returning the varible to 0 after completion  
            break;
        
        case 6:
            if (rB == cB)
                cout << det(matB, rB) << endl;
            else
                cout << "The operation you chose is invalid for the given matrices.\n";
                ans = 0; // returning the varible to 0 after completion  
   
            break;    

        default:
            break;
        }

    } while (op != 7);
    cout << "Thank you!";
}