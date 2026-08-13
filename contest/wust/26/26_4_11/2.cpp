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
    int a,b;
    cin >> a >> b;
    if (a < b) swap(a,b);
    int ans = 0;
    while (1)
    {
        int t = 0;
        if (a < b) swap(a,b);
        // cout << a << " " << b << endl;
        if (a <= 1) break;
        if (a == 2)
        {
            ans++;
            break;
        }
        if (a % 2 == 0) 
        {
            t = a / 2 - 1;
        }
        else 
        {
            t = a / 2;
        }
        a -= t * 2;
        b += t;
        ans += t;
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