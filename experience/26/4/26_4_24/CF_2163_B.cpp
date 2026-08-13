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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    string s;
    cin >> s;
    if (s[0] == '1' || s[n - 1] == '1') 
    {
        cout << -1 << endl;
        return ;
    }
    int p1 = -1,pn = -1;
    for (int i = 0;i < n;i++)
    {
        if (a[i] == 1) p1 = i;
        if (a[i] == n) pn = i;
        if (a[i] == 1 && s[i] == '1') 
        {
            cout << -1 << endl;
            return ;
        }
        if (a[i] == n && s[i] == '1') 
        {
            cout << -1 << endl;
            return ;
        }
    }
    set<pii> ans;
    ans.insert({1,p1 + 1});
    ans.insert({1,pn + 1});
    ans.insert({p1 + 1,n});
    ans.insert({pn + 1,n});
    ans.insert({min(p1,pn) + 1,max(p1,pn) + 1});
    cout << ans.size() << endl;
    for (auto& [l,r] : ans) cout << l << " " << r << endl;
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