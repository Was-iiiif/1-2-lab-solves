/*Create a Matrix in C++ class that:
Uses a parameterized constructor to dynamically allocate a 2D matrix of size r × c.
Implements a copy constructor for deep copying.
Uses a destructor to deallocate memory and print a message.
Uses a static counter to track the number of active matrices.*/

#include<bits/stdc++.h>
using namespace std;
class Matrix{
    int **mat;
    int row;
    int col;
    static int count_mat;
public:
    Matrix(int a, int b)
    {
        row=a;
        col=b;
        mat=new int *[row];
        for(int i=0; i<row; i++)
            mat[i]=new int[col];
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                mat[i][j]=0;
            }
        }
        count_mat++;
        cout<<"Matrix Created"<<endl<<"Active Matrix count: "<<count_mat<<endl;

    }
    Matrix(Matrix &x)
    {
        row=x.row;
        col=x.col;
        mat=new int *[row];
        for(int i=0; i<row; i++)
            mat[i]=new int[col];
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                mat[i][j]=x.mat[i][j];
            }
        }
        count_mat++;
        cout<<"Copy Matrix Created"<<endl<<"Active Matrix count: "<<count_mat<<endl;
    }
    ~Matrix()
    {
        for(int i=0; i<row; i++)
            delete[]mat[i];
        delete[]mat;
        count_mat--;
        cout<<"Matrix Deleted"<<endl<<"Active Matrix count: "<<count_mat<<endl;
    }
    void input()
    {
        cout<<"Enter elements:"<<endl;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            cin>>mat[i][j];
    }
    void display()
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int Matrix::count_mat=0;
int main()
{
    int r,c;
    cout<<"Enter row and col:"<<endl;
    cin>>r>>c;
    Matrix m1(r,c);
    m1.input();
    m1.display();
    Matrix m2(m1);
    m2.display();

}

