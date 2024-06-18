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

void nahar_marjana()
{
    ll a, b, c;
    cin >> a >> b >> c;

    set<ll> divisors;

    for (ll i = 1; i <= sqrt(c); ++i)
    {
        if (c % i == 0)
        {

            divisors.insert(i);

            if (i != c / i)
            {
                divisors.insert(c / i);
            }
        }
    }
    auto itLower = divisors.upper_bound(a-1);
    auto itUpper = divisors.lower_bound(b+1);

    ll count = distance(itLower, itUpper);
    cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t = 1;
    // cin >> t;
    while (t--)
    {
        nahar_marjana();
    }

    return 0;
}