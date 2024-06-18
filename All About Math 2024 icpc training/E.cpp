#include <bits/stdc++.h>
#include <utility>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> numbers(1000);
    for (int i = 1; i <= 1000; ++i)
    {
        cin >> numbers[i];
    }
    set<pair<int, int>> mySet;
    for (ll n : numbers)
    {
        ll count = 0;
        ll sqrt_n = sqrt(n);
        for (ll i = 1; i <= sqrt_n; ++i)
        {
            if (n % i == 0)
            {
                if (i * i == n)
                {
                    count += 1;
                }
                else
                {
                    count += 2;
                }
            }
            mySet.insert(make_pair(n, count));
        }
    }
    auto it = mySet.begin();
    advance(it, n - 1);
    cout << it->first << endl;
    return 0;
}
