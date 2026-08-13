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
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    ll d1 = 1LL * pow(a-c,2) + 1LL * pow(b - d,2);
    ll d2 = 1LL * pow(a-e,2) + 1LL * pow(b - f,2);
    ll d3 = 1LL * pow(c - e,2) + 1LL * pow(d - f,2);
    if (d1 == d2 && d2 == d3) cout << "YES" << endl;
    else cout << "NO" << endl;
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