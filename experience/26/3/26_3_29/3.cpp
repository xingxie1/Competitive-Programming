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
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    ranges::sort(a);
    for (int i = 0;i < n;i++)
    {
        for (int j = i + 1;j < n;j++)
        {
            for (int k = j + 1;k < n;k++)
            {
                int x1 = a[i].fi,y1 = a[i].se,x2 = a[j].fi,y2 = a[j].se,x3 = a[k].fi,y3 = a[k].se;
                int dx1 = x1 - x2,dx2 = x1 - x3;
                int dy1 = y1 - y2,dy2 = y1 - y3;
                if (dx1 * dy2 == dx2 * dy1)
                {
                    cout << "Yes" << endl;
                    return ;
                }
            }
        }
    }
    cout << "No" << endl;

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