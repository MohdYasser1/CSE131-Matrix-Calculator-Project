# CSE131-Matrix-Calculator-Project
 This is a matrix calculator that can preform simple operations on two matrices

 The github repository : https://github.com/MohdYasser1/CSE131-Matrix-Calculator-Project

## Day 1:
Initialized the matrices and implemented how to take them from the user.

### Done:
 - how to take the dimensions of both matrices.
 - how to enter the values of both matrices.
 - the message to choose the operation and the quitting message.

### ToDo:
- Function for Adding/Subracting two matrix.
- A case system to take the operation and get it to the function.

### New Varibles:
- rA (int) : row of matrix A
- rB (int) : row of matrix B
- cA (int) : column of Matrix A
- cB (int) : column of Matrix B
- MatA (array of int) : An array that holds the values of Matrix A
- MatB (array of int) : An array that holds the values of Matrix B
---

## Day 2:
Finished 3 funtions which adds, subtracts and multiplies 2 matrices.

### Problems Finished
1. Problem A ✅
2. Problem B ✅
3. Problem C ✅
4. Problem D
5. Problem E
6. Problem F
7. Problem G
8. Problem H
9. Problem I

#### Done:
- A function that adds 2 matrices
- A function that subtracts 2 matrices
- A function that multiply 2 matrices
- Case system that directs to each of the funtion
- Fail system if the the operation isn't allowed on the given dimensions

### ToDo:
- Learn how to get the determinant of matrix of different dimentions
- A function that gets the determinant of a matrix

### New Variables

**Add (function):** A functions that adds 2 matrices of the same dimention and then display the sum on the screen.

<u>Takes:</u>
- A (array): The first matrix
- B (array): The second matrix
- row (int): The numbers of rows of one of the 2 matrices(as the number of rows of both are the same).
- col (int): The numbers of columns of one of the 2 matrices(as the number of columns of both are the same).

add (array): An array that stors the sum of the two matrices to be later printed of the screen

**Sub (function):** A functions that adds 2 matrices of the same dimention and then displays the diffrence on the screen.

<u>Takes:</u>
- A (array): The first matrix
- B (array): The second matrix
- row (int): The numbers of rows of one of the 2 matrices(as the number of rows of both are the same).
- col (int): The numbers of columns of one of the 2 matrices(as the number of columns of both are the same).

sub (array): An array that stors the diffrence of the two matrices to be later printed of the screen

**Mult (funtion):** A function that multiplies 2 matrices if the dimentions accepts for multiplication and displays the product matrix on the screen.

<u>Takes:</u>
- A (array): The first matrix
- B (array): The second matrix
- rA (int) : row of matrix A
- rB (int) : row of matrix B
- cA (int) : column of Matrix A
- cB (int) : column of Matrix B

sum (int): A varible to display each cell of the matrix which represents the sum of products to be then displayed on the screen.

---

## Day 3:
Started with the determinant function but having problems with a matrix bigger than 3x3. The idea of the function that it takes the large matrix and bring the determinant of smaller matrix till it reaches to a 2x2 matrix which then it caculates it easily. The problem is when I am trying a 4x4 matrix and it finishes the first 3x3 it adds ans twice.

### Problems Finished
1. Problem A ✅
2. Problem B ✅
3. Problem C ✅
4. Problem D ✅
5. Problem E
6. Problem F
7. Problem G
8. Problem H
9. Problem I

### Done:
- Learned how to bring the determinant of any matrix
- Learned how to bring the inverse of a 2x2 matrix
- Started on the determinant function

### ToDo:
- Fix the determinant function
- Learn how to bring the inverse of any matrix
- Try to start the inverse function

### New varibles:
The new varibles will be explained on the code because the number of varibles became huge 😅

---

## Final Day
Had A few days trying to solve the determinant function and finally was able to find and fix the problem.The problem was that the determinant wasnt working on the 10x10 matrix as there was a for loop which went on an extra loop on the 10 x 10 matrix. I have also leared how to find the inverse of a matrix and was able to implement it to the program. It was an exiting journey and learned alot from it. I mainly leared how to effiectivly debug a program as the debuging in this program was hard because of its may steps. This project have motivated me to do more personal project to add to my resume.

### Problems Finished
1. Problem A ✅
2. Problem B ✅
3. Problem C ✅
4. Problem D ✅
5. Problem E ✅
6. Problem F ✅
7. Problem G ✅
8. Problem H ✅
9. Problem I ✅

### New file
-det_stresstest: This cpp file was made to stress test the determinant function by comparing it to the old derminant function and trying to find which test case will it stop at


-Fixed the name of the project to matrix.-project.cpp