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
    string s;
    cin >> s;
    int m,n = s.size();
    cin >> m;
    string l,r;
    cin >> l >> r;
    string t;
    vvt p(10,vt());
    for (int i = 0;i < n;i++)
    {
        int x = s[i] - '0';
        p[x].push_back(i);
    }
    int flag = 0,mx = -1;
    for (int i = 0;i < m;i++)
    {
        int nmx = 0;
        for (char c = l[i];c <= r[i];c++)
        {
            auto it = ranges::upper_bound(p[c - '0'],mx);
            if (it == p[c - '0'].end())
            {
                flag = 1;
                break;
            }
            nmx = max(nmx,*it);
        }
        if (flag) break;
        mx = nmx;
    }
    if (!flag) cout << "NO" << endl;
    else cout << "YES" << endl;
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