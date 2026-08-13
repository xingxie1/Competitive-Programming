#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vvt cnt(n + 1,vt(26));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < 26;j++)
        {
            cnt[i + 1][j] = cnt[i][j] + (s[i] == ('a' + j));
        }
    }
    while (q--)
    {
        int l,r,x;
        cin >> l >> r >> x;
        l--;r--;
        ll ans = 0;
        if (x == 1)
        {
            for (int i = 0;i < 26;i++) ans += (cnt[r + 1][i] - cnt[l][i]);
        }
        else if (x == 2)
        {
            for (int i = 0;i < 26;i++) 
            {
                int c = cnt[r + 1][i] - cnt[l][i];
                if (c < 2) continue;
                ans += 1LL * c * (c - 1) / 2;
            }
        }
        else 
        {
            for (int i = 0;i < 26;i++) 
            {
                int c = cnt[r + 1][i] - cnt[l][i];
                if (c < 3) continue;
                ans += 1LL * c * (c - 1) * (c - 2) / 6;
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