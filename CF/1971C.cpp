#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, flag = 0;
        cin >> a >> b >> c >> d;

        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);

        sort(v.begin(), v.end());
        for (int i = 0; i < 2; i++)
        {
            if ((v[i] == a && v[i + 2] == b) || (v[i] == b && v[i + 2] == a))
            {
                cout << "YES" << endl;
                flag = 1;
                break;
            }
            if ((v[i] == c && v[i + 2] == d) || (v[i] == d && v[i + 2] == c))
            {
                cout << "YES" << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}