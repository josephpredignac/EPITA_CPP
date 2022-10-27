#include <iostream>
using namespace std;

long long sqrt(long long n){
    long long i = 0;
    while(i * i < n)
        i++;
    return i; 
}

bool isPrime(long long n)
{
    long long root = sqrt(n);
    if (n == 0 || n == 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0)
        return false;
    for (long long i = 5; i <= root; i+=2)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    long long n;
    while (cin >> n)
    {
        if (isPrime(n))
            cout << n  << " is a prime: True\n";
        else
            cout << n << " is a prime: False\n"; 
    }
    return 0;
}
