#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    map<int,vt> p;
    vt a(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        p[a[i]].push_back(i + 1);
    }
    if (p.size() == 1) 
    {
        NO;
        return ;
    }
    int st = p.begin()->se[0];
    vvt g(n + 1);
    for (auto it = ++p.begin();it != p.end();it++)
    {
        for (int x : it->se) g[st].push_back(x);
    }
    int ed = (--(p.end()))->se[0];
    for (int i = 1;i < p.begin()->se.size();i++) 
    {
        int x = p.begin()->se[i];
        g[ed].push_back(x);
    }
    YES;
    for (int i = 1;i <= n;i++) 
    {
        for (int x : g[i]) cout << i << " " << x << endl;
    }


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}