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
// const int MOD = 998244353;
//const int MOD = (int)1e9+7;
// ll MOD = 1LL << 32;

// 计算并返回 z 数组，其中 z[i] = |LCP(s[i:], s)|
vector<int> calc_z(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int box_l = 0, box_r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= box_r) {
            z[i] = min(z[i - box_l], box_r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            box_l = i;
            box_r = i + z[i];
            z[i]++;
        }
    }
    z[0] = n;
    return z;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vt z = calc_z(s);
    vt pre(26);
    for (int i = 1;i < n;i++)
    {
        if (i + z[i] == n) 
        {
            cout << 0 << endl;
            return ;
        }
        int L = z[i];
        pre[s[L + i] - 'a'] |= 1 << (s[L] - 'a');
    }
    int N = 1 << 26;
    vector<uint32_t> f(N);
    f[0] = 1;
    for (int mask = 0;mask < N;mask++)
    {
        for (int i = 0;i < 26;i++) 
        {
            if (mask >> i & 1) continue;
            if ((pre[i] & mask) == pre[i]) 
            {
                f[mask | (1 << i)] += f[mask];
            }
        }
    }
    cout << (ull)f[N - 1] << endl;
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