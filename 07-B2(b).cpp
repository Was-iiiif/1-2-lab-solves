/*2. Create a class Product with private members:
(int product_id, string product_name, and float price)
Use a parameterized constructor to initialize these attributes. Write a program that:

Takes input for 5 products from the user.

Stores all details in a text file product.txt (each record in a new line, formatted as product_id product_name price).

Reopens the file, reads all records, and displays only those products whose price is below 500.*/

#include<bits/stdc++.h>
using namespace std;
class Product{
    int id;
    string name;
    float price;
public:
    Product(int a, string b, float c):id(a), name(b), price(c){}
    void write(ofstream &p)
    {
        p<<id<<" "<<name<<" "<<price<<endl;
    }
};
int main()
{
    ofstream fout("product.txt");
    cout<<"Enter info of 5 product"<<endl;
    for(int i=0; i<5; i++)
    {
        int id;
        string name;
        float price;
        cin>>id>>name>>price;
        Product p(id, name, price);
        p.write(fout);
    }
    fout.close();
    ifstream fin("product.txt");
    int id;
    string name;
    float price;
    while(fin>>id>>name>>price)
    {
        if(price<500)
            cout<<id<<" "<<name<<" "<<price<<endl;
    }
}

