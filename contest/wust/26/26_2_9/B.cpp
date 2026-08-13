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
    int n,q,s;
    cin >> n >> q >> s;
    vt t(n);
    for (int i = 0;i < n;i++) cin >> t[i];
    vll pre(n + 1);
    pre[0] = s;
    for (int i = 0;i < n;i++) pre[i + 1] = pre[i] + t[i];
    while (q--)
    {
        int x,y;
        cin >> x >> y;
        cout << pre[x - 1] + y - 1 << endl;
    }
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