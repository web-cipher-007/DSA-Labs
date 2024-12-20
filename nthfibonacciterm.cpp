//Nth order fibonacci series

#include <iostream>
#include <cmath>
using namespace std;

long long fibonacci(int n)
{
    const double sqrt5 = sqrt(5);
    const double phi = (1 + sqrt5) / 2;
    const double psi = (1 - sqrt5) / 2;
    return round((pow(phi, n-1) - pow(psi, n-1)) / sqrt5);
}

int main()
{
    int n;
    cout << "Enter the term number (n): ";
    cin >> n;
    if(n<1)
        {
          cout<<"Enter only positive integer"<<endl;
          return 1;
        }
    else
    cout << "The " << n << "th Fibonacci term is: " << fibonacci(n) << endl;
    return 0;
}
