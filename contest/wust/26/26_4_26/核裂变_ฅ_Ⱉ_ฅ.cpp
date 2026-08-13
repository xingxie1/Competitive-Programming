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
    int a,b,c;
    cin >> a >> b >> c;
    set<pii> aa,cc;
    for (int i = 1;i <= sqrt(a);i++)
    {
        if (a % i == 0) 
        {
            int mn = min(i,a / i);
            int mx = max(i,a / i);
            aa.insert({mn,mx});
            mn = min(-i,-a / i);
            mx = max(-i,-a / i);
            aa.insert({mn,mx});
        }
    }
    for (int i = 1;i <= sqrt(-a);i++)
    {
        if (a % i == 0) 
        {
            int mn = min(i,a / i);
            int mx = max(i,a / i);
            aa.insert({mn,mx});
            mn = min(-i,-a / i);
            mx = max(-i,-a / i);
            aa.insert({mn,mx});
        }
    }
    if (c == 0)
    {
        cout << a << " " << b << " " << 1 << " " << 0 << endl;
        return ;
    }
    for (int i = 1;i <= sqrt(c);i++)
    {
        if (c % i == 0) 
        {
            int mn = min(i,c / i);
            int mx = max(i,c / i);
            cc.insert({mn,mx});
            mn = min(-i,-c / i);
            mx = max(-i,-c / i);
            cc.insert({mn,mx});
        }
    }
    for (int i = 1;i <= sqrt(-c);i++)
    {
        if (c % i == 0) 
        {
            int mn = min(i,c / i);
            int mx = max(i,c / i);
            cc.insert({mn,mx});
            mn = min(-i,-c / i);
            mx = max(-i,-c / i);
            cc.insert({mn,mx});
        }
    }
    for (auto& [a1,a2] : aa)
    {
        for (auto& [c1,c2] : cc)
        {
            // cout << a1 << " " << a2 << " " << c1 << " " << c2 << endl;
            if (1LL * a1 * c2 + 1LL * a2 * c1 == b) 
            {
                cout << a1 << " " << c1 << " " << a2 << " " << c2 << endl;
                return ;
            }
            if (1LL * a1 * c1 + 1LL * a2 * c2 == b)
            {
                cout << a1 << " " << c2 << " " << a2 << " " << c1 << endl;
                return ;
            }
        }
    }
    NO;
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