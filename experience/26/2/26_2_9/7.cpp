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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,w;
    cin >> n >> w;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    auto check1 = [&](int x)
    {
        for (int y : a) 
        {
            if (x + y > w) return 0;
            x += y;
        }
        return 1;
    };
    auto check2 = [&](int x)
    {
        for (int y : a) 
        {
            if (x + y < 0) return 0;
            x += y;
        }
        return 1;
    };
    int l = -1,r = w + 1,mn = INT_MAX,mx = INT_MIN;
    while (l + 1 < r)
    {
        int m = (r + l) / 2;
        if (check1(m)) l = m;
        else r = m;
    }
    mx = l;
    l = -1,r = w + 1;
    while (l + 1 < r)
    {
        int m = (r + l) / 2;
        if (check2(m)) r = m;
        else l = m;
    }
    mn = r;
    if (mn > mx) cout << 0 << endl;
    else cout << mx - mn + 1<< endl;

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