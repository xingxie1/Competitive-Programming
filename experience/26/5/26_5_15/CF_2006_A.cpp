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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    int n;
    cin >> n;
    vvt g(n);
    for (int i = 1;i < n;i++) 
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s;
    cin >> s;
    int c0 = 0,c1 = 0,cq = 0,mq = 0;
    for (int i = 2;i <= n;i++) 
    {
        if (g[i - 1].size() == 1)
        {
            c0 += (s[i - 1] == '0');
            c1 += (s[i - 1] == '1');
            cq += (s[i - 1] == '?');
        }
        else 
        {
            mq += (s[i - 1] == '?');
        }
    }
    if (s[0] == '0') cout << c1 + (cq + 1) / 2 << endl;
    else if (s[0] == '1') cout << c0 + (cq + 1) / 2 << endl;
    else 
    {
        if (c0 != c1) cout << max(c0,c1) + cq / 2 << endl;
        else cout << c0 + (cq + mq % 2) / 2 << endl;
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