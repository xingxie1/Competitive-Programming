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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    ll x;
    cin >> x;
    if (x <= 2) 
    {
        NO;
        return ;
    }
    int cnt = 0;
    if (x == 4)
    {
        YES;
        cout << "3 4 5" << endl;
        return ;        
    }
    if (x % 4 == 0) 
    {
        YES;
        int t = x / 4;
        cout << x << " " << t * x - 1 << " " << t * x + 1 << endl;
        return ;
    }
    while (x % 2 == 0)
    {
        x /= 2;
        cnt++;
    }
    if (x != 1 && x % 2 == 1)
    {
        YES;
        int t = (x - 1) / 2;
        int p2 = 1 << cnt;
        cout << p2 * x << " " << p2 * (t * x + t) << " " << p2 * (t * x + t + 1) << endl;
        return ;
    }
    else if ((x + 1) / 2 % 4 == 0) 
    {
        YES;
        x = (x + 1) / 2;
        x *= 1LL << cnt;
        cout << x << " " << 2 * x - 1 << " " << 2 * x + 1 << endl;
        return ;
    }
    else if ((x - 1) / 2 % 4 == 0)
    {
        YES;
        x = (x - 1) / 2;
        x *= 1LL << cnt;
        cout << x << " " << 2 * x - 1 << " " << 2 * x + 1 << endl;
        return ;
    }
    NO;
    // for (int i = 1;i <= 1e3;i++)
    // {
    //     for (int j = i + 1;j <= 1e3;j++)
    //     {
    //         ll s = i * i + j * j;
    //         ll r = sqrt(s);
    //         if (r * r == s && i + j > r) 
    //         {
    //             cout << i << " " << j << " " << r << endl;
    //         }
    //     }
    // }
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