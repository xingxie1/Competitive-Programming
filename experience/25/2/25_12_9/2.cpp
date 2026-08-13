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
    int n;
    cin >> n;
    vt a(n);
    unordered_map<int,vector<int>> p;
    set<int> ts;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        p[a[i]].push_back(i);
        if (i > 0 && a[i - 1] > a[i]) ts.insert(i - 1);
    }
    int ans = 0;
    while (!ts.empty())
    {
        int i = *ts.begin();
        int x;
        if (a[i] > 0) x = a[i];
        else x = a[i + 1];
        for (int j : p[x])
        {
            a[j] = 0;
            ts.erase(j);
            ts.erase(j - 1);

            if (j > 0 && a[j - 1] > a[j]) ts.insert(j - 1);
            if (j + 1 < n && a[j] > a[j + 1]) ts.insert(j);
        }
        ans++;
    }
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