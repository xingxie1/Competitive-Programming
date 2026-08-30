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

void solve()
{
    int n,k;
    cin >> n >> k;
    set<vt> st;
    for (int x = 0;x * n <= k;x++) 
    {
        vt tmp = {x * n,x};
        st.insert(tmp);
    }
    if (n == 1)
    {
        cout << k << endl;
        return ;
    }
    while (1) 
    {
        set<vt> nst;
        auto tt = *st.begin();
        if (tt.size() == n) 
        {
            for (auto& a : st)
            {
                vt tmp = a;
                tmp[0] += k - a[0];
                tmp.push_back(k - a[0]);
                nst.insert(tmp);
            }
            st = nst;
            break;
        }
        for (auto& a : st) 
        {
            int i = a.size();
            i = n - i + 1; 
            vt tmp = a;
            for (int x = 0;x * i + a[0] <= k;x++)
            {
                tmp.push_back(x);
                tmp[0] += x * i;
                nst.insert(tmp);
                tmp[0] -= x * i;
                tmp.pop_back();
            }
        }
        st = nst;
    }
    vvt ans;
    for (auto& a : st)
    {
        if (a[0] != k) continue;
        vt tmp;
        for (int i = 1;i <= n;i++) tmp.push_back(a[i]);
        ranges::reverse(tmp);
        ans.push_back(tmp);
    }
    ranges::sort(ans);
    for (int i = 0;i < ans.size();i++)
    {
        for (int x : ans[i]) cout << x << " ";
        cout << endl;
    }
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