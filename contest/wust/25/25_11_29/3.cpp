#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    unordered_map<int,long long> cnt;
    unordered_map<int,long long> vis;
    int p = 1;
    for (int i = 0;i < n;i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x,y;
            cin >> x >> y;
            if (vis[x] < p)
            {
                cnt[x] = min(1LL,cnt[x]) + y;
                vis[x] = p;
            }
            else 
            {
                cnt[x] += y;
            }
        }
        else if (a == 2)
        {
            int x,y;
            cin >> x >> y;
            if (vis[x] < p)
            {
                vis[x] = p;
                cnt.erase(x);
            }
            else 
            {
                if (cnt[x] - y > 0) cnt[x] -= y;
                else cnt.erase(x);
            }
        }
        else if (a == 3)
        {
            p++;
        }
        else 
        {
            int x;
            cin >> x;
            if (vis[x] < p) cout << min(1LL,cnt[x]) << endl;
            else cout << cnt[x] << endl;
        }
    }
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