#include <cmath>
#include <iostream>
using namespace std;


long sum_divisors(long n, int divisor)
{ /*count natural numbers i the range of n that are divisible by the divisor */ 
long counter = floor(n-1)/divisor;
return (counter *((counter + 1)*divisor))/2; //sum of the numbers 
}

int main()
{
    int t;
    cin >> t;

    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        cin >> n;
        cout << sum_divisors(n, 3) + sum_divisors(n, 5) - sum_divisors(n, 15) << endl;
    }
    return 0;
}