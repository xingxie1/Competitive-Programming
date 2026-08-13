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
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int mxi = 1;
    for (int i = 2;i < n;i++)
    {
        if (a[i] > a[mxi]) mxi = i;
    }
    vt ans(a.begin() + mxi,a.end());
    
    for (int i = 0;i <= mxi - 1;i++)
    {
        vt b(a.begin() + i,a.begin() + mxi);
        ranges::reverse(b);
        vt tmp(a.begin() + mxi,a.end());
        tmp.insert(tmp.end(),b.begin(),b.end());
        tmp.insert(tmp.end(),a.begin(),a.begin() + i);
        ans = max(ans,tmp);
    }
    if (mxi == n - 1)
    {
        vt tmp = {a[n - 1]};
        tmp.insert(tmp.end(),a.begin(),a.end() - 1);
        ans = max(ans,tmp);
    }
    for (int x : ans) cout << x << " ";
    cout << endl;
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