#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using vpii = vector<pii>;

class FenwickTree
{
    vt tr;
public:
    FenwickTree (int n) : tr(n + 1) {} 
    
    void update(int i,int v) 
    {
        for (;i < tr.size();i += i & -i) tr[i] += v;
    }

    int pre(int i) 
    {
        int res = 0;
        for (;i > 0;i &= i - 1) res += tr[i];
        return res;
    }
    int query(int l,int r) 
    {
        if (r < l) return 0;
        return pre(r) - pre(l - 1);
    }
    int kth(int k) 
    {
        int pos = 0;
        int bit = 1;
        while ((bit << 1) < tr.size())
        {
            bit <<= 1;
        }
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
    int m;
    cin >> m;
    int n = m / 2;
    set<int> st;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    FenwickTree tr(m);
    for (int i = 1;i <= m;i++) tr.update(i,1);
    vt ansa,ansb;
    for (int i = 0;i < n;i++) 
    {
        int p = tr.kth(a[i]);
        ansa.push_back(p);
        tr.update(p,-1);
        
        p = tr.kth(b[i]);
        ansb.push_back(p);
        tr.update(p,-1);
    }
    for (int x : ansa) cout << x << " ";
    cout << endl;
    for (int x : ansb) cout << x << " ";
    cout << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();

}