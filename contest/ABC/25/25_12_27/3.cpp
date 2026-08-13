#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector<pair<int,int>> st;
    for (int x : a)
    {
        if (!st.empty() && x == st.back().fi) 
        {
            st.back().se++;
            if (st.back().se == 4) st.pop_back();
        }
        else st.push_back({x,1});
    }
    int ans = 0;
    for (auto [x,c] : st) ans += c;
    cout << ans << endl;
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