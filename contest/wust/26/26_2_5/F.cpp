#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    ll n;
    cin >> n;
    cout << (n << (bit_width((uint32_t) n) - __builtin_ctz(n))) << " " << (n + (n << (bit_width((uint32_t) n)) - __builtin_ctz(n))) << endl;

    // ll ansx = 0,ansy = 0;
    // unordered_set<ll> s;
    // for (ll n = 100;n < 10000000;n++)
    // {
    //     for (ll x = n;;x += n)
    //     {
    //         ll y = x,x1 = x;
    //         int flag = 0;
    //         while (x1 > 0)
    //         {
    //             if (s.contains(x1) && gcd(x1,y) == n && x1 != y)
    //             {
    //                 ansx = x1;
    //                 ansy = y;
    //                 flag = 1;
    //             }
    //             x1 -= (x1 & -x1);
    //         }
    //         s.insert(y);
    //         if (flag) break;
    //     }
    //     bitset<32> n1 = n;
    //     cout << ansx << " " << ansy << endl;
    //     cout << n << endl << n1 << endl;
    //     bitset<32> a1 = ansx,a2 = ansy;
    //     cout << a1 << endl << a2 << endl;
    //     cout << "@@@" << endl;
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