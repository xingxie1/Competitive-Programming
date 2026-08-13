#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,x;
    cin >> n >> x;
    ll ans = 0;
    set<int> st;
    ll t = n + x - 2;
    for (ll p = 1;p * p <= t;p++) 
    {
        if (t % p == 0) 
        {
            if (p % 2 == 0) 
            {
                ll k = p / 2 + 1;
                if (k > 1 && k >= x) st.insert(k);
            }
            ll p2 = t / p;
            if (p2 % 2 == 0) 
            {
                ll k = p2 / 2 + 1;
                if (k > 1 && k >= x) st.insert(k);
            }
        }
    }
    t = n - x;
    for (ll p = 1;p * p <= t;p++) 
    {
        if (t % p == 0) 
        {
            if (p % 2 == 0) 
            {
                ll k = p / 2 + 1;
                if (k > 1 && k >= x) st.insert(k);
            }
            ll p2 = t / p;
            if (p2 % 2 == 0) 
            {
                ll k = p2 / 2 + 1;
                if (k > 1 && k >= x) st.insert(k);
            }
        }
    }
    cout << st.size() << endl;
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