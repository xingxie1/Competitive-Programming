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
    int n,m,k;
    cin >> n >> m ;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    cin >> k;
    vt b(k);
    for (int i = 0;i < k;i++) cin >> b[i];
    vpll c,d;
    for (int i = 0;i < n;i++)
    {
        if (a[i] % m == 0)
        {
            int cnt = 0;
            while (a[i] % m == 0)
            {
                a[i] /= m;
                cnt++;
            } 
            int p = pow(m,cnt);
            if (!c.empty() && a[i] == c.back().fi) c.back().se += p;
            else c.push_back({a[i],p});
        }
        else 
        {
            int j = i,cnt = 0;
            while (j < n && a[j] == a[i]) 
            {
                j++;
                cnt++;
            }
            if (!c.empty() && a[i] == c.back().fi) c.back().se += cnt;
            else c.push_back({a[i],cnt});
            i = j - 1;
        }
    }
    for (int i = 0;i < k;i++)
    {
        if (b[i] % m == 0)
        {
            int cnt = 0;
            while (b[i] % m == 0)
            {
                b[i] /= m;
                cnt++;
            } 
            int p = pow(m,cnt);
            if (!d.empty() && b[i] == d.back().fi) d.back().se += p;
            else d.push_back({b[i],p});
        }
        else 
        {
            int j = i,cnt = 0;
            while (j < k && b[j] == b[i]) 
            {
                j++;
                cnt++;
            }
            if (!d.empty() && b[i] == d.back().fi) d.back().se += cnt;
            else d.push_back({b[i],cnt});
            i = j - 1;
        }
    }
    if (c == d) cout << "Yes" << endl;
    else cout << "No" << endl;
    
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