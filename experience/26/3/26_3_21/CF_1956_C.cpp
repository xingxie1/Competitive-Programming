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
    if (n == 1)
    {
        cout << "1 1" << endl;
        cout << "1 1 1" << endl;
        return ;
    }
    vvt a(n,vt(n));
    vvt ans;
    vt t1(n),t2(n);
    ranges::iota(t1,1);
    ranges::iota(t2,1);
    for (int i = n - 1;i >= 0;i--)
    {
        vt tmp = {1,i + 1};
        tmp.insert(tmp.end(),t1.begin(),t1.end());
        ans.push_back(tmp);
        for (int j = 0;j < n;j++) a[i][j] = t1[j];
        tmp = {2,i + 1};
        tmp.insert(tmp.end(),t2.begin(),t2.end());
        for (int j = 0;j < n;j++) a[j][i] = t2[j];
        ans.push_back(tmp);
    }
    ll sum = 0;
    for (int i = 0;i < n;i++)
    {
        for (int x : a[i]) sum += x;
    }
    cout << sum << " " << ans.size() << endl;
    for (auto& t : ans)
    {
        for (int x : t) cout << x << " ";
        cout << endl;
    }
    // for (int i = 0;i < n;i++)
    // {
    //     for (int x : a[i]) cout << x << " ";
    //     cout << endl;
    // }
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