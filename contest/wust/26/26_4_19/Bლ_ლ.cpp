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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt vis(n);
    int ans = 0;
    for (int i = 0;i < n;i++)
    {
        if (a[i]) 
        {
            int j = i;
            int f = 0;
            ans++;
            while (j < n && a[j] > 0)
            {
                vis[j] = 1;
                if (a[j] == 2) f = 1;
                j++;
            }
            if (f)
            {
                if (i - 1 >= 0) vis[i - 1] = 1;
                if (j < n) vis[j] = 1;
            }
            else 
            {
                if (i - 1 >= 0 && !vis[i - 1]) vis[i - 1] = 1;
                else if (j < n && !vis[j]) vis[j] = 1;
            }
            i = j - 1;
        }
    }
    for (int i = 0;i < n;i++)
    {
        if (!vis[i] && a[i] == 0) ans++;
    }

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