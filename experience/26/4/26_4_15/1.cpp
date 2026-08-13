
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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    vt cnt(10);
    for (int x : a) cnt[x]++;
    for (int i = 1;i <= 9;i++) 
    {
        if (!cnt[i]) 
        {
            NO;
            return ;
        }
    }
    int mx = 0,mn = INT_MIN;
    for (int i = 1;i < 10;i++) 
    {
        mx = max(mx,cnt[i]);
        mn = min(mn,cnt[i]);
    }
    if (mx - mn > 1) NO;
    else YES;
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