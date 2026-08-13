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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int fi = -1,last = -1,cnt = 0;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '1' && fi == -1) fi = i;
        if (s[i] == '1') 
        {
            last = i;
            cnt++;
        }
    }
    if (cnt == 0)
    {
        cout << 0 << endl;
        return ;
    }
    ll ans = cnt * 11;
    int flag1 = 0,flag2 = 0;
    if (n - last - 1 <= k)
    {
        k -= (n - last - 1);
        flag1 = 1;
    }
    if (k >= fi && (cnt > 1 || !flag1))
    {
        flag2 = 1;
    }
    if (flag1) ans -= 10;
    if (flag2) ans --;

    cout << ans << endl;
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