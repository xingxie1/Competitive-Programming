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
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a,b;
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        if (x % 2) a.push_back(x);
        else b.push_back(x);
    }
    ranges::sort(a);
    ranges::sort(b);
    vll ans;
    ll s1 = 0,s2 = 0;
    if (!a.empty()) s1 = a.back();
    if (!b.empty()) s2 = b.back();
    ll mx = max(s1,s2);
    ans.push_back(mx);
    while (!a.empty() && !b.empty())
    {
        s1 += b.back();
        s2 += a.back();
        ans.push_back(max(s1,s2));
        a.pop_back();
        b.pop_back();
    }
    if (a.empty())
    {
        while (!b.empty())
        {
            s1 += b.back();
            ans.push_back(s1);
            b.pop_back();
        }
    }
    else if (b.empty())
    {
        while (!a.empty())
        {
            s2 += a.back();
            ans.push_back(s2);
            a.pop_back();
        }
    }
    while (ans.size() < n) ans.push_back(0);
    for (ll x : ans) cout << x << " ";
    cout << endl;

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