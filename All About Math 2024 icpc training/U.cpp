#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long max_possible_gcd(long long N, vector<long long> &A)
{
    if (N == 1)
    {
        return 1000000000;
    }

    vector<long long> prefix_gcd(N);
    prefix_gcd[0] = A[0];
    for (long long i = 1; i < N; ++i)
    {
        prefix_gcd[i] = gcd(prefix_gcd[i - 1], A[i]);
    }

    vector<long long> suffix_gcd(N);
    suffix_gcd[N - 1] = A[N - 1];
    for (long long i = N - 2; i >= 0; --i)
    {
        suffix_gcd[i] = gcd(suffix_gcd[i + 1], A[i]);
    }

    long long max_gcd = 0;
    for (long long i = 0; i < N; ++i)
    {
        long long current_gcd;
        if (i == 0)
        {

            current_gcd = suffix_gcd[1];
        }
        else if (i == N - 1)
        {

            current_gcd = prefix_gcd[N - 2];
        }
        else
        {

            current_gcd = gcd(prefix_gcd[i - 1], suffix_gcd[i + 1]);
        }
        max_gcd = max(max_gcd, current_gcd);
    }

    return max_gcd;
}

int main()
{
    long long N;
    cin >> N;
    vector<long long> A;
    for (int i = 0; i < N; i++)
    {
        long long x;
        cin >> x;
        A.push_back(x);
    }
    cout << max_possible_gcd(N, A) << endl;

    return 0;
}
