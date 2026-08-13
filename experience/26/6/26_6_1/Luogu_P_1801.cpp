#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;
class FenwickTree{
public:
    vt tr;
    FenwickTree(int n) : tr(n + 1) {} 
    void update(int i,int v) 
    {
        for (;i < tr.size();i += i & -i) tr[i] += v;
    }
    int pre(int i) 
    {
        int r = 0;
        for (;i > 0;i &= i - 1)
        {
            r += tr[i];
        }
        return r;
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
    int n,m;
    cin >> n >> m;
    vt a(n),b(m);
    FenwickTree tr(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) cin >> b[i];
    vt tmp = a;
    ranges::sort(tmp);
    auto get = [&](int x) 
    {
        return ranges::lower_bound(tmp,x) - tmp.begin() + 1;
    };
    int i = 0,j = 0;
    int c = 0;
    for (int x : a) 
    {
        tr.update(get(x),1);
        c++;
        while (j < m && c == b[j]) 
        {
            i++;
            int id = tr.kth(i);
            cout << tmp[id - 1] << endl;
            j++;
        }
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