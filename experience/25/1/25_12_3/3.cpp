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
    int n,m;
    cin >> n >> m;
    if (m % n) cout << -1 << endl;
    else 
    {
        queue<pair<int,int>> q;
        map<int,int> a;
        q.emplace(n,0);
        int ans = -1;
        while (!q.empty())
        {
            auto [x,cnt] = q.front();
            q.pop();
            a[x]++;
            if (x == m) 
            {
                ans = cnt;
                break;
            }
            if (x * 2 <= m && !a.count(x * 2)) 
            {
                q.emplace(x * 2,cnt + 1);
                a[x * 2]++;
            }
            if (x * 3 <= m && !a.count(x * 3)) 
            {
                q.emplace(x * 3,cnt + 1);
                a[x * 3]++;
            }
        }
        cout << ans << endl;
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