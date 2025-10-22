/*2. A global financial analytics system integrates data from multiple currency and taxation modules under one transaction processing framework. Write a C++ program where the base class Transaction stores the transaction ID and base amount. Two classes, Currency_Module and Tax_Module, derive from Transaction to handle currency conversion (e.g., USD ↔ EUR) and tax computation (e.g., VAT, GST) respectively.
Further, two specialized classes, Currency_Converter (from Currency_Module) and Tax_Processor (from Tax_Module), process dynamic exchange rates and regional tax percentages for accurate financial adjustments. Finally, a class Final_Statement inherits from both Currency_Converter and Tax_Processor.
Use parameterized constructors in all classes to initialize data, print messages showing the constructor calling order.*/

#include<bits/stdc++.h>
using namespace std;
class Transaction{
protected:
    int id;
    double base;
public:
    Transaction(int a, double b):id(a), base(b)
    {
        cout<<"Transaction called"<<endl;
    }
};
class Currency_Module: virtual public Transaction{
protected:
    string from,to;
public:
    Currency_Module(int a, double b, string c, string d):Transaction(a,b), from(c), to(d)
    {
        cout<<"Currency_Module called"<<endl;
    }
};
class Tax_Module: virtual public Transaction{
protected:
    double taxRate;
public:
    Tax_Module(int a, double b, double e):Transaction(a,b), taxRate(e)
    {
        cout<<"Tax_Module called"<<endl;
    }
};
class Currency_Converter: public Currency_Module{
protected:
    double rate;
public:
    Currency_Converter(int a, double b, string c, string d, double f):Transaction(a,b), Currency_Module(a,b,c,d), rate(f)
    {
        cout<<"Currency_Converter called"<<endl;
    }
};
class Tax_Processor: public Tax_Module{
protected:
    string region;
public:
    Tax_Processor(int a, double b, double e, string g):Transaction(a,b), Tax_Module(a,b,e), region(g)
    {
        cout<<"Tax_Processor called"<<endl;
    }
};
class Final_Statement: public Currency_Converter, public Tax_Processor{
public:
    Final_Statement(int a, double b, string c, string d, double e, double f, string g):Transaction(a,b), Currency_Converter(a,b,c,d,f), Tax_Processor(a,b,e,g)
    {
        cout<<"Final Statement called"<<endl;
    }
    void display()
    {
        cout << "\n--- Final Statement ---" << endl;
        cout << "Transaction ID: " << id  << endl;
        cout << "Base Amount: " << base << endl;
        cout << "Currency: " << from << " -> " << to << endl;
        cout << "Exchange Rate: " << rate << endl;
        cout << "Tax Rate: " << taxRate << "%" << endl;
        cout << "Region: " << region << endl;
    }
};
int main()
{
    int a;
    string c,d,g;
    double b,e,f;
    cout<<"Enter info: "<<endl;
    cin>>a>>b>>c>>d>>e>>f>>g;
    Final_Statement m(a,b,c,d,e,f,g);
    m.display();
    return 0;
}
