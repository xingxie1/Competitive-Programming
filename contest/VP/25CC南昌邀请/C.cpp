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
    int n,k;
    cin >> n >> k;
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    int blocksize = sqrt(n + 1);
    int blockcnt = (n + blocksize - 1) / blocksize;
    vt b(n + 5),st(blocksize + 5),ed(blocksize + 5),mx(blocksize + 5),lazy(blocksize + 5);
    for (int i = 1;i <= blockcnt;i++)
    {
        st[i] = (i - 1) * blocksize + 1;
        ed[i] = min(n,i * blocksize);
    }
    for (int i = 1;i <= blockcnt;i++)
    {
        for (int j = st[i];j <= ed[i];j++)
        {
            b[j] = i;
        }
    }
    vt c(n + 1);
    auto rebuild = [&](int p) -> void
    {
        mx[p] = 0;
        for (int i = st[p];i <= ed[p];i++) mx[p] = max(mx[p],c[i]);
    };
    auto add = [&](int l,int r,int v)
    {
        int p = b[l],q = b[r];
        if (p == q)
        {
            for (int i = l;i <= r;i++) c[i] += v;
            rebuild(p);
            return ;
        }
        for (int i = l;i <= ed[p];i++)
        {
            c[i] += v;
        }
        rebuild(p);
        for (int i = st[q];i <= r;i++)
        {
            c[i] += v;
        }
        rebuild(q);
        for (int i = p + 1;i < q;i++) lazy[i] += v;
    };
    auto query = [&]()
    {
        int res = 0;
        for (int i = 1;i <= blockcnt;i++) res = max(res,mx[i] + lazy[i]);
        return res;
    };

    int l = 0,r = 0,ans = 0;
    while (r < n)
    {
        add(a[r].fi,a[r].se,1);
        while (l < r && query() > k)
        {
            add(a[l].fi,a[l].se,-1);
            l++;
        }
        ans = max(ans,r - l + 1);
        r++;
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