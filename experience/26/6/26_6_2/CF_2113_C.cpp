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
    int n,m,k;
    cin >> n >> m >> k;
    k--;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt cnt(n + 1,vt(m + 1));
    int sum = 0;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            cnt[i + 1][j + 1] = cnt[i + 1][j] + cnt[i][j + 1] - cnt[i][j] + (a[i][j] == 'g');
            sum += (a[i][j] == 'g');
        }
    }
    auto query = [&](int l,int r,int u,int d) 
    {
        return cnt[d + 1][r + 1] - cnt[d + 1][l] - cnt[u][r + 1] + cnt[u][l];
    };
    int ans = 0;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] != '.') continue;
            int l = max(j - k,0),r = min(j + k,m - 1);
            int u = max(i - k,0),d = min(i + k,n - 1);
            ans = max(ans,sum - query(l,r,u,d));
        }
    }
    cout << ans << endl;
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