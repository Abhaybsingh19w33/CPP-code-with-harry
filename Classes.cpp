#include <iostream>
using namespace std;
class Employee
{
private:
    int a, b, c;

public:
    int d, e;
    void setData(int a, int b, int c);
    // functions can be declare here, but the definitioon can be writteen anywhere eles
    void getData()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
        cout << "The value of d is " << d << endl;
        cout << "The value of e is " << e << endl;
    }
};

// nesting of member functions
class binary
{
    // By default, all members of a class are private if you don't specify an access specifier:
    string s;

public:
    void read(void);
    void chk_bin(void);
    void ones(void);
    void display(void);
private :
    void thisIsPrivateFunction(void);
};

void binary :: thisIsPrivateFunction(void) {
    cout << "This is a private function and can't be called directly";
}
void binary::read(void)
{
    cout << "Enter a binary number: ";
    cin >> s;
}

void binary ::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrectly binary format : " << endl;
            exit(1);
        }
    }

    cout << s << " is in binary format." << endl;
}

void binary ::ones(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else if (s.at(i) == '1')
        {
            s.at(i) = '0';
        }
    }
}

void binary ::display(void)
{
    thisIsPrivateFunction();
    cout << s << endl;
}

void Employee::setData(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}

int main()
{
    // Employee Abhay;
    // Abhay.setData(1, 2, 3);
    // Abhay.getData();
    // Abhay.d = 4;
    // Abhay.e = 5;
    // Abhay.getData();

    binary b;
    b.read();
    b.chk_bin();
    b.ones();
    // b.chk_bin();
    b.display();
    // b.thisIsPrivateFunction(); // error
    return 0;
}