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
    int n;
    cin >> n;
    vvt a(n,vt(n,INT_MAX / 2));
    for (int i = 0;i < n;i++) 
    {
        for (int j = i + 1;j < n;j++) cin >> a[i][j];
    }
    for (int k = 0;k < n;k++)
    {
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                if (a[i][k] + a[k][j] < a[i][j])
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