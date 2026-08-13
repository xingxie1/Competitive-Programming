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
    int n,m;
    cin >> n >> m;
    vvt a(n,vt());
    vt ans(n);
    set<int> s;
    for (int i = 0;i < n;i++)
    {
        int l;
        cin >> l;
        a[i].resize(l);
        for (int j = 0;j < l;j++) cin >> a[i][j];
        for (int x : a[i])
        {
            if (!s.contains(x)) 
            {
                ans[i] = x;
                s.insert(x);
                break;
            }
            s.insert(x);
        }
    }
    for (int x : ans) cout << x << endl;

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