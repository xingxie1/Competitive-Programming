#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int check(vector<long long>& a,long long mid,long long k,long long x,vector<long long>& ans)
{
    long long n = a.size();
    for (long long i = a[0] - mid;;i--)
    {
        if (i >= 0) ans.push_back(i);
        else break;
        if (ans.size() >= k) return 1;
    }
    if (ans.size() >= k) return 1;
    for (long long i = 1;i < n;i++)
    {
        if (a[i] - mid >= 0 && a[i - 1] + mid <= a[i] - mid)
        {
            for (long long j = a[i - 1] + mid;;j++)
            {
                if (j <= a[i] - mid)
                {
                    ans.push_back(j);
                }
                else break;
                if (ans.size() >= k) return 1;
            }
        }
        if (ans.size() >= k) return 1;
    }
    for (long long i = a[n - 1] + mid;;i++)
    {
        if (i <= x) ans.push_back(i);
        else break;
        if (ans.size() >= k) return 1;
    }
    return ans.size() >= k;
}
void solve()
{
    int n,k,x;
    cin >> n >> k >> x;
    vll a(n),ans;
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    long long l = -1,r = x + 1;
    while (l + 1 < r)
    {
        vll tmp;
        long long mid = l + (r - l) / 2;
        if (check(a,mid,k,x,tmp)) 
        {
            l = mid;
            ans = tmp;
        }
        else r = mid;
    }
    for (int i = 0;i < k;i++) cout << ans[i] << " ";
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