#include <bits/stdc++.h>

using namespace std;

int count_pairs(int A, int B)
{

    if (B % A != 0)
    {
        return 0;
    }

    int C = B / A;
    int count = 0;

    for (int k = 1; k <= sqrt(C); ++k)
    {
        if (C % k == 0)
        {
            int m = C / k;
            if (__gcd(k, m) == 1)
            {
                count += 2;
                if (k == m)
                {
                    count -= 1;
                }
            }
        }
    }

    return count;
}

int main()
{
    int A, B;
    cin >> A >> B;

    cout << count_pairs(A, B) << endl;

    return 0;
}
