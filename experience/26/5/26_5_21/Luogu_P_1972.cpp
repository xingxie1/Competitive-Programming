#include<bits/stdc++.h>
using namespace std;
// typedef long long ll;
// using vt = vector<int>;
// using vd = vector<double>;
// using vll = vector<long long>;
// using vvt = vector<vector<int>>;
// using vvd = vector<vector<double>>;
// using vvll = vector<vector<long long>>;
// using pii = pair<int,int>;
// using pll = pair<ll,ll>;
// using vpii = vector<pair<int,int>>;
// using vpll = vector<pair<ll,ll>>;
// using vvpii = vector<vector<pair<int,int>>>;
// using vvpll = vector<vector<pair<ll,ll>>>;
// #define YES cout << "Yes" << endl
// #define NO cout << "No" << endl
// #define fi first
// #define se second
// #define umap unordered_map
// #define pqueue priority_queue
// #define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

const int N = 1000005;
int a[N];
int ans[N];
int cnt[N];
struct query{
    int l,r,id;
};
void solve()
{
    int n, q;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    cin >> q;
    int B = sqrt(n) + 1;
    vector<query> qs(q);
    for (int i = 0;i < q;i++) 
    {
        int l, r;
        cin >> l >> r;
        qs[i] = {l,r,i};
    }
    sort(qs.begin(),qs.end(),[&](auto& x,auto& y){
        int bx = x.l / B;
        int by = y.l / B;
        if (bx != by) return bx < by;
        if (bx & 1) return x.r > y.r;
        else return x.r < y.r;
    });
    int L = 1,R = 0;
    int sum = 0;
    auto add = [&](int x)
    {
        cnt[x]++;
        if (cnt[x] == 1) sum++;
    };
    auto del = [&](int x)
    {
        cnt[x]--;
        if (cnt[x] == 0) sum--;
    };
    for (auto& [l,r,id] : qs)
    {
        while (L > l) add(a[--L]);
        while (R < r) add(a[++R]);
        while (L < l) del(a[L++]);
        while (R > r) del(a[R--]);
        ans[id] = sum; 
    }
    for (int i = 0;i < q;i++) cout << ans[i] << endl;
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