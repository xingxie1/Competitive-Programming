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
    vt a(n);
    int down = 0,up = 1e9;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        if (i > 0)
        {
            if (a[i] > a[i - 1])
            {
                up = min(up,(a[i - 1] + a[i]) / 2);
            }
            else if (a[i] < a[i - 1])
            {
                down = max(down,(a[i] + a[i - 1] + 1) / 2);
            }
        }
    }
    if (down <= up) cout << down << endl;
    else cout << -1 << endl;
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