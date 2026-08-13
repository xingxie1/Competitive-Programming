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
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < n;j++) a[i] += '.';
    }
    vpii b(m);
    for (int i = 0;i < m;i++) cin >> b[i].fi >> b[i].se;
    auto check = [&](char t,int x,int y) 
    {
        int cnt = 0;
        for (int j = y;j < n;j++)
        {
            if (a[x][j] == t) cnt++;
            else break;
        }
        for (int j = y - 1;j >= 0;j--) 
        {
            if (a[x][j] == t) cnt++;
            else break;
        }
        if (cnt >= 5) return true;
        cnt = 0;
        for (int i = x;i < n;i++) 
        {
            if (a[i][y] == t) cnt++;
            else break;
        }
        for (int i = x - 1;i >= 0;i--) 
        {
            if (a[i][y] == t) cnt++;
            else break;
        }
        if (cnt >= 5) return true;
        cnt = 0;
        for (int d = 1;x - d >= 0 && y - d >= 0;d++)
        {
            if (a[x - d][y - d] == t) cnt++;
            else break;
        }
        for (int d = 0;x + d < n && y + d < n;d++)
        {
            if (a[x + d][y + d] == t) cnt++;
            else break;
        }
        if (cnt >= 5) return true;
        cnt = 0;
        for (int d = 1;x + d < n && y - d >= 0;d++)
        {
            if (a[x + d][y - d] == t) cnt++;
            else break;
        }
        for (int d = 0;x - d >= 0 && y + d < n;d++)
        {
            if (a[x - d][y + d] == t) cnt++;
            else break;
        }
        return cnt >= 5;
    };
    for (int i = 0;i < m;i++) 
    {
        int x = b[i].fi,y = b[i].se;
        x--;y--;
        if (i % 2 == 0) 
        {
            a[x][y] = 'H';
            if (check('H',x,y)) 
            {
                cout << "HtBest " << i + 1 << endl;
                return ;
            }
        }
        else
        {
            a[x][y] = 'W';
            if (check('W',x,y)) 
            {
                cout << "WHZ " << i + 1 << endl;
                return ;
            }
        }
    }
    cout << "UNK " << m << endl;
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