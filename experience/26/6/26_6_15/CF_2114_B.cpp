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
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int c0 = 0,c1 = 0;
    for (int i = 0;i < n;i++) c0 += (s[i] == '0');
    c1 = n - c0;
    int mx = max(c1,c0);
    for (int i = 0;i <= min(mx,k);i += 2) 
    {
        int res = k - i / 2;
        if (c0 >= i && c1 >= 2 * res && c0 - i == c1 - 2 * res) 
        {
            YES;
            return ;
        }
        if (c1 >= i && c0 >= 2 * res && c1 - i == c0 - 2 * res) 
        {
            YES;
            return ;
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