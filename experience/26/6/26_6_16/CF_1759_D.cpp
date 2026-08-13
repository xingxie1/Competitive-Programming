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
    ll n,m;
    cin >> n >> m;
    int c2 = 0,c5 = 0;
    int x = n;
    while (x % 2 == 0) 
    {
        c2++;
        x /= 2;
    }
    while (x % 5 == 0) 
    {
        c5++;
        x /= 5;
    }
    // cout << c2 << " " << c5 << endl;
    if (m == 1 && c2 == 0 && c5 == 0) cout << n * m << endl;
    else if (m <= 4 && c5 == 0) cout << n * m << endl;
    else 
    {
        if (c2 == c5) 
        {
            ll s = 1;
            while (s * 10 <= m) s *= 10;
            ll mx = s;
            for (int i = 2;;i++) 
            {
                if (s * i <= m) mx = max(mx,s * i);
                else break;
            }
            cout << n * mx << endl;
        }
        else if (c2 > c5) 
        {
            int d = c2 - c5;
            ll s = 1;
            while (d-- && s * 5 <= m) s *= 5;
            while (s * 10 <= m) s *= 10;
            ll mx = s;
            for (int i = 2;;i++) 
            {
                if (s * i <= m) mx = max(mx,s * i);
                else break;
            }
            cout << n * mx << endl;
        }
        else 
        {
            int d = c5 - c2;
            ll s = 1;
            while (d-- && s * 2 <= m)
            {
                s *= 2;
            }
            while (s * 10 <= m) s *= 10;
            ll mx = s;
            for (int i = 2;;i++) 
            {
                if (s * i <= m) mx = max(mx,s * i);
                else break;
            }
            // cout << s << endl;
            cout << n * mx << endl;
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