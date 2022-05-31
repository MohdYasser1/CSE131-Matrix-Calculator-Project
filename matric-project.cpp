#include <iostream>

using namespace std;

    long long ans = 0, ans1 = 0, ans2 = 0; // a global varible to store the final determinant used in determinant function


/// A function to Add 2 Matrix of any size
void Add(double A[][10], double B[][10], int row, int col){ //passing only the rows and coloumns from one matrix only as the both of them has to be equal to add
    
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
void Sub(double A[][10], double B[][10], int row, int col){ //passing only the rows and coloumns from one matrix only as the both of them has to be equal to subtract
    
    int sub[10][10]; // A new matrix to store the subtracted matrices
    
    for (int i =0; i < row; i++){
        for (int j=0; j < col; j++){
            sub[i][j] = A[i][j] - B[i][j];
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }
}

double round(double x);


/// A function to Multiply 2 Matrix of any size
void Mult(double A[][10], double B[][10], int rA, int rB, int cA, int cB){

    double sum;

    for (int i=0; i < rA; i++){
            for (int l=0; l < cB; l++){

                sum = 0;
                
                for (int k=0; k < cA; k ++){ // Because Column of Matrix A = Rows of Matrix B we can use either of them

                    sum += A[i][k] * B[k][l];
                }


                cout << round(sum) << " ";
        }
        cout << endl;
    }
} 


/**
 * Gets a determinant of any matrix by minimizing it to a 2x2 matrix
 * @param mat the matrix needed to get the determinant from
 * @param dim number of rows/ columns of the matrix that indicates its dimensions (dim x dim)
 * @return long long the determinant of the matrix 
 */
long long det(double mat[][10], int dim){
    
    int factors[10] ;                          // an array to store the factors that will be multiplied with at the end
    double red_mat[10][10];                       // an array to store the reduced matrix to be put in the function again
    int sign[10] = {1,-1,1,-1,1,-1,1,-1,1,-1}; // an array to change the sign of the factors
    long long ans_arr[10] = {0} ;              //an array to store the answers and try to avoid the error  
    int f;                                     // detrmines we are in the which factor

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
                ans_arr[f] = (factors[f] * det(red_mat,dim -1)); // ERROR (FIXED): Not working adding 2 times after completing the 3x3 matrix of the first 4x4
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

/**
 * @brief A function to round to the nearnest integer
 * 
 * @param x The decimal to be rounded
 * @return int Returning the integer 
 */
double round(double x){

    int ten= (x*10);
    int tenth = ten % 10;
    int y;

    if (x>=0){
        if (tenth<5)
            y =x;
        else
            y = ++x;
    }
    else{

       if ((tenth) <=-5)
            y= --x;
       else
            y=x;
    }
    return y;
}

/**
 * @brief A function to get the inverse of a matrix using determinants and Matrix of minors and then divide by it
 * 
 * @param div The matrix to be divided by at the end when we get the inverse
 * @param mat The matrix to be inversed
 * @param dim The dimensions of the matrix
 * @param rA The rows of the div matrix
 * @param cB The columns of the div matrix 
 * @return void It will print the division matrix directly 
 */
void Division(double div[][10], int rA, int cA, double mat[][10], int dim){

    double minor[10][10];                   //  A matrix of minors
    double minor_ad[10][10];                // A matrix of adjugated minors
    double determinant_mat = det(mat, dim); //The determinant of the matrix
    double deter[10][10];                         //  A matrix to calculate the determinant of
    int m = 0, n = 0, o = 0, p = 0;                   //counters
    double inverse[10][10];                    //The inverse of the matrix
    double cofactor[10][10];             // A cofactor matrix


    // the inverse of 2x2 matrix (Lazy Way)
    if(dim == 2){
        inverse[0][0] = mat[1][1]/determinant_mat;
        inverse[0][1] = (mat[0][1]*-1)/determinant_mat;
        inverse [1][0] = (mat [1][0]*-1)/determinant_mat;
        inverse [1][1] = (mat[0][0])/determinant_mat;

    }
    else{


    //Tring to get the matrix of minors
    for (int i =0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            deter[10][10] = {0};
            n = 0;
            for (int k = 0; k < dim; k++){
                m = 0; 
                for(int l = 0; l < dim; l++){
                    if(k == i || l == j )
                        continue;
                    deter[n][m] = mat[k][l];
                    m++;                                                
                }
                if(k != i)
                    n++; 
            }
            minor[i][j] = det(deter, dim -1);
            ans = 0; ans1 = 0; ans2 = 0; // resetting for the determinant function (Stupid Impletaion) 
        }
    }

    //Cofactor matrix implemtation

    for (int a = 0; a < 10; a++){
        for(int b=0; b < 10; b++){
            if (a % 2 ==0){
                if (o % 2 == 0)
                    cofactor[a][b] = 1;
                else
                    cofactor[a][b] = -1;
                o++;}
            else {
                if (p % 2 == 0)
                    cofactor[a][b] = -1;
                else
                    cofactor[a][b] = 1;
                p++;
            }

        }
    }


    for (int y = 0; y < dim; y++){
        for(int z=0; z < dim; z++){
                minor[y][z] = minor[y][z]*cofactor[y][z];
        }
    }

    //Getting the adjucate of the matrix
    for(int c = 0; c < dim; c++){
        for(int d =0; d < dim; d++){
            minor_ad[c][d] = minor[d][c];
        }
    }

    for (int e = 0; e < dim; e ++){
        for(int f = 0; f < dim; f++){
            inverse[e][f] = (1.0/determinant_mat) * minor_ad[e][f];
        }
    }
    }

    //Performing the division
    Mult(div, inverse,rA, dim, cA, dim);
}

int main (){
    int rA, rB, cA, cB;
    int op;

    double matA [10][10];
    double matB [10][10];

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
            if (rB == cB &&  cA == rB && det(matB, rB) != 0)
                Division(matA, rA, cA, matB, rB);
            else
                cout << "The operation you chose is invalid for the given matrices.\n";
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