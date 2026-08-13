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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    vt a(n),pos(n + 1);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int f = 1;
    for (int i = 0;i < n - 1;i++)
    {
        if (a[i + 1] < a[i]) f = 0;
    }
    if (f) 
    {
        cout << 0 << endl;
        return ;
    }
    int l = (n + 1) / 2,r = (n + 2) / 2;
    if (l != r && pos[l] > pos[r]) 
    {
        cout << n / 2 << endl;
        return ;
    }
    while (l > 1 && r < n)
    {
        if (pos[l - 1] < pos[l] && pos[r] < pos[r + 1]) 
        {
            l--;
            r++;
        }
        else break;
    }
    int ans = l - 1;
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