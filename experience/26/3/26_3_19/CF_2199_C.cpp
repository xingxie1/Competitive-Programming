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
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int k;
    cin >> k;
    if (k == 1)
    {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << "*" << endl;
        cout << "." << endl;
        return ;
    }

    if (!(k % 5 == 0 || (k - 3) % 5 == 0 || (k - 6) % 5 == 0)) 
    {
        cout << "NO" << endl;
        return ;
    }
    cout << "YES" << endl;
    
    vector<string> a(2);
    int cnt5 = 0;
    if (k % 5 == 0)
    {
        cnt5 = k / 5;
    }
    else if ((k - 3) % 5 == 0)
    {
        cnt5 = (k - 3) / 5;
        a[0] += "*.";
        a[1] += "..";
    }
    else if ((k - 6) % 5 == 0) 
    {
        cnt5 = (k - 6) / 5;
        a[0] += "*.";
        a[1] += "..";
    }

    for (int i = 0;i < cnt5;i++)
    {
        a[0] += ".*.";
        a[1] += "...";
    }

    if ((k - 6) % 5 == 0) 
    {
        a[0] += ".*";
        a[1] += "..";
    }
    cout << a[0].size() << endl;
    cout << a[0] << endl << a[1] << endl;
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

