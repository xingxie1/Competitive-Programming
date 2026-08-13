#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    // auto f = [&](ll x)
    // {
    //     ll ret = 1;
    //     if (x == 0) return 0LL;
    //     while (x)
    //     {
    //         ret *= (x % 10);
    //         x /= 10;
    //     }
    //     return ret;
    // };
    // auto g = [&](this auto&& self, ll x)
    // {
    //     if (x == f(x)) return 0;
    //     x = f(x);
    //     return 1 + self(x);  
    // };
    // ll mx = 0,a = 77777999999999982,b = 0;
    // for (int i = 0;i < 40;i++)
    // {
    //     for (int j = 0;j < 40;j++)
    //     {
    //         for (int k = 0;k < 40;k++)
    //         {
    //             string s;
    //             int n1 = i,n2 = j,n3 = k;
    //             while (n3--) s+='7';
    //             while (n2 >= 2)
    //             {
    //                 n2 -= 2;
    //                 s += '9';
    //             }
    //             while (n1 >= 3)
    //             {
    //                 s += '8';
    //                 n1 -= 3;
    //             }
    //             while (n1 >= 1 && n2 >= 1) 
    //             {
    //                 n1--;
    //                 n2--;
    //                 s += '6';
    //             }
    //             while (n1 >= 2)
    //             {
    //                 n1 -= 2;
    //                 s += '4';
    //             }
    //             while (n1--) s += '2';
    //             while (n2--) s += '3';
    //             if (s.size() > 18 || s.size() == 0) continue;
    //             ll x = stoll(s);
    //             if (g(x) > mx && x != a)
    //             {
    //                 b = x;
    //                 mx = g(x);
    //             }
    //         }
    //     }
    // }
    // cout << a << " " << b << endl;
    cout << "77777999999999982 777777998888882";
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