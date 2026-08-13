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
    int n,k;
    cin >> n >> k;
    vvt a(n,vt(n));
    int i = 0,j = 0;
    int cnt = 0;
    int t = k / n;
    int flag = 0;
    while (k--) 
    {
        if (a[i][j] == 1) flag = 1;
        if (flag) 
        {
            while (j < n && a[i][j] == 1) j++;
            a[i][j] = 1;
            i = (i + 1) % n;
            j = (j + 1) % n;
            continue;
        }
        a[i][j] = 1;
        cnt++;
        if (cnt >= t) 
        {
            i = (i + 1) % n;
            j = i;
            cnt = 0;
            continue;
        }
        j = (j + 1) % n;
    }
    int mx = 0,mn = INT_MAX;
    for (int i = 0;i < n;i++) 
    {
        int c = 0;
        for (int x : a[i]) c += x;
        mx = max(mx,c);
        mn = min(mn,c);
    }
    int ans = (mx - mn) * (mx - mn);
    mx = 0,mn = INT_MAX;
    for (int j = 0;j < n;j++) 
    {
        int c = 0;
        for (int i = 0;i < n;i++) c += a[i][j];
        mx = max(mx,c);
        mn = min(mn,c);
    }
    ans += (mx - mn) * (mx - mn);
    cout << ans << endl;
    for (int i = 0;i < n;i++) 
    {
        for (int x : a[i]) cout << x;
        cout << endl;
    }
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