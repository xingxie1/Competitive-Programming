#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt a,b;
    for (int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    a.resize(k);
    b.resize(k);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    priority_queue<int,vector<int>,greater<int>> q;
    int l = 0,r = k  -1;
    while (l < r)
    {
        q.push(a[l] + b[r]);
        q.push(b[l] + a[r]);
        l++;
        r--;
    }
    if (l == r)
    {
        q.push(a[l] + b[l]);
    }
    cout << q.top();

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