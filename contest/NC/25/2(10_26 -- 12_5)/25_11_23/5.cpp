#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int lb(vector<pair<int,int>>& a,int x)
{
    int n = a.size();
    int l = -1,r = n;
    while (l + 1 < r)
    {
        int mid = (r + l) / 2;
        if (a[mid].first >= x) r = mid;
        else l = mid;
    }
    return l;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end());
    vector<long long> s(n + 1);
    for (int i = 0;i < n;i++)
    {
        s[i + 1] = s[i] + a[i].first;
    }
    long long ans = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = i;j < n;j++)
        {
            int x = a[i].first + a[j].first;
            int k = lb(a,x);
            if (k < j) break;
            if (i != j && j != k)
            {
                ans += k - j;
                if (a[j].second >= 2) ans++;
            }
            else 
            {
                if (i == j && j == k)
                {
                    if (a[i].second >= 3)
                    {
                        ans++;
                    }
                }
                else if (i == j && j != k)
                {
                    if (a[i].second >= 2)
                    {
                        ans += k - j;
                    }
                    if (a[i].second >= 3)
                    {
                        ans ++;
                    }
                }
                else if (i != j && j == k)
                {
                    if (a[j].second >= 2)
                    {
                        ans ++;
                    }
                }
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