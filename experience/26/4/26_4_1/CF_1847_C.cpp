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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt suf(n + 1);
    for (int i = n - 1;i >= 0;i--) suf[i] = suf[i + 1] ^ a[i];
    int ans = 0;
    for (int i = 8;i >= 0;i--)
    {
        int mask = ans | 1 << i;
        set<int> st;
        int flag = 0;
        for (int x : suf)
        {
            int y = x & mask;
            if (st.contains(y ^ mask)) flag = 1;
            st.insert(y);
        }
        if (flag) ans |= 1 << i;
    }
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