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
    int n,I,H,R;
    cin >> n >> I >> H >> R;
    vector<long long> ans(n + 1,H),diff(n + 3);
    set<pair<int,int>> cnt;
    for (int i = 1;i <= R;i++)
    { 
        int l,r;
        cin >> l >> r;
        if (l > r) swap(l,r);
        if (l + 1 <= r - 1 && !cnt.count({l,r}))
        {
            diff[l + 1] --;
            diff[r] ++;
        }
        cnt.insert({l,r});
    }
    int cur = 0;
    for (int i = 1;i <= n;i++)
    {
        cur += diff[i];
        ans[i] += cur;
    }
    for (int i = 1;i <= n;i++) cout << ans[i] << endl;
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