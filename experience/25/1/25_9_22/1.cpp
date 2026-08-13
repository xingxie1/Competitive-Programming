#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,p;
    cin >> n >> p;
    vector<int> a(n+1),d(n+2);
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        d[i] = a[i] - a[i-1];
    }
    for (int i = 0;i < p;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        d[x] += z;
        d[y+1] -= z;
    }
    for (int i = 1;i <= n;i++)
    {
        a[i] = d[i] + a[i-1];
    }
    int mn = INT_MAX;
    for (int i = 1;i <= n;i++)
    {
        mn = min(mn,a[i]);
    }
    cout << mn << endl;

    return 0;
}