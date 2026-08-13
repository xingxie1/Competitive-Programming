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
    vll s(n);
    ll sum = 0,t = 0;
    for (int i = 0;i < n;i++) 
    {
        int a,b;
        cin >> a >> b;
        s[i] = a + b;
        t += a;
    }
    sort(s.begin(),s.end(),greater<>());
    int ans = 0;
    for (int i = 0;i < n;i++)
    {
        sum += s[i];
        if (sum >= t) 
        {
            ans = n - i - 1;
            break;
        }
    }
    cout << ans <<endl;
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