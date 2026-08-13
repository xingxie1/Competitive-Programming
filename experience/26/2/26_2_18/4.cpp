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
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int k;
    cin >> k;
    vvt a(k,vt());
    vll pre(k);
    for (int i = 0;i < k;i++)
    {
        int n;
        cin >> n;
        a[i].resize(n);
        for (int j = 0;j < n;j++) 
        {
            cin >> a[i][j];
            pre[i] += a[i][j];
        }
    }
    map<ll,pii> pos;
    for (int i = 0;i < k;i++)
    {
        for (int j = 0;j < a[i].size();j++)
        {
            if (!pos.count(pre[i] - a[i][j])) 
            {
                pos[pre[i] - a[i][j]] = {i + 1,j + 1};
            }
            else 
            {
                if (pos[pre[i] - a[i][j]].fi != i + 1)
                {
                    cout << "YES" << endl;
                    cout << pos[pre[i] - a[i][j]].fi << " " << pos[pre[i] - a[i][j]].se << endl;
                    cout << i + 1 << " " << j + 1 << endl;
                    return ;
                }
            }
        }
    }
    cout << "NO" << endl;
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