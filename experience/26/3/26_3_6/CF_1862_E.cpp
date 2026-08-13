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
    int n,m,d;
    cin >> n >> m >> d;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll ans = 0,sum = 0;
    pqueue<int,vector<int>,greater<>> pq;
    for (int i = 0;i < n;i++)
    {
        if (a[i] > 0)
        {
            pq.push(a[i]);
            sum += a[i];
            if (pq.size() > m) 
            {
                sum -= pq.top();
                pq.pop();
            }
        }
        ans = max(ans,sum - 1LL * (i + 1) * d);
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