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

void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n),b(m);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) cin >> b[i];
    if (n < m) 
    {
        NO;
        return ;
    }
    ranges::sort(a);
    ranges::sort(b);
    if (n == m && a != b) 
    {
        NO;
        return ;
    }
    int i = 0,j = 0;
    vt c,d;
    for (int j = 0;j < m;j++)
    {
        while (i < n && a[i] < b[j]) 
        {
            c.push_back(a[i]);
            i++;
        }
        if (i < n && a[i] == b[j]) 
        {
            i++;
        }
        else d.push_back(b[j]);
    }
    while (i < n) c.push_back(a[i++]);
    if (c.size() < 2 * d.size()) 
    {
        NO;
        return ;
    }
    int N = d.size();
    for (int j = 0;j < N;j++)
    {
        auto r = c.end() - ranges::lower_bound(c,d[j]);
        auto l = ranges::lower_bound(c,d[j]) - c.begin();
        if (l < j + 1 || N - j > r)
        {
            NO;
            return ;
        }
    }
    YES;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}