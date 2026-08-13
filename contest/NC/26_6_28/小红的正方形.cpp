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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    auto f = [&](int& x1,int& y1,int& x2,int& y2)
    {
        if (x1 > x2) 
        {
            swap(x1,x2);
            swap(y1,y2);
        }
        if (y1 > y2) 
        {
            swap(y1,y2);
        }
    };
    f(x1,y2,x2,y2);
    f(x3,y3,x4,y4);
    if ((x1 == x4 && y1 == y4) || (x2 == y2 && x3 == y3)) cout << 1 << endl;
    else if (x1 == x3 || y1 == y3 || x2 == x4 || y2 == y4 || x1 == x4 || y1 == y4 || x2 == x4 || y2 == y4) 
    {
        cout << "inf" << endl;
    }
    else if ((x3 < x1 && y3 < y1 && x4 > x2 && y4 > y2) || (x3 > x1 && y3 > y1 && x4 < x2 && y4 < y2) )
    {
        cout << 0 << endl;
    }
    else cout << 2 << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}