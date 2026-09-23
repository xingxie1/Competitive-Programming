#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
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
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

struct Query
{
    int l,r,a,b,id;
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
        cin >> qs[i].l >> qs[i].r >> qs[i].a >> qs[i].b;
        qs[i].id = i;
    }
    int B = sqrt(n) + 1;
    sort(qs.begin(), qs.end(), [&](auto& x,auto& y)
    {
        int bx = x.l / B;
        int by = y.l / B;
        if (bx != by) return bx < by;
        if (bx & 1) return x.r > y.r;
        return x.r < y.r;
    });
    vpii ans(q);
    int L = 1,R = 0;
    B = sqrt(100005) + 1;
    int cc = 100005 / B;
    vt cnt(100005);
    vt sum1(cc);
    vt sum2(cc);
    auto bel = [&](int x)
    {
        return (x - 1) / B;
    };
    auto add = [&](int x)
    {
        cnt[x]++;
        sum1[bel(x)]++;
        if (cnt[x] == 1) sum2[bel(x)]++;
    };
    auto del = [&](int x)
    {
        cnt[x]--;
        sum1[bel(x)]--;
        if (cnt[x] == 0) sum2[bel(x)]--;
    };
    for (auto&[l, r,aa,bb,id] : qs)
    {
        while (L > l) add(a[--L]);
        while (R < r) add(a[++R]);
        while (L < l) del(a[L++]);
        while (R > r) del(a[R--]);

        int res1 = 0,res2 = 0;
        int bl = bel(aa),br = bel(bb);
        if (bl == br)
        {
            for (int x = aa;x <= bb;x++)
            {
                res1 += cnt[x];
                res2 += (cnt[x] > 0);
            }
        }
        else 
        {
            for (int b = bl + 1;b <= br - 1;b++) 
            {
                res1 += sum1[b];
                res2 += sum2[b];
            }
            for (int x = aa;x <= bl * B + B;x++)
            {
                res1 += cnt[x];
                res2 += (cnt[x] > 0);
            }
            for (int x = br * B + 1;x <= bb;x++)
            {
                res1 += cnt[x];
                res2 += (cnt[x] > 0);
            }
        }
        ans[id] = {res1,res2};
    }
    for (auto& [x,y] : ans) cout << x << " " << y << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// using i128 = __int128_t;
// using vt = vector<int>;
// using vd = vector<double>;
// using vll = vector<long long>;
// using vvt = vector<vector<int>>;
// using vvd = vector<vector<double>>;
// using vvll = vector<vector<long long>>;
// using vvvt = vector<vector<vector<int>>>;
// using vvvll = vector<vector<vector<long long>>>;
// using pii = pair<int,int>;
// using pll = pair<ll,ll>;
// using pdd = pair<double,double>;
// using vpii = vector<pair<int,int>>;
// using vpll = vector<pair<ll,ll>>;
// using vpdd = vector<pair<double,double>>;
// using vvpii = vector<vector<pair<int,int>>>;
// using vvpll = vector<vector<pair<ll,ll>>>;
// using tri = tuple<int,int,int>;
// using trl = tuple<ll,ll,ll>;
// using vtri = vector<tuple<int,int,int>>;
// using vtrl = vector<tuple<ll,ll,ll>>;
// #define YES cout << "YES" << endl
// #define Yes cout << "Yes" << endl
// #define NO cout << "NO" << endl
// #define No cout << "No" << endl
// #define fi first
// #define se second
// #define umap unordered_map
// #define uset unordered_set
// #define pqueue priority_queue
// #define mset multiset
// #define endl '\n'
// //const int MOD = 998244353;
// //const int MOD = (int)1e9+7;

// struct Query
// {
//     int l,r,a,b,id;
// };

// // 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
// // 根据题目用 FenwickTree<int> t(n) 或者 FenwickTree<long long> t(n) 初始化
// template<typename T = int >
// class FenwickTree {
//     vector<T> tree;

// public:
//     // 使用下标 1 到 n
//     FenwickTree(int n) : tree(n + 1) {}

//     // a[i] 增加 val
//     // 1 <= i <= n
//     // 时间复杂度 O(log n)
//     void update(int i, T val) {
//         for (; i < tree.size(); i += i & -i) {
//             tree[i] += val;
//         }
//     }

//     // 求前缀和 a[1] + ... + a[i]
//     // 1 <= i <= n
//     // 时间复杂度 O(log n)
//     T pre(int i) const {
//         T res = 0;
//         for (; i > 0; i &= i - 1) {
//             res += tree[i];
//         }
//         return res;
//     }

//     // 求区间和 a[l] + ... + a[r]
//     // 1 <= l <= r <= n
//     // 时间复杂度 O(log n)
//     T query(int l, int r) const {
//         if (r < l) {
//             return 0;
//         }
//         return pre(r) - pre(l - 1);
//     }

//     // 找到最小的下标 pos，满足 a[1] + ... + a[pos] >= k
//     // 要求树状数组中维护的是频率/个数，并且 k >= 1 且 k <= pre(n)
//     // 时间复杂度 O(log n)
//     int kth(T k) const {
//         int pos = 0;
//         int bit = 1;

//         while ((bit << 1) < tree.size()) {
//             bit <<= 1;
//         }

//         for (; bit; bit >>= 1) {
//             int nxt = pos + bit;

//             if (nxt < tree.size() && tree[nxt] < k) {
//                 pos = nxt;
//                 k -= tree[nxt];
//             }
//         }

//         return pos + 1;
//     }
// };

// void solve()
// {
//     int n,q;
//     cin >> n >> q;
//     vt a(n + 1);
//     for (int i = 1;i <= n;i++) cin >> a[i];
//     int B = sqrt(n) + 1;
//     vector<Query> qs(q);
//     for (int i = 0;i < q;i++)
//     {
//         cin >> qs[i].l >> qs[i].r >> qs[i].a >> qs[i].b;
//         qs[i].id = i;
//     }
//     sort(qs.begin(), qs.end(), [&](auto& x,auto& y)
//     {
//         int bx = x.l / B;
//         int by = y.l / B;
//         if (bx != by) return bx < by;
//         if (bx & 1) return x.r > y.r;
//         return x.r < y.r;
//     });
//     vpii ans(q);
//     int L = 1,R = 0;
//     FenwickTree tr1(1e5),tr2(1e5);
//     auto add = [&](int x,int a,int b)
//     {
//         tr1.update(x,1);
//         if (tr2.query(x,x) == 0) tr2.update(x,1);
//     };
//     auto del = [&](int x,int a,int b)
//     {
//         tr1.update(x,-1);
//         if (tr1.query(x,x) == 0) tr2.update(x,-1);
//     };
//     for (auto&[l, r,aa,bb,id] : qs)
//     {
//         while (L > l) add(a[--L],aa,bb);
//         while (R < r) add(a[++R],aa,bb);
//         while (L < l) del(a[L++],aa,bb);
//         while (R > r) del(a[R--],aa,bb);

//         ans[id] = {tr1.query(aa,bb),tr2.query(aa,bb)};
//     }
//     for (auto& [x,y] : ans) cout << x << " " << y << endl;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cout << fixed << setprecision(15);
//     int _ = 1;
//     // cin >> _;
//     while (_ --) solve();

//     return 0;
// }