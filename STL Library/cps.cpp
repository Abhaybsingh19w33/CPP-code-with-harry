//recursion function - jb ek function apne aap ko call krta he.. EX- FACTORIAL KA LETE

#include <iostream>
using namespace std;

int factorial(int n)
{
  if (n == 4)
  {
    return 6;
  }

  cout << n << endl;
  if (n <= 1)
  {
    return 1;
  }

  return n * factorial(n - 1);
}

int main()
{

  int hiren;
  // cout << "Finding Factorial For Value: " << endl;
  // cin >> hiren;
  hiren = 4;

  cout << "Factorial Of " << hiren << " Is: " << factorial(hiren) << endl;
}