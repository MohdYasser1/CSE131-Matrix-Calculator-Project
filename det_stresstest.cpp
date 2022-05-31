#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

    long long ans = 0, ans1 = 0, ans2 = 0; // a global varible to store the final determinant used in determinant function


long long det_old(int mat[][10], int dim){
    
    int factors[10] ; // an array to store the factors that will be multiplied with at the end
    int red_mat[10][10]; // an array to store the reduced matrix to be put in the function again
    int sign[10] = {1,-1,1,-1,1,-1,1,-1,1,-1}; // an array to change the sign of the factors

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
        int f; // detrmines we are in the which factor
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
            ans += (factors[f] * det_old(red_mat, dim - 1)); // ERROR: Not working adding 2 times after completing the 3x3 matrix of the first 4x4

        }
        return ans;
    }

}


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
    for (int y = 0; y < dim + 1; y++)
        ans += ans_arr[y];
    if (f == (dim -1)){
        for (int y = 0; y < dim + 1; y++)
        ans2 += ans_arr[y];
        return ans2;
    }

    return ans;

}


int main(){
    srand((unsigned)time(0));
    int a[10][10], i ,j;

while (true){
    for( i = 0; i < 3; ++i)
        {for( j = 0;  j < 3; ++j)
        {a[i][j] = (rand() % 200) - 100;}
        }

    for( i = 0; i < 3; ++i)
        {for( j = 0; j < 3; ++j)
        cout<<a[i][j]<<'\t';
        cout<<'\n';
        }
    long long x,y;
    x= det_old(a, 3);
    ans =0;
    y = det(a, 3);
    ans =0;
    cout << x << '\t' << y << '\n';
    if (x == y)
       { cout << "correct";}
    else {
        cout << "WRONG!!!!";
        break;
    } 

}

}
