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
    int n,m;
    cin >> n >> m;
    vvt a(n,vt(m));
    if (m == 1)
    {
        cout << 0 << endl;
        for (int i = 0;i < n;i++) cout << 0 << endl;
        return ;
    }
    int ans = min(m,n + 1);
    cout << ans << endl;
    vt tmp;
    for (int i = 0;i < m;i++) tmp.push_back(i);
    int cnt = 0;
    for (int i = 0;i < n;i++)
    {
        a[i] = tmp;
        int k = (i + 1 + cnt) % m;
        if (k == 0)
        {
            cnt++;
            k++;
        }
        reverse(a[i].begin() + k,a[i].end());
        reverse(a[i].begin(),a[i].begin() + k);
        ranges::reverse(a[i]);
    }
    for (int i = 0;i < n;i++)
    {
        for (int x : a[i]) cout << x << " ";
        cout << endl;
    }
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