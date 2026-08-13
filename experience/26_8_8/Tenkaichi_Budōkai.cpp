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

// 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
// 根据题目用 FenwickTree<int> t(n) 或者 FenwickTree<long long> t(n) 初始化
template<typename T = int >
class FenwickTree {
    vector<T> tree;

public:
    // 使用下标 1 到 n
    FenwickTree(int n) : tree(n + 1) {}

    // a[i] 增加 val
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    void update(int i, T val) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += val;
        }
    }

    // 求前缀和 a[1] + ... + a[i]
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    T pre(int i) const {
        T res = 0;
        for (; i > 0; i &= i - 1) {
            res += tree[i];
        }
        return res;
    }

    // 求区间和 a[l] + ... + a[r]
    // 1 <= l <= r <= n
    // 时间复杂度 O(log n)
    T query(int l, int r) const {
        if (r < l) {
            return 0;
        }
        return pre(r) - pre(l - 1);
    }

    // 找到最小的下标 pos，满足 a[1] + ... + a[pos] >= k
    // 要求树状数组中维护的是频率/个数，并且 k >= 1 且 k <= pre(n)
    // 时间复杂度 O(log n)
    int kth(T k) const {
        int pos = 0;
        int bit = 1;

        while ((bit << 1) < tree.size()) {
            bit <<= 1;
        }

        for (; bit; bit >>= 1) {
            int nxt = pos + bit;

            if (nxt < tree.size() && tree[nxt] < k) {
                pos = nxt;
                k -= tree[nxt];
            }
        }

        return pos + 1;
    }
};

void solve()
{
    int n,x;
    cin >> n >> x;
    vt p(n + 1),q(n + 1);
    vt posp(n + 1),posq(n + 1);
    for (int i = 1;i <= n;i++)
    {
        cin >> p[i];
        posp[p[i]] = i;
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> q[i];
        posq[q[i]] = i;
    }
    int mx = 0;
    for (int i = 1;i < n;i++)
    {
        mx = max(mx,posq[p[i]]);
        if (i == mx) 
        {
            NO;
            return ;
        }
    }
    for (int y = 1;y <= n;y++)
    {
        if (x == y) continue;
        if (posp[y] > posp[x] && posq[y] > posq[x]) 
        {
            NO;
            return ;
        }
    }
    FenwickTree tr1(n),tr2(n);
    for (int i = 1;i <= n;i++) 
    {
        tr1.update(i,1);
        tr2.update(i,1);
    }
    int i = 1,j = 1;
    vt del(n + 1);
    vt ans;
    for (int r = 1;r < n;r++)
    {
        while (del[p[i]]) i++;
        while (del[q[j]]) j++;
        int u = p[i];
        int v = q[j];
        if (u == v)
        {
            NO;
            return ;
        }
        int z;
        if (u == x) 
        {
            z = v;
            j++;
        }
        else if (v == x) 
        {
            z = u;
            i++;
        }
        else 
        {
            int pu = tr1.pre(posq[u]);
            int qv = tr2.pre(posp[v]);
            if (pu < qv) 
            {
                z = u;
                i++;
            }
            else 
            {
                z = v;
                j++;
            }
        }
        ans.push_back(z);
        del[z] = 1;
        tr1.update(posp[z],-1);
        tr2.update(posq[z],-1);
    }
    YES;
    for (int x : ans) cout << x << " ";
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