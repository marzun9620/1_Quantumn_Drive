#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int main()
{
    long long N;
    bool flag = false;

    cin >> N;
    long long arr[N];

    for (long long i = 0; i < N; i++)
    {
        cin >> arr[i];
        if ((pow(static_cast<long long>(sqrt(arr[i])), 2)) == arr[i])
        {
            if (isPrime(sqrt(arr[i])))
            {
                cout << "YES" << endl;
                flag = true;
            }
        }
        if (!flag)
        {
            cout << "NO" << endl;
        }
        flag = false;
    }

    return 0;
}
