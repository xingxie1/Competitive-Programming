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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    vt a(n);
    vt cnt(n + 1);
    for (int i = 0;i < n;i++) cin >> a[i];
    ranges::sort(a);
    for (int x : a) cnt[x]++;
    int mx = ranges::max(a);
    if (cnt[mx] % 2 == 0) 
    {
        YES;
        return ;
    }
    for (int i = mx - 1;i >= max(0,mx - k);i--) 
    {
        if (cnt[i])
        {
            // cout << i << " " << cnt[i] << endl;
            YES;
            return ;
        } 
    }
    while (mx--) 
    {
        if (cnt[mx]) 
        {
            if (cnt[mx] % 2 == 0) 
            {
                // cout << mx << endl;
                YES;
                return ;
            }
            else 
            {
                for (int i = mx - 1;i >= max(0,mx - k);i--) 
                {
                    if (cnt[i])
                    {
                        YES;
                        return ;
                    } 
                }
            }
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