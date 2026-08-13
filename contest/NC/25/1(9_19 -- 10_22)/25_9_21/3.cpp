#include <bits/stdc++.h>
using namespace std;

int mex(int a, int b) 
{
    bool has0 = (a == 0 || b == 0);
    bool has1 = (a == 1 || b == 1);
    if (!has0) return 0;
    if (has1) return 2;
    return 1;
}
int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0;i < n;i++)
        {
            cin >> a[i];
        }
        int ans = INT_MIN;
        for (int i = 1;i < n;i++)
        {
            ans = max(ans,max(a[i],a[i-1]) - mex(a[i],a[i-1]));
        }
        cout << ans << endl;
        

    }

    return 0;
}