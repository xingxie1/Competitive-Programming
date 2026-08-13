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
    int px,py,ax,ay,bx,by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    int dpax = px - ax,dpay = py - ay;
    int dpbx = px - bx,dpby = py - by;
    int dabx = ax - bx,daby = ay - by;
    double dpa = sqrt(dpax * dpax + dpay * dpay);
    double dpb = sqrt(dpbx * dpbx + dpby * dpby);
    double dab = sqrt(dabx * dabx + daby * daby);
    double dao = sqrt(ax * ax + ay * ay);
    double dbo = sqrt(bx * bx + by * by);
    double ans = min(max(dao,dpa),max(dbo,dpb));
    double l = -1,r = 1e4;
    auto check = [&](double m) 
    {
        if (dpa > m && dpb > m) return false;
        if (dao > m && dbo > m) return false;
        if (dab > 2 * m) return false;
        return true;
    };
    int cnt = 0;
    while (cnt < 100) 
    {
        double m = l + (r - l) / 2.0;
        if (check(m)) r = m;
        else l = m;
        cnt++;
    }
    cout << fixed << setprecision(10);
    cout << min(r,ans) << endl;
    // cout << r << endl;
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