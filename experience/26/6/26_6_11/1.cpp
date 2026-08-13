#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int x,y;
    cin >> x >> y;
    if (x == 0) 
    {
        if (y % 3 == 0) cout << "awsl" << endl;
        else cout << "yyds" << endl;
    }
    else if (y == 0) 
    {
        if (x % 3 == 0) cout << "awsl" << endl;
        else cout << "yyds" << endl;
    }
    else 
    {
        if (x % 3 == 0 && y % 3 == 0) cout << "awsl" << endl;
        else if (x % 3 && y % 3 == 0) cout << "yyds" << endl;
        else if (x % 3 == 0 && y % 3) cout << "yyds" << endl;
        else 
        {
            cout << "awsl" << endl;
            // if (x % 3 == 2 && y % 3 == 2) cout << "yyds" << endl;
            // else cout << "awsl" << endl;
        }
    }
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