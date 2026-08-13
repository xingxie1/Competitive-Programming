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
    int n,m,k;
    cin >> n >> m >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int l = -1,r = n;
    auto check = [&](int j)
    {
        int sum = 0,cnt = 1;
        for (int i = j;i < n;i++) 
        {
            int x = a[i];
            if (sum + x > k) 
            {
                cnt++;
                sum = x;
            }
            else 
            {
                sum += x;
            }
        }
        return cnt <= m;
    };
    while (l + 1 < r) 
    {
        int m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    cout << n - r << endl;
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