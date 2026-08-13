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
// const int MOD = 998244353;
//const int MOD = (int)1e9+7;

ll qpow(ll a, int b) 
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll k;
    cin >> k;
    if (k == 1) 
    {
        cout << "codeforces" << endl;
        return ;
    }
    string s = "codeforces";
    int f = 0;
    for (ll i = 2;;i++) 
    {
        if (qpow(i,10) >= k) 
        {
            for (int j = 0;j <= 9;j++) 
            {
                if (1LL * qpow(i,j) * qpow(i - 1,10 - j) < k && 1LL * qpow(i,j + 1) * qpow(i - 1,9 - j) >= k) 
                {
                    int c0 = j + 1,c1 = i;
                    string ans;
                    for (int ii = 0;ii < c0;ii++) 
                    {
                        for (int jj = 0;jj < i;jj++) ans += s[f];
                        f++;
                    }
                    for (int ii = 0;ii < 10 - c0;ii++) 
                    {
                        for (int jj = 0;jj < i - 1;jj++) ans += s[f];
                        f++;
                    }
                    cout << ans << endl;
                    return ;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}