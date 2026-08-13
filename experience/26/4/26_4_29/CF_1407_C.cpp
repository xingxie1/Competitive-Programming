#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
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
#define pqueue priority_queue
#define mset multiset
// #define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    auto query = [&](int i,int j)
    {
        cout << "? " << i << " " << j << endl;
        int ret;
        cin >> ret;
        return ret;
    };
    int l = 1,r = 2;
    while (r <= n && l < r)
    {
        int r1 = query(l,r);
        int r2 = query(r,l);
        if (r1 < r2) 
        {
            a[r - 1] = r2;
            r++;
        }
        else 
        {
            a[l - 1] = r1;
            l = r;
            r++;
        }
    }   
    cout << "! ";
    for (int& x : a) 
    {
        if (!x) 
        {
            x = n;
            break;
        }
    }
    for (int x : a) cout << x << " ";
    cout << endl;
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