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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

double rand_real(double a, double b)
{
    uniform_real_distribution<double> dist(a, b);
    return dist(rng);
}

void solve()
{
    int n,t;
    cin >> n >> t;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    vt aa,bb;
    set<int> st;
    for (int x : a) 
    {
        if (x == t) 
        {
            aa.push_back(x);
            break;
        }
        st.insert(x);
        aa.push_back(x);
    }
    for (int x : b) 
    {
        if (x == t) 
        {
            bb.push_back(x);
            break;
        }
        st.insert(x);
        bb.push_back(x);
    }
    if (st.size() != n - 1)
    {
        NO;
        return ;
    }
    a = aa;
    b = bb;
    n = a.size();
    int m = b.size();
    int l = 0,r = 0;
    int d1 = 0,d2 = 0;
    set<int> used;
    vt ans;
    // for (int x : a) cout << x << " ";
    // cout << endl;
    // for (int x : b) cout << x << " ";
    // cout << endl;
    while (l < n && r < m)
    {
        while (l < n && used.contains(a[l])) 
        {
            d1 = 0;
            l++;
        }
        while (r < m && used.contains(b[r])) 
        {
            d2 = 0;
            r++;
        }
        // if (l == n || r == m) break;
        if (a[l] == t && b[r] == t) break;
        if (a[l] == b[r]) 
        {
            NO;
            return;
        }
        if (a[l] == t) 
        {
            ans.push_back(b[r]);
            used.insert(b[r]);
            r++;
            continue;
        }
        if (b[r] == t) 
        {
            ans.push_back(a[l]);
            used.insert(a[l]);
            l++;
            continue;
        }
        if (l + d1 + 1 < n && r + d2 + 1 < m)
        {
            if (a[l + d1 + 1] == b[r] && b[r + d2 + 1] == a[l]) 
            {
                NO;
                return ;
            }
            if (a[l + d1 + 1] == b[r])
            {
                ans.push_back(b[r]);
                used.insert(b[r]);
                r += d2 + 1;
                d2 = 0;
                d1++;
                continue;
            }
            if (b[r + d2 + 1] == a[l])
            {
                ans.push_back(a[l]);
                used.insert(a[l]);
                l += d1 + 1;
                d1 = 0;
                d2++;
                continue;
            }
            int x = rng() % 2;
            if (x)
            {
                ans.push_back(a[l]);
                used.insert(a[l]);
                l += d1 + 1;
                d1 = 0;
            }
            else 
            {
                ans.push_back(b[r]);
                used.insert(b[r]);
                r += d2 + 1;
                d2 = 0;
            }
        }
        else if (l + d1 + 1 < n)
        {
            ans.push_back(a[l]);
            used.insert(a[l]);
            l += d1 + 1;
            d1 = 0;
        }
        else if (r + d2 + 1 < m)
        {
            ans.push_back(b[r]);
            used.insert(b[r]);
            r += d2 + 1;
            d2 = 0;
        }
    }
    YES;
    for (int x : ans) cout << x << " ";
    cout << endl;
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