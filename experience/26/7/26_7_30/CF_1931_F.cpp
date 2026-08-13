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
    int n, k;
    cin >> n >> k;
    vvt a(k,vt(n));
    vvt g(n + 1);
    vt deg(n + 1);
    for (int i = 0;i < k;i++) 
    {
        for (int j = 0;j < n;j++) 
        {
            cin >> a[i][j];
            if (j > 1) 
            {
                g[a[i][j - 1]].push_back(a[i][j]);
                deg[a[i][j]]++;
            }
        }
    }
    vt ans;
    queue<int> q;
    for (int i = 1;i <= n;i++) 
    {
        if (!deg[i]) q.push(i);
    }
    while (!q.empty()) 
    {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for (int y : g[x])
        {
            deg[y]--;
            if (!deg[y]) q.push(y);
        }
    }
    if (ans.size() < n) NO;
    else YES;    
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