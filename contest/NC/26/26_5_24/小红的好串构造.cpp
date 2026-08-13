#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
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
    int n,k;
    cin >> n >> k;
    string s(n,' ');
    for (ll x = 1;x <= 2;x++) 
    {
        for (ll y = 1;y <= n;y++) 
        {
            ll m = n - x - y;
            int res = 0;
            if (m > 0) res = y + m - 1;
            if (x * y + res == k) 
            {
                for (int i = 0;i < x;i++) s[i] = 'a';
                for (int i = x;i < x + y;i++) s[i] = 'b';
                char c = 'c';
                for (int i = x + y;i < n;i++) 
                {
                    s[i] = c;
                    c++;
                    if (c > 'e') c -= 3;
                }
                cout << s << endl;
                return ;
            }
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