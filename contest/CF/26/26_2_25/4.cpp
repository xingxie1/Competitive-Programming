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
    ll l = 1;
    vt bb(n + m + 5),a(n);
    for (int i = 0;i < n;i++) cin >> a[i];  
    ranges::sort(a);
    a.erase(unique(a.begin(),a.end()),a.end());
    for (int x : a)
    {
        l = lcm(l,x);
        if (l > n + m + 1) l = INT_MAX;
        for (int j = x;j <= n + m;j += x) bb[j] = 1;
    }
    int A = 0,B = 0,C = 0;
    for (int i = 0;i < m;i++)
    {
        int x;
        cin >> x;
        if (x % l == 0) A++;
        else 
        {
            if (!bb[x]) B++;
            else C++;
        }
    }
    if (A + C % 2 > B) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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