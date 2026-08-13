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
    int n, m;
    cin >> n >> m;
    map<pair<int,int>,int> cnt;
    int ans = 0;
    while (m --)
    {
        int r,c;
        cin >> r >> c;
        if (!cnt.count({r,c}) && !cnt.count({r,c + 1}) && !cnt.count({r + 1,c}) && !cnt.count({r + 1,c + 1}))
        {
            ans ++;
            cnt[{r,c}]++;
            cnt[{r + 1,c}]++;
            cnt[{r,c + 1}]++;
            cnt[{r + 1,c + 1}]++;
        }
        
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