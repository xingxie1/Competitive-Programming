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
    int n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt b = a,cnt(n);
    ranges::sort(b);
    for (int i = 0;i < n;i++)
    {
        auto j = ranges::lower_bound(b,a[i]) - b.begin();
        cnt[i] = j;
    }
    while (k--)
    {
        int x,y;
        cin >> x >> y;
        if (a[x - 1] > a[y - 1]) cnt[x - 1]--;
        else if (a[x - 1] < a[y - 1]) cnt[y - 1]--;
    }
    for (int x : cnt) cout << x << " ";
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