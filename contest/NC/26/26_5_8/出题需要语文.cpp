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
    vvt cnt(6);
    vt a(n);
    for (int i = 0;i < n;i++) 
    {
        char c;
        int x;
        cin >> c >> x;
        c -= 'A';
        if (x >= 60) cnt[c].push_back(i);
        a[i] = x;
    }
    ll sum = 0;
    vt ans;
    for (int i = 0;i < 6;i++) 
    {
        if (cnt[i].empty()) 
        {
            cout << -1 << endl;
            return ;
        }
        int mxi = cnt[i][0];
        for (int j : cnt[i]) 
        {
            if (a[mxi] < a[j]) mxi = j;
        }
        sum += a[mxi];
        ans.push_back(mxi);
    }
    if (sum < 420) 
    {
        cout << -1 << endl;
        return ;
    }
    for (int x : ans) cout << x + 1 << " ";
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