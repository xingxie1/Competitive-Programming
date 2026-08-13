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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int k;
    cin >> k;
    if (k == 0) 
    {
        cout << 0 << endl;
        return ;
    }
    int l = -1,r = 501;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (1LL * m * (m - 1) / 2 > k) r = m;
        else l = m;
    }
    ll res = k - 1LL * l * (l - 1) / 2;
    vpii a;
    for (int i = 0;i < l;i++) a.push_back({i,0});
    int x = 0,y = 1;
    while (res > 0)
    {
        int m = 1;
        while ((m + 1) * (m + 2) / 2 <= res) m++;
        for (int i = 0;i < m;i++) a.push_back({x + i,y});
        res -= m * (m + 1) / 2;
        x += m;
        y++;
    }
    cout << a.size() << endl;
    for (auto&[l,r] : a) cout << l << " " << r << endl;
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