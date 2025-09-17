/*
 Create a Matrix in C++ class that:
     1. Uses a parameterized constructor to dynamically allocate a 2D matrix of size r × c.
     2. Implements a copy constructor for deep copying.
     3. Uses a destructor to deallocate memory and print a message.
     4. Uses a static counter to track the number of active matrices.
 */

#include <bits/stdc++.h>
using namespace std;

class Matrix {
    static int active;

    public :
        int r, c;
        int **arr;

        Matrix (int r, int c) {
            this->r = r;
            this->c = c;
            active++;

            arr = new int* [r];
            for (int i = 0; i < r; i++) arr[i] = new int[c];

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    arr[i][j] = i + j;
                }
            }
        }

        Matrix (Matrix &dummy) {
            this->r = dummy.r;
            this->c = dummy.c;

            arr = new int* [r];
            for (int i = 0; i < r; i++) arr[i] = new int[c];

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    this->arr[i][j] = dummy.arr[i][j];
                }
            }
        }

        void print() {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }

        ~Matrix() {
            for (int i = 0; i < r; i++) delete[] arr[i];
            delete[] arr;
            active--;
            cout << "Destructor executes.\n";
        }

};
int Matrix :: active;

int main() {
    Matrix m1(2, 3);
    m1.print();

    Matrix m2(3, 4);
    m2.print();
}


