// This logic causes Timeout error in some test cases.

#include <iostream>


using namespace std;

bool check_multiple_5(int number)
{
    bool ret = true;
    if (number < 10)
    {
        if (number != 5)
            ret = false;
    }
    else
    {
        int rem = number % 10;
        if ((rem != 0) && (rem != 5))
            ret = false;
    }

    return ret;
}

bool check_divisibility_3(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }

    if ((sum % 3) == 0)
        return true;
    else
        return false;
}

int return_divisibility_sums(int last_number)
{
    int sum = 0;
    bool div_by_3, div_by_5;
    for (int i = 1; i< last_number; i++)
    {
        div_by_3 = check_divisibility_3(i);
        div_by_5 = check_multiple_5(i);
        if (div_by_3 || div_by_5)
            sum += i;
    }
    return sum;
}

int main(){
    int t;
    cin >> t;

    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        cout << return_divisibility_sums(n) << endl;
    }
    return 0;
}