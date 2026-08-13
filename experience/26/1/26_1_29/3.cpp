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
    set<int> a;
    map<int,int> cnt,cnt2;
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        a.insert(x);
        cnt[x]++;
    }
    int mx = 0;
    for (int x : a)
    {
        for (int y = x;y <= n;y += x)
        {
            cnt2[y] += cnt[x];
            mx = max(mx,cnt2[y]);
            // cout << y << endl;
        }
    }
    cout << mx << endl;
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