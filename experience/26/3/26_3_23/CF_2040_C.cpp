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
    ll n,k;
    cin >> n >> k;
    vt a(n);
    if (n - 1 <= 60) 
    {
        if (k > (1LL << (n - 1)))
        {
            cout << -1 << endl;
            return ;
        }
    }
    k--;
    int L = 0,R = n - 1;
    for (int i = 1;i < n;i++)
    {
        if (n - i - 1 >= 60)
        {
            a[L++] = i;
        }
        else 
        {
            ll res = 1LL << (n - i - 1);
            if (res > k) a[L++] = i;
            else 
            {
                a[R--] = i;
                k -= res;
            }
        }
    }
    a[L] = n;
    for (int x : a) cout << x << " ";
    cout << endl;
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