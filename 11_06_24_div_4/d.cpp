#include <stdio.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define gc getchar_unlocked

#define fo(i, a, n, b) for (int i = a; i < n; i += b)
#define Fo(i, a, n, b) for (int i = a; i >= n; i -= b)

#define ll long long

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)

#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(x) printf("%s\n", s)

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

#define pb push_back
#define mp make_pair

#define F first
#define S second

#define all(x) x.begin(), x.end()
#define allr(a) a.rbegin(), a.rend()

#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define rvrs(a) reverse(all(a))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626

#define upb(a, x) (upper_bound(all(a), x) - a.begin())
#define lwb(a, x) (lower_bound(all(a), x) - a.begin())
#define mxel(a) (max_element(all(a)) - a.begin())
#define miel(a) (min_element(all(a)) - a.begin())

#define endl "\n"

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}

void find_center()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    vector<int> x_coords, y_coords;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '#')
            {
                x_coords.push_back(i + 1);
                y_coords.push_back(j + 1);
            }
        }
    }

    sort(x_coords.begin(), x_coords.end());
    sort(y_coords.begin(), y_coords.end());

    int center_x = x_coords[x_coords.size() / 2];
    int center_y = y_coords[y_coords.size() / 2];

    cout << center_x << " " << center_y << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t = 1;
    cin >> t;
    while (t--)
    {
        find_center();
    }

    return 0;
}
