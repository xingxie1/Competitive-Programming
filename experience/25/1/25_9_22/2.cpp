#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    const int N = (int)1e6;
    vector<int> a(N+4),d(N+4);
    for (int i = 1;i <= n;i++)
    {
        int l,r;
        cin >> l >> r;
        d[l] ++;
        if (r + 1 <= N) d[r+1]--;
    }
    a[0] = d[0];
    int mx = a[0];
    for (int i = 1;i <= N;i++)
    {
        a[i] = a[i-1] + d[i];
        mx = max(mx,a[i]);
    }
    cout << mx << endl;
    

    return 0;
}