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
    if (n == 1) 
    {
        if (k == 1) 
        {
            YES;
            cout << 0 << endl;
        }
        else NO;
        return ;
    }
    int t = n ^ k;
    if (bit_width(1u * t) > bit_width(1u * (n - 1))) 
    {
        NO;
        return ;
    }
    if (t == 0) 
    {
        YES;
        for (int i = 1;i <= n;i++) cout << n - i << " ";
        cout << endl;
    }
    else if (t < n) 
    {
        YES;
        for (int i = 1;i < t;i++) cout << i << " ";
        for (int i = t + 1;i < n;i++) cout << i << " ";
        cout << 0 << " " << t << endl;
    }
    else 
    {
        int a = t ^ (n - 1);
        YES;
        for (int i = 1;i < n - 1;i++) 
        {
            if (i == a) continue;
            cout << i << " ";
        }
        cout << 0 << " " << a << " " << n - 1 << endl;
    }
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