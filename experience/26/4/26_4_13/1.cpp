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
    int n;
    cin >> n;
    vt a(n);
    int sum1 = 0,sum2 = 0;
    for (int i = 0;i < n;i ++)
    {
        cin >> a[i];
        sum1 += a[i];
        i++;
        if (i >= n) break;
        cin >> a[i];
        sum2 += a[i];
    }
    if (n == 1) 
    {
        cout << "YES" << endl;
        return ;
    }
    int n1 = n / 2,n2 = n / 2;
    if (n % 2) n1++;
    if (sum1 % n1 == 0 && sum2 % n2 == 0 && sum1 / n1 == sum2 / n2) cout << "YES" << endl;
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