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
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
// #define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    for (int i = 2;i < 2 * n;i+=2)
    {
        cout << "? " << i << " " << i + 1 << endl;
        int a;
        cin >> a;
        if (a == 1) 
        {
            cout << "! " << i << endl;
            return ;
        }
    }
    int a;
    cout << "? 2 " << 2 * n << endl;
    cin >> a;
    if (a == 1) 
    {
        cout << "! 2" << endl;
        return ;
    }
    cout << "? 3 " << 2 * n << endl;
    cin >> a;
    if (a == 1)
    {
        cout << "! 3" << endl;
        return ;
    }
    cout << "! 1" << endl;
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