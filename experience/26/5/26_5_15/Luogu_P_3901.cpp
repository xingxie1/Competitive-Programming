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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

struct Query{
    int l,r,id;
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    vector<Query> qs(q);
    for (int i = 0;i < q;i++) 
    {
        cin >> qs[i].l >> qs[i].r;
        qs[i].id = i;
    }
    int B = sqrt(n) + 1;
    sort(qs.begin(),qs.end(),[&](auto& x,auto& y){
        int bx = x.l / B;
        int by = y.l / B;
        if (bx != by) return bx < by;
        if (bx & 1) return x.r > y.r;
        return x.r < y.r;
    });
    vt cnt(1e5 + 5);
    int f = 0;
    auto add = [&](int x)
    {
        cnt[x]++;
        if (cnt [x] >= 2) f ++;
    };
    auto del = [&](int x)
    {
        if (cnt[x] > 1) f--;
        cnt[x]--;
    };
    int L = 1,R = 0;
    vt ans(q);
    for (auto& [l,r,id] : qs) 
    {
        while (L > l) add(a[--L]);
        while (R < r) add(a[++R]);
        while (L < l) del(a[L++]);
        while (R > r) del(a[R--]);
        ans[id] = (f == 0);
    }
    for (int x : ans) 
    {
        if (x) YES;
        else NO;
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