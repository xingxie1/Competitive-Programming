#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

ll pow10(int i)
{
    ll ret = 1;
    while (i--)
    {
        ret = 10LL * ret;
    }
    return ret;
}
void solve()
{
    string l,r;
    cin >> l >> r;
    int j = 1;
    int m = l.size(),n = r.size();
    while (j < n && r[j] == '0') j++;
    if (j == n && r[0] == '1')
    {
        if (l == r) 
        {
            cout << 1 << endl;
            return ;
        }
        while (--n) cout << 9;
        cout << endl;
        return ;
    }
    if (l.size() < n)
    {
        l = '1';
        while (l.size() < n) l += '0';
        l[n - 1] = '1';
    }
    string ans;
    int k = -1;
    for (int i = 0;i < n;i++)
    {
        if (l[i] != r[i])
        {
            k = i;
            break;
        }
    }
    if (k == -1)
    {
        ans = l;
        while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
        ranges::reverse(ans);
        cout << ans << endl;
        return ;
    }
    bool ok = 1;
    for (int i = k + 1;i < n;i++)
    {
        ans += '9';
        ok &= (r[i] == '9');
        
    }
    ans += (r[k] - !ok);
    for (int i = k - 1;i >= 0;i--) ans += l[i];
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