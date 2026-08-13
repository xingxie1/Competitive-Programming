#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int Lower_bound(vector<pair<int,vector<int>>>& a,int x)
{
    int n = a.size();
    int l = -1,r = n;
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid].first <= x) l = mid;
        else r = mid;
    }
    if (l == -1) return -1;
    else if (a[l].second[0] >= x) return a[l].second[1];
    else return -1;
}
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<pair<int,vector<int>>> a(n);
    for (int i = 0;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[i].first = x;
        a[i].second.push_back(y);
        a[i].second.push_back(i + 1);
    }
    sort(a.begin(),a.end());

    for (int i = 0;i < q;i++)
    {
        int x;
        cin >> x;
        int j = Lower_bound(a,x);
        cout << j << endl;
    }
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