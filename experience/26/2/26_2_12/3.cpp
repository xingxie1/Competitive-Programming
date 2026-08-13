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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n);
    map<int,int> cnt;
    ll sum = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        sum += a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(),a.end());
    int ans = 0;
    if (a[0] == a[n - 1]) cout << m << endl;
    else 
    {
        int flag = 1;
        int k = cnt.size();
        for (auto&[x,_] : cnt)
        {
            if (_ % k) flag = 0;
        }
        if (flag) ans++;
        cout << ans << endl;
    }
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