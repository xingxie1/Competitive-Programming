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
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,x,y;
    cin >> n >> x >> y;
    vt a;
    for (int d = 1;d <= y - x;d++) 
    {
        if ((y - x) % d) continue;
        if ((y - x) / d > n - 1) continue;
        int i = 0;
        while (a.size() < n) 
        {
            if (y - i * d <= 0) break;
            a.push_back(y - i * d);
            i++;
        }
        i = 1;
        while (a.size() < n) 
        {
            a.push_back(y + i * d);
            i++;
        }
        break;
    }
    for (int x : a) cout << x << " ";
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