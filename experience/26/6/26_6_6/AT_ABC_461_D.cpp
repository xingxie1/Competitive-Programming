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
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt pre(n + 1,vt(m + 2));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + (a[i][j] == '1');
    }
    ll cnt = 0;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            for (int i1 = i;i1 < n;i1++) 
            {
                auto f = [&](int k) 
                {
                    int l = j - 1,r = m;
                    while (l + 1 < r)
                    {
                        int mid = (l + r) / 2;
                        auto check = [&](int j1) 
                        {
                            return pre[i1 + 1][j1 + 1] - pre[i1 + 1][j] - pre[i][j1 + 1] + pre[i][j] >= k;
                        };
                        if (check(mid)) r = mid;
                        else l = mid;
                    }
                    return r;
                };
                int r1 = f(k),r2 = f(k + 1);
                if (pre[i1 + 1][r1 + 1] - pre[i1 + 1][j] - pre[i][r1 + 1] + pre[i][j] == k) 
                {
                    cnt += r2 - r1;
                }
            }
        }
    }
    cout << cnt << endl;
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