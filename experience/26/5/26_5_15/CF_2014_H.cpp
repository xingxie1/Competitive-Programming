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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    vt a(n + 1),b;
    for (int i = 1;i <= n;i++) 
    {
        cin >> a[i];
        b.push_back(a[i]);
    }
    ranges::sort(b);
    b.erase(unique(b.begin(),b.end()),b.end());
    for (int i = 1;i <= n;i++) 
    {
        a[i] = ranges::lower_bound(b,a[i]) - b.begin() + 1;
    }
    int B = sqrt(n) + 1;

    vector<Query> qs(q);
    for (int i = 0;i < q;i++) 
    {
        cin >> qs[i].l >> qs[i].r;
        qs[i].id = i;
    }
    sort(qs.begin(),qs.end(),[&](auto& x,auto& y){
        int bx = x.l / B;
        int by = y.l / B;
        if (bx != by ) return bx < by;
        if (bx & 1) return x.r > y.r;
        return x.r < y.r;
    });
    int L = 1,R = 0;
    vt ans(q);
    ll odd = 0;
    vt cnt(n + 1);
    auto add = [&](int x)
    {
        if (cnt[x] & 1) odd--;
        else odd++;
        cnt[x]++;
    };
    auto del = [&](int x)
    {
        if (cnt[x] & 1) odd--;
        else odd++;
        cnt[x]--;
    };
    for (auto& [l,r,id] : qs)
    {
        while (L > l) add(a[--L]);
        while (R < r) add(a[++R]);
        while (R > r) del(a[R--]);
        while (L < l) del(a[L++]);
        ans[id] = (odd == 0);
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
    cin >> _;
    while (_ --) solve();

    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// using vt = vector<int>;
// using vvt = vector<vector<int>>;
// using vll = vector<long long>;
// using vvll = vector<vector<long long>>;
// using pii = pair<int,int>;
// using pll = pair<ll,ll>;
// using vpii = vector<pair<int,int>>;
// using vpll = vector<pair<ll,ll>>;
// using vvpii = vector<vector<pair<int,int>>>;
// using vvpll = vector<vector<pair<ll,ll>>>;
// #define YES cout << "YES" << endl
// #define NO cout << "NO" << endl
// #define fi first
// #define se second
// #define umap unordered_map
// #define pqueue priority_queue
// #define mset multiset
// #define endl '\n'
// //cout << fixed << setprecision(10);
// //const int MOD = 998244353;
// //const int MOD = (int)1e9+7;

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// ll get_rand()
// {
//     ll x = rng();
//     while (x == 0) x = rng();
//     return x;
// }
// const int MX = 1e6 + 5;
// ll h1[MX],h2[MX];
// void solve()
// {
//     int n,q;
//     cin >> n >> q;
//     vt a(n);
//     for (int i = 0;i < n;i++) cin >> a[i];
//     vll pre1(n + 1),pre2(n + 1);
//     for (int i = 0;i < n;i++)
//     {
//         int x = a[i];
//         if (h1[x] == 0) 
//         {
//             h1[x] = get_rand();
//             h2[x] = get_rand();
//         }
//         pre1[i + 1] = pre1[i] ^ h1[x];
//         pre2[i + 1] = pre2[i] ^ h2[x];
//     }
//     while (q--) 
//     {
//         int l,r;
//         cin >> l >> r;
//         ll v1 = pre1[r] ^ pre1[l - 1];
//         ll v2 = pre2[r] ^ pre2[l - 1];
//         if (v1 == 0 && v2 == 0) YES;
//         else NO;
//     }   
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int _ = 1;
//     cin >> _;
//     while (_ --) solve();

//     return 0;
// }