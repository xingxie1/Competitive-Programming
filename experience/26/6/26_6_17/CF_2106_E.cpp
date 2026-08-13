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
    int n,q;
    cin >> n >> q;
    vt a(n),p(n + 1);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        p[a[i]] = i;
    }
    while (q--) 
    {
        int l,r,k;
        cin >> l >> r >> k;
        l--;r--;
        if (p[k] < l || p[k] > r) 
        {
            cout << -1 << " ";
            continue;
        }
        int j = p[k];
        int c0 = 0,c1 = 0;
        int u0 = 0,u1 = 0;
        while (l <= r) 
        {
            int m = l + r >> 1;
            if (a[m] == k) break;
            if (a[m] < k) 
            {
                if (m > j) 
                {
                    c1++;
                    r = m - 1;
                }
                else 
                {
                    l = m + 1;
                    u0++;
                }
            }
            else 
            {
                if (m < j) 
                {
                    c0++;
                    l = m + 1;
                }
                else 
                {
                    r = m - 1;
                    u1++;
                }
            }
        }
        if (c0 > k - 1 - u0) 
        {
            cout << -1 << " ";
            continue;
        }
        if (c1 > n - k - u1) 
        {
            cout << -1 << " ";
            continue;
        }
        int ans = min(c0,c1) * 2 + abs(c1 - c0) * 2;
        cout << ans << " ";
    }
    cout << endl;
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