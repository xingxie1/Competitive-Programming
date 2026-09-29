#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

unsigned seed;

unsigned rnd()
{
	unsigned ret=seed;
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return ret;
}

void solve()
{
    unsigned n,m,k;
    cin >> n >> m >> k >> seed;
    vvll a(n,vll(m));
    vvt c(m);
    vt vis(m);
    while (k--)
    {
        int op = rnd() % 2 + 1;
        if (op == 1) 
        {
            int i = (rnd() % m) + 1;
            int x = (rnd() % (n * m)) + 1;
            i--;
            if (vis[i]) 
            {
                while (!c[i].empty())
                {
                    int j = c[i].back();
                    c[i].pop_back();
                    a[j][i] = x;
                }
            }
            else 
            {
                vis[i] = 1;
                for (int j = 0;j < n;j++) a[j][i] = x;
            }
        }
        else 
        {
            int x = (rnd() % n) + 1;
            int y = (rnd() % m) + 1;
            x--;y--;
            if (a[x][y])
            {
                a[x][y] = 0;
                c[y].push_back(x);
            }
        }
    }
    ll ans = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            ans ^= a[i][j] * (i * m + j + 1);
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}