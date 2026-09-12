#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<ll>;

const int MOD = 998244353;

const int MX = 1000001;
ll F[MX];
ll INV_F[MX];

ll qpow(ll a,ll b)
{
    ll res = 1;
    while (b) 
    {
        if (b & 1) res = a * res % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
auto init = []
{
    F[0] = 1;
    for (int i = 1;i < MX;i++) F[i] = F[i - 1] * i % MOD;
    INV_F[MX - 1] = qpow(F[MX - 1],MOD - 2);
    for (int i = MX - 1;i;i--) INV_F[i - 1] = INV_F[i] * i % MOD;
    return 0;
}();

ll P(int n,int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return F[n] * INV_F[n - k] % MOD;
}
class FenwickTree
{
public:
    vll tr;
    FenwickTree (int n)
    {
        tr.resize(n + 1);
    }
    void update(int i,int v) 
    {
        for (;i < tr.size();i += i & -i) tr[i] += v;
    }
    ll pre(int i) 
    {
        ll res = 0;
        for (;i > 0;i &= i - 1) res += tr[i];
        return res;
    }
    ll query(int l,int r) 
    {
        if (r < l) return 0;
        return pre(r) - pre(l - 1);
    }
    int kth(int k)
    {
        int pos = 0,bit = 1;
        while ((bit << 1) < tr.size()) bit <<= 1;
        for (;bit;bit >>= 1) 
        {
            int nxt = pos + bit;
            if (nxt < tr.size() && tr[nxt] < k) 
            {
                pos = nxt;
                k -= tr[nxt];
            }
        }
        return pos + 1;
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vvt a(q,vt(3));
    for (int i = 0;i < q;i++)
    {
        int u,x;
        cin >> u >> x;
        a[i][0] = u;
        a[i][1] = x;
        a[i][2] = __lg(u);
    }
    sort(a.begin(),a.end(),[&](auto& t1,auto& t2){
        if (t1[1] == t2[1]) return t1[2] > t2[2];
        return t1[1] < t2[1];
    });
    int N = 1 << n;
    FenwickTree tr1(N);
    ll ans = 1,res = 0;
    for (int i = 0;i < q;i++)
    {
        int l = a[i][0],r = a[i][0];
        int x = a[i][1];
        while (l < N) 
        {
            l *= 2;
            r = 2 * r + 1;
        }
        int cnt = r - l + 1 - tr1.query(l - N + 1,r - N + 1);
        int cc = cnt;
        while (cc--)
        {
            int L = l - 1,R = r + 1;
            int c2 = 10;
            while (L + 1 < R)
            {
                int m = L + R >> 1;
                if (tr1.query(l - N + 1,m - N + 1) > m - l + 1) R = m; 
                else L = m;
            }
            tr1.update(R - N + 1,1);
        }
        // cout << P(x - res,cnt) << endl;
        // cout << x - res << " " << cnt << endl;
        ans = (ans * P(x - res,cnt)) % MOD;
        
        res += cnt;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();

}