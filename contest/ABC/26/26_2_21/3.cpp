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
    int n,d;
    cin >> n >> d;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    queue<pii> q;
    for (int i = 0;i < n;i++)
    {
        q.push({a[i],i});
        int s = 0;
        while (s < b[i])
        {
            auto& [x,c] = q.front();
            if (s + x <= b[i]) 
            {
                s += x;
                q.pop();
            }
            else 
            {
                x -= (b[i] - s);
                s = b[i];
            }
        }
        while (!q.empty())
        {
            auto [x,c] = q.front();
            if (i - c >= d) q.pop();
            else break;
        }
    }
    ll ans = 0;
    while (!q.empty())
    {
        ans += q.front().fi;
        q.pop();
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