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
    string s;
    cin >> s;
    ll ans = 0;
    vt a(n);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == 'L') 
        {
            ans += i;
            if (n - 1 - i > i) a[i] = n - 1 - i - i;
            else a[i] = 0;
        }
        else 
        {
            ans += n - i - 1;
            if (i > n - i - 1) a[i] = i - n + i + 1;
            else a[i] = 0;
        }
    }
    sort(a.begin(),a.end(),greater<int>());
    for (int i = 0;i < n;i++)
    {
        ans += a[i];
        cout << ans << " "; 
        
    }
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