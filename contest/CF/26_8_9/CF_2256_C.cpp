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
    string s;
    cin >> s;
    s += s;
    int jj = 0;
    while (jj < 2 * n && s[jj] == '1') jj++;
    if (jj == 2 * n) 
    {
        cout << n << " " << n << endl;
        return ;
    }
    s = s.substr(jj,2 * n);
    int c0 = 0,c1 = 0;
    for (int i = 0;i < 2 * n;i++)
    {
        if (s[i] == '0') continue;
        if (i % 2 == 0) c0++;
        else c1++;
    }
    int a0 = 0,a1 = 0;
    for (int i = 0;i < 2 * n;i++)
    {
        if (s[i] == '0') continue;
        int j = i;
        while (j < 2 * n && s[j] == s[i]) j++;
        if (j % 2) a0++;
        else a1++;
        i = j - 1;
    }
    // cout << c0 << " " << a0 << " " << c1 << " " << a1 << endl;
    int ans0 = c0 - a0 + a1;
    int ans1 = c1 - a1 + a0;
    if (jj % 2) cout << ans0 << " " << ans1 << endl;
    else cout << ans1 << " " << ans0 << endl;
    // cout << c0 - a0 + a1 << " " << c1 - a1 + a0 << endl;
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