#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    int l = 0,r = 2 * n + 1;
    auto check = [&](int m) 
    {
        int c0 =0 ,c1 = 0;
        int pre = -1;
        for (int i = 0;i < n;i++) 
        {
            int type = (a[i] >= m) + (b[i] >= m);
            if (type == 2) 
            {
                pre = 1;
                c1++;
            }
            else if (type == 0) 
            {
                if (pre != 0) c0++;
                pre = 0;
            }
        }
        return c1 > c0;
    };
    while (l + 1 < r) 
    {
        int m = l + r >> 1;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << endl;
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