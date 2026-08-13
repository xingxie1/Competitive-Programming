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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vvt pre(6,vt(n + 1));
    vector<string> p = {"abc","acb","bac","bca","cab","cba"};
    for (int j = 0;j < 6;j++)
    {
        for (int i = 0;i < n;i++) 
        {
            pre[j][i + 1] = pre[j][i] + (s[i] != p[j][i % 3]);
        }
    }
    while (q--)
    {
        int l,r ;
        cin >> l >> r;
        l--;
        r--;
        int ans = INT_MAX;
        for (int i = 0;i < 6;i++)
        {
            ans = min(ans,pre[i][r + 1] - pre[i][l]);
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