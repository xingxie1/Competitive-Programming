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

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    map<int,int> cnt;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(),a.end(),greater<int>());
    ll sum = 0;
    int m = 0;
    vt b;
    for (int x : a)
    {
        while (cnt[x] >= 2)
        {
            sum += 2LL * x;
            cnt[x] -= 2;
            m += 2;
        }
        if (cnt[x] == 1)
        {
            cnt[x]--;
            b.push_back(x); 
        }
    }
    ll ans = 0;
    if (m >= 3) ans = sum;
    ranges::sort(b);
    if (m >= 2)
    {
        for (int x : b)
        {
            if (x < sum) 
            {
                ans = max(ans,sum + x);
            }
        }
    }
    if (m >= 1)
    {
        for (int i = 0;i + 1 < (int) b.size();i++)
        {
            if (b[i + 1] - b[i] < sum) 
            {
                ans = max(ans,sum + b[i + 1] + b[i]);
            }
        }
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