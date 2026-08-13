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
    int n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    if (k == 0) 
    {
        if (a[0] > 1)cout << 1 << endl;
        else cout << -1 << endl;
        return ;
    }
    else if (k == n)
    {
        cout << a[k - 1] << endl;
        return ;
    }
    int l = 0,r = 1e9 + 1;
    while (l + 1 < r)
    {
        int m = l + (r - l) / 2;
        auto check = [&](int x)
        {
            int cnt = 0;
            for (int xx : a)
            {
                if (xx <= x) cnt++;
            }
            return cnt <= k;
        };
        if (check(m)) l = m;
        else r = m;
    }
    int cnt = 0;
    for (int x : a)
    {
        if (x <= l) cnt++;
    }
    if (cnt == k) cout << l << endl;
    else cout << -1 << endl;
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