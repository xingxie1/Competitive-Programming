#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll ans = 0,pre = 0;
    for (int i = 1;i < n;i++)
    {
        ll x = a[i],y = a[i - 1],cur = 0;
        if (x == 1)
        {
            if (y > 1) 
            {
                cout << -1 << endl;
                return ;
            }
            cur = 0;
        }
        else if (y == 1)
        {
            cur = 0;
        }
        else if (x < y) 
        {
            ll tmp = x,cnt = 0;
            while (tmp < y)
            {
                tmp = tmp * tmp;
                cnt++;
            }
            cur = pre + cnt;
        }
        else 
        {
            ll tmp = y,cnt = 0;
            while (tmp * tmp <= x)
            {
                tmp = tmp * tmp;
                cnt++;
            }
            cur = max(0LL,pre - cnt);
        }
        ans += cur;
        pre = cur;
    }
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