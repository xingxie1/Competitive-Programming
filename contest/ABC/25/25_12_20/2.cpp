#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int h,w,n;
    cin >> h >> w >> n;
    vector<map<int,int>> g(h);
    for (int i = 0;i < h;i++)
    {
        int x;
        for (int j = 0;j < w;j++) 
        {
            cin >> x;
            g[i][x]++;
        }
    }
    vt b(n);
    int ans = 0;
    for (int i = 0;i < n;i++) cin >> b[i];
    for (int i = 0;i < h;i++)
    {
        int cnt = 0;
        for (int j = 0;j < n;j++)
        {
            cnt += g[i][b[j]];
        }
        ans = max(ans,cnt);
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