#include <bits/stdc++.h>
using namespace std;

long long calculateProfit(long long n, long long a, long long b, long long k)
{
    long long profit = k * b - k * (k - 1) / 2 + (n - k) * a;
    return profit;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, a, b;
        cin >> n >> a >> b;

        long long k = min(n, b);
        long long Mp = calculateProfit(n, a, b, k);

        if (a > b)
        {
            cout << n * a << endl;
        }
        else
        {
            long long start = 0, end = min(n, b);
            while (start <= end)
            {
                long long mid1 = start + (end - start) / 3;
                long long mid2 = end - (end - start) / 3;
                long long p = calculateProfit(n, a, b, mid1);
                long long p1 = calculateProfit(n, a, b, mid2);

                Mp = max(Mp, max(p, p1));

                if (p < p1)
                {
                    start = mid1 + 1;
                }
                else
                {
                    end = mid2 - 1;
                }
            }
            cout << Mp << endl;
        }
    }

    return 0;
}
