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
    int n,m;
    cin >> n >> m;
    vt a(n);
    for (int i = 0;i < n;i++) cin >>a[i];
    sort(a.begin(),a.end());
    vt d(n - 1);
    for (int i = 0;i < n - 1;i++)
    {
        d[i] = a[i + 1] - a[i];
    }
    int l = 0,r = 0;
    int len = 0,ans = 0;
    int cnt1 = 0,cnt2 = 0;
    while (r < n - 1)
    {
        if (d[r] == 1) cnt1++;
        else if (d[r] == 2) 
        {
            ans = max(ans,cnt1 + cnt2 + 2);
            cnt2++;
            while (cnt2 > 1)
            {
                if (d[l] == 1) cnt1--;
                else if (d[l] == 2) cnt2--;
                l++;
            }
        }
        else 
        {
            ans = max(ans,cnt1 + cnt2 + 2);
            cnt1 = cnt2 = 0;
            l = r + 1;
        }
        r++;
    }
    ans = max(ans,cnt1 + cnt2 + 2);
    
    if (ans >= m) cout << "YES" << endl;
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