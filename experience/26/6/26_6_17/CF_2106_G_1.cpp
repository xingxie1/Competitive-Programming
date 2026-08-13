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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
// #define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) 
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
    }
    auto ask = [&](vt& a) 
    {
        cout << "? 1 " << a.size() << " ";
        for (int x : a) cout << x << " ";
        cout << endl;
        int res;
        cin >> res;
        return res;
    };
    auto flip =[&](int u) -> void
    {
        cout << "? 2 " << u << endl;
    };
    int s1;
    vt tmp = {1};
    s1 = ask(tmp);
    vt ans(n);
    if (abs(s1) == 1) 
    {
        ans[0] = s1;
        for (int i = 2;i <= n;i++) 
        {
            vt tmp = {i};
            int si = ask(tmp);
            ans[i - 1] = si - s1;
        }
    }
    else 
    {
        vt a;
        for (int i = 2;i <= n;i++) a.push_back(i);
        int l = 0,r = a.size();
        while (l + 1 < r) 
        {
            int m = (l + r) / 2 ;
            vt q;
            for (int i = 1;i <= m;i++) q.push_back(a[i - 1]);
            int ss1 = ask(q);
            flip(1);
            int ss2 = ask(q);
            flip(1);
            int len = q.size();
            if (abs(ss1 - ss2) != 2 * len) r = m;
            else l = m;
        }
        int root = a[r - 1];
        vt tt = {root};
        int sr = ask(tt);
        ans[root - 1] = sr;
        int a1;
        tt = {1};
        a1 = ask(tt);
        ans[0] = a1 - sr;
        for (int i = 2;i <= n;i++) 
        {
            if (i == root) continue;
            vt q = {i};
            int s = ask(q);
            ans[i - 1] = s - ans[0] - sr;
        }
    }
    cout << "! ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    return ;
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