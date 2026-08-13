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
    int n,x;
    cin >> n >> x;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    ll sum = 0,req = 0;
    for (int i = 0;i < n;i++)
    {
        req = max(req,a[i] - sum);
        sum += b[i] - a[i];
    }
    if (x < req)
    {
        int cnt = 0;
        ll cur = x;
        for (int i = 0;i < n;i++)
        {
            if (cur >= a[i]) cur += b[i] - a[i];
            else break;
            cnt++;
        }
        cout << cnt << endl;
    }
    else
    {
        if (sum >= 0) cout << "Infinity" << endl;
        else 
        {
            sum = -sum;
            ll ans = (x - req) / sum + 1;
            ll cur = x - ans * sum;
            ans *= n;
            for (int i = 0;i < n;i++)
            {
                if (cur >= a[i]) cur += b[i] - a[i];
                else break;
                ans++;
            }
            cout << ans << endl;
        }
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