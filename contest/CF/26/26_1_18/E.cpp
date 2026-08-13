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
    int n,m,k;
    cin >> n >> m >> k;
    vt a(n),b(m);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) cin >> b[i];

    b.push_back(INT_MIN / 2);
    b.push_back(INT_MAX / 2);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    vector pr(k + 1,vector<int>()),pl(k + 1,vector<int>());
    string s;
    cin >> s;
    for (int i = 0;i < n;i++)
    {
        int j = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
        int r = b[j] - a[i],l = a[i] - b[j - 1];
        if (r <= k) pr[r].push_back(l);
        if (l <= k) pl[l].push_back(r);
    }

    int sum = 0,mr = 0,ml = 0,ans = n;
    for (char c : s)
    {
        if (c == 'L') sum--;
        else sum++;
        
        mr = max(mr,sum);
        ml = max(ml,-sum);
        if (sum > 0 && sum <= k)
        {
            for (int l : pr[sum]) if (l > ml) ans--;
            pr[sum].clear();
        }
        if (sum < 0 && -sum <= k)
        {
            for (int r : pl[-sum]) if (r > mr) ans--;
            pl[-sum].clear();
        }
        cout << ans << " ";
    }
    cout << endl;
    // cout << mn << " " << mx << endl;
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