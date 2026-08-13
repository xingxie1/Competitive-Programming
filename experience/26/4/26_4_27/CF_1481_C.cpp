#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
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
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n),b(n),c(m);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    for (int i = 0;i < m;i++) cin >> c[i];
    map<int,vt> p;
    for (int i = 0;i < n;i++)
    {
        if (a[i] != b[i])
        {
            p[b[i]].push_back(i);
        }
    }
    vt ans(m);
    int f = -1;
    for (int i = 0;i < n;i++)
    {
        if (a[i] != b[i] && b[i] == c[m - 1]) 
        {
            f = i;
            break;
        }
    }
    if (f == -1)
    {
        for (int i = 0;i < n;i++)
        {
            if (b[i] == c[m - 1]) 
            {
                f = i;
                break;
            }
        }
    }
    if (f == -1) 
    {
        NO;
        return ;
    }

    for (int i = 0;i < m;i++)
    {
        if (p.count(c[i])) 
        {
            ans[i] = p[c[i]].back();
            a[ans[i]] = c[i];
            p[c[i]].pop_back();
            if (p[c[i]].size() == 0) p.erase(c[i]);
        }
        else 
        {
            ans[i] = f;
            a[f] = c[i];
        }
    }
    for (int i = 0;i < n;i++) 
    {
        if (a[i] != b[i]) 
        {
            NO;
            return ;
        }
    }
    YES;
    for (int x : ans) cout << x + 1 << " ";
    cout << endl;
    
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