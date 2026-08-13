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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vvt pre(26,vt(n + 1));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < 26;j++)
        {
            pre[j][i + 1] = pre[j][i] + (s[i] == ('a' + j));
        }
    }
    auto f = [&](auto&& self,int l,int r,char c)
    {
        if (l == r) return (int)(s[l] != c);
        int len = (r - l + 1) / 2;
        int cnt1 = 0,cnt2 = 0;
        cnt1 = len - (pre[c - 'a'][l + len] - pre[c - 'a'][l]);
        cnt2 = len - (pre[c - 'a'][r + 1] - pre[c - 'a'][l + len]);
        int Lv = cnt1 + self(self,l + len,r,(c - 'a' + 1) % 26 + 'a');
        int Rv = cnt2 + self(self,l,l + len - 1,(c - 'a' + 1) % 26 + 'a');
        return min(Lv,Rv);
    };
    int ans = INT_MAX;
    ans = f(f,0,n - 1,'a');
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