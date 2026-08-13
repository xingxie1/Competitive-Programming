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
    vvt cnt(n + 1,vt(201));
    vvt pos(201);
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        pos[x].push_back(i);
        for (int y = 1;y <= 200;y++) cnt[i + 1][y] = cnt[i][y] + (y == x);
    }
    int ans = 0;
    for (int x = 1;x <= 200;x++) 
    {
        ans = max(ans,cnt[n][x]);
        for (int k = 1;k <= cnt[n][x] / 2;k++) 
        {
            int l = pos[x][k - 1],r = pos[x][pos[x].size() - k];
            int mx = 0;
            for (int y = 1;y <= 200;y++)
            {
                mx = max(mx,cnt[r][y] - cnt[l + 1][y]);
            }
            ans = max(ans,mx + 2 * k);
        }
    }
    cout << ans << endl;
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