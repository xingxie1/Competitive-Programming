#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    int pre3 = 0,pre7 = 0;
    int suf3 = 0,suf7 = 0;
    map<int,int> cnt3,cnt7;
    ll ans = 0; 
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        if (a[i] % 5 == 0)
        {
            int k = a[i] / 5;
            ll a1 = cnt3[3 * k],a2 = cnt7[7 * k];
            
            ans += a1 * a2;
        }
        if (a[i] % 7 == 0)
        {
            pre7++;
            cnt7[a[i]]++;
        }
        if (a[i] % 3 == 0)
        {
            pre3++;
            cnt3[a[i]]++;
        }
    }
    cnt3.clear();
    cnt7.clear();
    for (int i = n - 1;i >= 0;i--)
    {
        if (a[i] % 5 == 0)
        {
            int k = a[i] / 5;
            ll a1 = cnt3[3 * k],a2 = cnt7[7 * k];

            ans += a1 * a2;
        }
        if (a[i] % 7 == 0)
        {
            suf7++;
            cnt7[a[i]]++;
        }
        if (a[i] % 3 == 0)
        {
            suf3++;
            cnt3[a[i]]++;
        }
    }
    cout << ans << endl;
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