#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;


class XorBasis 
{
    vector<ll> b;

public:
    XorBasis(int n) : b(n) {}

    int insert(ll x) 
    {
        for (int i = b.size() - 1; i >= 0; i--) 
        {
            if (x >> i) 
            { 
                if (b[i] == 0) 
                {
                    b[i] = x;
                    return i;
                }
                x ^= b[i];
            }
        }
        return -1;
    }
    void erase(int p) 
    {
        if (p != -1) b[p] = 0;
    }
    ll max_xor() 
    {
        ll res = 0;
        for (int i = b.size() - 1; i >= 0; i--) 
        {
            res = max(res, res ^ b[i]);
        }
        return res;
    }
};

XorBasis xb(60);

ll ans;
vll a;
void dfs(int i,int n) 
{
    if (i >= n) 
    {
        ans = max(ans,xb.max_xor());
        return ;
    }
    int p = xb.insert(a[i]);
    dfs(i + 2,n);
    dfs(i + 3,n);
    xb.erase(p);
}
void solve()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ans = 0;
    dfs(0,n);
    dfs(1,n);
    cout << ans << endl;
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int _ = 1;
    cin >> _;
    while (_--) solve();

}

