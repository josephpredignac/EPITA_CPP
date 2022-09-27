#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n == 0 || n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i < n; i+=2)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (isPrime(n))
            cout << n  << " is a prime: True\n";
        else
            cout << n << " is a prime: False\n"; 
    }
    return 0;
}
