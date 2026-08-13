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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    if (n == 1 || n == 2) 
    {
        cout << 0 << endl;
        return ;
    }
    vector dp(n + 1,vector<int>(3));
    vvt dd = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
    int ans = INT_MAX;
    for (int k = 0;k < 9;k++)
    {
        int d = a[1] + dd[k][1] - a[0] - dd[k][0];
        int last = a[1] + dd[k][1];
        int cnt = 0,flag = 1;
        if (dd[k][0] != 0) cnt++;
        if (dd[k][1] != 0) cnt++;
        for (int i = 2;i < n;i++)
        {
            if (a[i] - last != d)
            {
                if (abs(a[i] - last - d) > 1) 
                {
                    flag = 0;
                    break;
                }
                cnt++;
            }
            last = last + d;
        }
        if (flag) ans = min(ans,cnt);
    }
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans;

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