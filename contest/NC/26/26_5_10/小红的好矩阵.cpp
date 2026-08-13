#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
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
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vector<string> a(2);
    cin >> a[0] >> a[1];
    if (n % 3) 
    {
        cout << -1 << endl;
        return ;
    }
    auto f = [&](char t)
    {
        int ans = 0;
        for (int i = 0;i < n;i ++)
        {
            if (i % 3 != 1) 
            {
                if (a[0][i] != t) ans++;
                if (a[1][i] != t) ans++;
                t = ((t - '0') ^ 1) + '0';
            }
            else 
            {
                if (a[0][i] == a[1][i]) ans++;
            }
        }
        return ans;
    };
    int ans = min(f('0'),f('1'));
    auto f2 = [&](char t)
    {
        int ans = 0;
        for (int i = 0;i < n;i+=3)
        {
            ans += (a[0][i] != t);
            ans += (a[0][i] != t);
            ans += (a[0][i] != t);
            ans += (a[1][i] == t);
            ans += (a[1][i] == t);
            ans += (a[1][i] == t);
            t = ((t - '0') ^ 1) + '0';
        }
        return ans;
    };
    ans = min(ans,f('0'));
    ans = min(ans,f('1'));
    cout << ans << endl;
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