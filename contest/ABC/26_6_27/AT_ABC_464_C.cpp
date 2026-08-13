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
    int n,m;
    cin >> n >> m;
    vvt a(n,vt(3));
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    }
    ranges::sort(a,{},[&](auto& b){return b[0];});
    map<int,int> cnt;
    int ans = 0;
    for (int i = 0;i < n;i++) 
    {
        cnt[a[i][1]]++;
        if (cnt[a[i][1]] == 1) ans++;
    }
    int last = 0;
    for (int d = 1;d <= m;d++)
    {
        int l = -1,r = n;
        while (l + 1 < r) 
        {
            int m = l + (r - l) / 2;
            if (a[m][0] <= d) l = m;
            else r = m;
        }
        for (int i = last;i <= l;i++) 
        {
            cnt[a[i][1]]--;
            if (cnt[a[i][1]] == 0) ans--;
            cnt[a[i][2]]++;
            if (cnt[a[i][2]] == 1) ans++;
        }
        // cout << last << " " << l << endl;
        last = l + 1;
        cout << ans << endl;
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