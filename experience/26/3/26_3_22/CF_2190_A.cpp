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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vt pre(n + 1),suf(n + 1);
    for (int i = 0;i < n;i++) pre[i + 1] = pre[i] + (s[i] == '1');
    for (int i = n - 1;i >= 0;i--) suf[i] = suf[i + 1] + (s[i] == '0');
    int j = -1;
    for (int i = 0;i < n;i++)
    {
        if (pre[i] >= suf[i])
        {
            j = i;
            break;
        }
    }
    if (j == -1 || pre[n] == 0 || suf[0] == 0) 
    {
        cout << "Bob" << endl;
        return ;
    }
    vt ans;
    for (int i = 0;i < j;i++)
    {
        if (s[i] == '1') ans.push_back(i + 1);
    }
    for (int i = j;i < n;i++)
    {
        if (s[i] == '0') ans.push_back(i + 1);
    }
    if (ans.size() == 0)
    {
        cout << "Bob" << endl;
        return ;
    }
    cout << "Alice" << endl;
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
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