#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

int check(vector<int>& a,long long mid,int m)
{
    long long cnt = 1,sum = 0;
    for (int x : a)
    {
        if (sum + x <= mid)
        {
            sum += x;
            continue;
        }
        if (cnt == m) return 0;
        sum = x;
        cnt++;      
    }
    return 1;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n);
    long long sum = 0;
    int mx = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        sum += a[i];
        mx = max(mx,a[i]);
    }
    long long l = mx - 1,r = sum + 1;
    while (l + 1 < r)
    {
        long long mid = l + (r - l) / 2;
        if (check(a,mid,m)) r = mid;
        else l = mid;
    }
    cout << r;
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