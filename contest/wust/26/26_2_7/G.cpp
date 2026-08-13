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
    vt a(n),b(m);
    
    ll suma = 0,sumb = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        suma += a[i];
    }
    for (int i = 0;i < m;i++) 
    {
        cin >> b[i];
        sumb += b[i];
    }

    if (suma == sumb) cout << 1 << endl;
    else if (suma < sumb)
    {
        ranges::sort(b);
        for (int i = m - 1;i >= 0;i--)
        {
            sumb -= b[i];
            if (sumb <= suma) 
            {
                cout << m - i << endl;
                return ;
            }
        }
    }
    else 
    {
        ranges::sort(a);
        for (int i = n - 1;i >= 0;i--)
        {
            suma -= a[i];
            if (suma <= sumb) 
            {
                cout << n - i << endl;
                return ;
            }
        }
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