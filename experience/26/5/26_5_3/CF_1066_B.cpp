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
    int n,r;
    cin >> n >> r;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int last = -1;
    int ans = 0;
    for (int i = 0;i <= min(n - 1,r - 1);i++)
    {
        if (a[i] == 1) 
        {
            last = i;
        }
    }
    if (last == -1) 
    {
        cout << -1 << endl;
        return ;
    }
    ans++;
    // cout << "ans : " << ans << endl;
    while (1)
    {
        if (last + r - 1 >= n - 1) break;
        int st = last;
        for (int i = min(n - 1,last + 2 * r - 1);i > last;i--) 
        {
            if (a[i] == 1) 
            {
                last = i;
                ans++;
                break;
            }
        }
        if (last == st) 
        {
            cout << -1 << endl;
            return ;
        }
        // cout << "ans : " << ans << endl;
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