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
    int n,m;
    cin >> n >> m;
    vt a(n),x(m);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) cin >> x[i];
    mset<int> st1,st2;
    ll sum = accumulate(a.begin(),a.end(),0LL);
    for (int i = 0;i < n;i++) 
    {
        if (i % 2 == 0) st1.insert(a[i]);
        else st2.insert(a[i]);
    }
    int f1 = 0,f2 = 0;
    for (int i = 0;i < m;i++)
    {
        if ((x[i] - 1) % 2 == 0) 
        {
            if (st1.empty()) continue;
            ll mx = *(--st1.end());
            if (mx < 0 && f1) continue;
            f1 = 1;
            sum -= mx;
            st1.erase(st1.find(mx));
        }
        else 
        {
            if (st2.empty()) continue;
            ll mx = *(--st2.end());
            if (mx < 0 && f2) continue;
            f2 = 1;
            sum -= mx;
            st2.erase(st2.find(mx));
        }
    }
    cout << sum << endl;
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