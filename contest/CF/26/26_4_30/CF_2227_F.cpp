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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt mn(n + 1,INT_MAX);
    ll sum = 0;
    int last = n;
    for (int i = n - 1;i >= 0;i--)
    {
        if (a[i] > mn[i + 1]) 
        {
            int d = a[i] - mn[i + 1];
            sum += d;
            if (i < n - 1 && a[i] > a[i + 1]) sum += (a[i] - a[i + 1]) * (last - i);
            mn[i] = mn[i + 1];
        }
        else 
        {
            mn[i] = a[i];
            last = i;
        }
    }
    ll ans = sum;
    vt b = {mn[0]};
    for (int i = 1;i <= n;i++) 
    {
        if (mn[i] == b.back()) continue;
        b.push_back(mn[i]);
    }
    int j = 1;
    int mm = b[0];
    // for (int x : b) cout << x <<" ";
    // cout << endl;
    int cnt = 0;
    ll sump = 0;
    // for (int i = 0;i < n;i++)
    // {
    //     int x = a[i];
    //     if (x == mm && mn[i + 1] != mm)
    //     {
    //         mm = b[j++];
    //         // cout << "@@@" << endl;
    //         ans = max(ans,1LL * cnt * (i - 1) - sump + sum);
    //         cnt = 0;
    //         sump = 0;
    //         continue;
    //     }
    //     if (a[i] >= mm) 
    //     {
    //         sump += i;
    //         cnt++;
    //     }
    // }
    cout << ans << endl;

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