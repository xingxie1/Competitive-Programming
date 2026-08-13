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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt b(n);
    if (n % 2 == 0)
    {
        for (int i = 0;i < n;i+=2)
        {
            b[i] = -a[i + 1];
            b[i + 1] = a[i];
        }
    }
    else 
    {
        for (int i = 0;i < n - 3;i+=2)
        {
            b[i] = -a[i + 1];
            b[i + 1] = a[i];
        }
        int x = a[n - 3],y = a[n - 2],z = a[n - 1];
        if (x + y != 0)
        {
            b[n - 3] = z;
            b[n - 2] = z;
            b[n - 1] = -x - y;
        }
        else if (y + z != 0)
        {
            b[n - 3] = -y - z;
            b[n - 2] = x;
            b[n - 1] = x;
        }
        else 
        {
            b[n - 3] = y;
            b[n - 2] = -x - z;
            b[n - 1] = y;
        }
    }
    for (int x : b) cout << x << " ";
    cout << endl;

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