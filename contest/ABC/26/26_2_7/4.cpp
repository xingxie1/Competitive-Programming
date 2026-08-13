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
    int n;
    cin >> n;
    vt a(n);
    int mx = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    sort(a.begin(),a.end());
    string ans;
    int flag = 0;
    for (int i = 1;i <= mx;i++)
    {
        auto j = a.end() - lower_bound(a.begin(),a.end(),i);
        int x = j;
        x += flag;
        flag = x / 10;
        int y = x % 10;
        ans += '0' + y;
    }
    while (flag)
    {
        int x = flag % 10;
        ans += '0' + x;
        flag /= 10;
    }
    reverse (ans.begin(),ans.end());
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