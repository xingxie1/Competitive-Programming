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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    for (int i = 0;i < n;i++) 
    {
        if (a[i] > b[i])
        {
            cout << "NO" << endl;
            return ;
        }
        if (a[i] == b[i]) continue;
        int f = 0;
        for (int j = i - 1;j >= 0;j--) 
        {
            if (a[j] > b[i] || b[j] < b[i]) break;
            if (a[j] == b[i]) 
            {
                f = 1;
                break;
            }
        }
        if (f) continue;
        for (int j = i + 1;j < n;j++) 
        {
            if (a[j] > b[i] || b[j] < b[i]) break;
            if (a[j] == b[i]) 
            {
                f = 1;
                break;
            }
        }
        if (!f) 
        {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
    
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