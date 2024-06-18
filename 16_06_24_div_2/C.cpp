#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;

        long long max_manhattan = (n * (n - 1)) / 2;
        if (n % 2 == 0)
        {
            max_manhattan += 2;
        }
        else
        {
            max_manhattan += 1;
        }

        if (k > max_manhattan)
        {
            cout << "No" << endl;
            continue;
        }

        // If k <= max_manhattan, it's possible to construct such a permutation
        vector<int> permutation(n);
        for (int i = 0; i < n; ++i)
        {
            permutation[i] = i + 1; // Start with sorted permutation [1, 2, ..., n]
        }

        // To achieve Manhattan value k, swap adjacent elements
        // Keep swapping until the Manhattan value reaches k
        int left = 0, right = n - 1;
        while (k > 0 && left < right)
        {
            if (k >= (right - left))
            {
                swap(permutation[left], permutation[right]);
                k -= (right - left);
                ++left;
                --right;
            }
            else
            {
                swap(permutation[left], permutation[left + k]);
                k = 0; // We achieved the desired Manhattan value k
            }
        }

        // Output the result
        if (k == 0)
        {
            cout << "Yes" << endl;
            for (int i = 0; i < n; ++i)
            {
                cout << permutation[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

int main()
{
    solve();
    return 0;
}
