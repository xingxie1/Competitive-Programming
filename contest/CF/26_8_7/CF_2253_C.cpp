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
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    set<int> st,sta,stb;
    for (int i = 0;i < x;i++) 
    {
        int a;
        cin >> a;
        st.insert(a);
        sta.insert(a);
    }
    for (int i = 0;i < y;i++) 
    {
        int a;
        cin >> a;
        st.insert(a);
        stb.insert(a);
    }
    int N = n + m - 1;
    int cn = 0,cm = 0,cnt = 0;
    ll ans = 0;
    while (cnt < N && !st.empty())
    {
        int x = *(--st.end());
        if (sta.contains(x) && stb.contains(x)) 
        {
            ans += x;
            sta.erase(x);
            stb.erase(x);
            st.erase(x);
            cnt++;
        }
        else if (sta.contains(x)) 
        {
            if (cn < n) 
            {
                cn++;
                cnt++;
                ans += x;
            }
            sta.erase(x);
            st.erase(x);
        }
        else 
        {
            if (cm < m) 
            {
                cm++;
                cnt++;
                ans += x;
            }
            stb.erase(x);
            st.erase(x);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}