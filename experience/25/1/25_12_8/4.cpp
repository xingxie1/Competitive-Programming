#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(n);
    set<int> have;
    map<int,int> cnt;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        have.insert(a[i]);
        cnt[a[i]]++;
    }
    vector<int> ans;
    while (have.size())
    {
        int t = *have.begin();
        ans.push_back(t);
        have.erase(have.begin());
        for (int cur = t;cur <= k;cur+= t)
        {
            if (!cnt.count(cur))
            {
                cout << "-1" << endl;
                return ;
            }
            if (have.count(cur)) have.erase(cur);
        }
    }
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