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
    int n;
    cin >> n;
    vector<pair<int,int>> ans;
    priority_queue<int> q;
    for (int i = 1;i <= n;i++) q.push(i);

    while (q.size() >= 2)
    {
        int t1 = q.top();
        q.pop();
        int t2 = q.top();
        q.pop();
        ans.push_back({t1,t2});

        q.push((t1 + t2 + 1) / 2);
    }
    cout << 2 << endl;
    for(int i = 0;i < n - 1;i++) cout << ans[i].fi << " " << ans[i].se << endl;

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