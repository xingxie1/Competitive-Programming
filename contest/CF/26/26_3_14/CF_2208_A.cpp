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
    int n;
    cin >> n;
    vvt a(n,vt(n));
    map<int,int> cnt;
    int mx = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++) 
        {
            cin >> a[i][j];
            cnt[a[i][j]] ++;
            mx = max(mx,cnt[a[i][j]]);
        }
    }
    if (mx <= n * (n - 1)) cout << "YES" << endl;
    else cout << "NO" << endl;

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