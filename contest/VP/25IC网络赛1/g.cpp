#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using pii = pair<int,int>;
using vll = vector<ll>;
using vpii = vector<pii>;


void solve()
{
    int n,m;
    cin >> n >> m;
    vpii a(m);
    set<pii> st;
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        if (v == u + 1) st.insert({u,v});
    }
    if (st.size() == n - 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}