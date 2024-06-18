#include <iostream>
#include <vector>
using namespace std;

int countGoodPrefixes(const vector<int> &arr)
{
    long long prefixSum = 0, max = arr[0];
    int goodCount = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        prefixSum += arr[i];
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (prefixSum - max == max)
        {
            goodCount++;
        }
    }
    return goodCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        cout << countGoodPrefixes(arr) << endl;
    }

    return 0;
}
