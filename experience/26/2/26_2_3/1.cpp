#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    umap<int,int> pos;
    vt In(n),pre(n + 1);
    for (int i = 0;i < n;i++)
    {
        int y = x ^ a[i];
        if (pos.count(y))
        {
            In[i] = pos[y] + 1;
        }
        pos[a[i]] = i;
    }
    for (int i = 0;i < n;i++) pre[i + 1] = max(pre[i],In[i]);
    while (m--)
    {
        int l,r;
        cin >> l >> r;
        int flag = (pre[r] >= l);
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
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