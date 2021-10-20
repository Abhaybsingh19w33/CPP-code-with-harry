#include <iostream>
using namespace std;

struct structure
{
    int a;
    char b;
    float c;
} stru;

union uni
{
    int a;
    char b;
    float c;
};

int main()
{

    union uni shared;
    shared.a = 1;
    shared.b = 'a';
    shared.c = 1.1f;

    cout << shared.a << endl;
    cout << shared.b << endl;
    cout << shared.c << endl;

    enum data
    {
        a,
        b,
        c
    };
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    data d = a;
    cout << d << endl;
    return 0;
}