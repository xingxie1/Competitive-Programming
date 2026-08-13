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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

const int N = 30;
int pow2[N];
void solve()
{
    int l,r;
    cin >> l >> r;
    int cnt = 0,x = l;
    while (x * 2 <= r) 
    {
        x *= 2;
        cnt++;
    }
    cout << cnt + 1 << " ";
    int ans = 0;
    ll L = l - 1,R = r + 1;
    while (L + 1 < R)
    {
        ll m = L + (R - L) / 2;
        if (m * pow2[cnt] <= r) L = m;
        else R = m;
    }
    ans += L - l + 1;
    L = l - 1,R = r + 1;
    while (L + 1 < R)
    {
        ll m = L + (R - L) / 2;
        if (m * pow2[cnt - 1] * 3 <= r) L = m;
        else R = m;
    }
    if (L >= l) ans += (L - l + 1) * cnt;
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    pow2[0] = 1;
    for (int i = 1;i < N;i++) pow2[i] = pow2[i - 1] * 2;
    while (_ --) solve();

    return 0;
}