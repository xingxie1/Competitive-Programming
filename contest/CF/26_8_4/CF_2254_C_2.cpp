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
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    if (a == b) 
    {
        cout << 0 << endl;
        return ;
    }
    if (n < 3) 
    {
        cout << -1 << endl;
        return ;
    }
    int a0 = 0,b0 = 0;
    for (char c : a) a0 += (c == '0');
    for (char c : b) b0 += (c == '0');
    if (a0 != b0) 
    {
        cout << -1 << endl;
        return ;
    }
    set<int> p1,p0;
    for (int i = 0;i < n;i++)
    {
        if (a[i] == '1' && i % 2 == 0) p0.insert(i);
        else if (a[i] == '1' && i % 2) p1.insert(i);
    }
    ll ans = 0;
    for (int i = 0;i < n;i++) 
    {
        if (b[i] == '0') continue;
        if (i % 2 == 0) 
        {
            if (p0.size()) 
            {
                int j = *p0.begin();
                ans += abs(i - j) / 2;
                p0.erase(p0.begin());
            }
            else 
            {
                cout << -1 << endl;
                return ;
            }
        }
        else 
        {
            if (p1.size()) 
            {
                int j = *p1.begin();
                ans += abs(i - j) / 2;
                p1.erase(p1.begin());
            }
            else 
            {
                cout << -1 << endl;
                return ;
            }
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