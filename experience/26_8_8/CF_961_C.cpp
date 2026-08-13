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
    int n;
    cin >> n;
    vvvt a(4,vvt(n,vt(n)));
    auto b = a;
    for (int i = 0;i < 4;i++)
    {
        for (int j = 0;j < n;j++)
        {
            string s;
            cin >> s;
            for (int k = 0;k < n;k++) a[i][j][k] = s[k] - '0';
        }
    }
    for (int i = 0;i < 4;i++)
    {
        for (int j = 0;j < n;j++)
        {
            for (int k = 0;k < n;k++) 
            {
                b[i][j][k] = (i & 1) ^ ((j + k) & 1);
            }
        }
    }
    swap(b[1],b[2]);
    auto f = [&](vvt& a,vvt& b)
    {
        int cnt = 0;
        for (int i = 0;i < a.size();i++)
        {
            for (int j = 0;j < a.size();j++)
            {
                if (a[i][j] != b[i][j]) cnt++;
            }
        }
        return cnt;
    };
    int ans = INT_MAX;
    ans = min(ans,f(a[0],b[0]) + f(a[1],b[1]) + f(a[2],b[2]) + f(a[3],b[3]));
    ans = min(ans,f(a[0],b[0]) + f(a[2],b[1]) + f(a[1],b[2]) + f(a[3],b[3]));
    ans = min(ans,f(a[0],b[0]) + f(a[3],b[1]) + f(a[1],b[2]) + f(a[2],b[3]));
    ans = min(ans,f(a[1],b[0]) + f(a[2],b[1]) + f(a[0],b[2]) + f(a[3],b[3]));
    ans = min(ans,f(a[1],b[0]) + f(a[3],b[1]) + f(a[0],b[2]) + f(a[2],b[3]));
    ans = min(ans,f(a[2],b[0]) + f(a[3],b[1]) + f(a[0],b[2]) + f(a[1],b[3]));
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}