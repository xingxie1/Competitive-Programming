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
    int n,m;
    cin >> n >> m;
    vt a(n);
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        if (x > m) a[i] = 1;
        else if (x == m) a[i] = 0;
        else a[i] = -1;
    }
    int s = 0;
    map<int,int> cnt;
    cnt[0]++;
    ll ans = 0;
    int flag = 0;
    for (int i = 0;i < n;i++)
    {
        int x = a[i];
        if (x == 0) flag = 1;
        s += a[i];
        if (!flag)
        {
            cnt[s]++;
        }
        else 
        {
            if (cnt.count(s)) ans += cnt[s];
            if (cnt.count(s - 1)) ans += cnt[s - 1];
        }
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