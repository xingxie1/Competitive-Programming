#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vt a (n),pre(n + 1,INT_MAX);
    vector <pair<int,int>> suf(n + 1);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        pre[i + 1] = min(pre[i],a[i]);
    }
    for (int i = n - 1;i >= 0;i--)
    {
        suf[i] = max(suf[i + 1],{a[i],i});
    }
    for (int i = 1;i < n;i++)
    {
        if (pre[i] > suf[i].first) 
        {
            cout << "No" << endl;
            return ;
        }
    }
    cout << "yes" << endl;
    for (int l = 0;l < n;)
    {
        int r = suf[l].second;
        for (int i = l;i < r;i++)
        {
            cout << a[i] << " " << a[r] << endl;
        }
        if (l > 1)
            cout << pre[l - 1] << " " << a[r] << endl;
        l = r + 1;
    }
    

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