/*Create a MemoryBlock class in c++:
The constructor allocates a dynamic memory block of size n.
A static variable tracks the total allocated memory across all objects.
Use the destructor to free memory and update total usage.
Include a static function showMemoryUsage() to display the current total memory.*/
#include<bits/stdc++.h>
using namespace std;
class MemoryBlock{
    int *block;
    int s;
    static int total;
public:
    MemoryBlock(int n)
    {
        s=n;
        block=new int[s];
        total+=s*sizeof(int);
        cout<<"Memory block successfully created"<<endl;


    }
    ~MemoryBlock()
    {
        delete[]block;
        total-=s*sizeof(int);
        cout<<"Memory block successfully deleted"<<endl<<"Current size: "<<total<<" Bytes"<<endl;
    }
    static void showMemoryUsage()
    {
        cout<<"Memory consumption:"<<endl<<"Total memory: "<<total<<" Bytes"<<endl;
    }
};
int MemoryBlock::total=0;

int main()
{

    int a,b;
    cout<<"Enter size of 2 memory blocks:"<<endl;
    cin>>a>>b;
    MemoryBlock m1(a);
    MemoryBlock::showMemoryUsage();
    m1.showMemoryUsage();
    MemoryBlock m2(b);
    m2.showMemoryUsage();

}

