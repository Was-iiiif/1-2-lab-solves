/*Create a custom MyString class (similar to std::string) using dynamic memory.
• Constructor allocates memory for the string. Overload following operators:
    ➢ + → concatenate two strings. ➢ == → compare two strings
    ➢ [] → access a character at given index.
• Overload the << operator to print the string.*/

#include<bits/stdc++.h>
using namespace std;
class MyString{
    char *str;
    int length;
public:
    MyString()
    {
        length=0;
        str=new char[1];
        str[0]='\0';
    }
    MyString(const char *s)
    {
        length=strlen(s);
        str=new char[length+1];
        strcpy(str,s);
    }
    ~MyString()
    {
        delete[]str;
    }
    MyString operator +(MyString &s)
    {
        int l=length+s.length;
        char*NS=new char[l+1];
        strcpy(NS, str);
        strcat(NS,s.str);
        MyString temp(NS);
        strcpy(temp.str,NS);
        delete[]NS;
        return temp;
    }
    bool operator==(MyString s)
    {
        return strcmp(str,s.str)==0;
    }
    char &operator [](int pos)
    {
        return str[pos];
    }
    friend ostream &operator<<(ostream&, MyString&);
};
ostream &operator<<(ostream& output, MyString &s)
{
    output<<s.str;
    return output;
}
int main()
{
    MyString s1("CSE ");
    MyString s2("2k23");
    MyString s3=s1+s2;
    cout<<s1<<endl<<s2<<endl<<s3<<endl;
    (s1==s2)?cout<<"Equal"<<endl:cout<<"Not Equal"<<endl;
    cout<<s1[1]<<endl;
    s1[1]='p';
    cout<<"Modified string: "<<s1<<endl;
    return 0;


}
