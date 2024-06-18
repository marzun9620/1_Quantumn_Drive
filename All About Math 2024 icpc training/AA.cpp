#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

long long find_lcm(const vector<int> &numbers)
{
    long long result = 1;
    for (int num : numbers)
    {
        result = lcm(result, num);
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string line;
        getline(cin, line);

        stringstream ss(line);
        int m;
        ss >> m;
        vector<int> numbers(m);
        for (int i = 0; i < m; ++i)
        {
            ss >> numbers[i];
        }

        cout << find_lcm(numbers) << endl;
    }

    return 0;
}
