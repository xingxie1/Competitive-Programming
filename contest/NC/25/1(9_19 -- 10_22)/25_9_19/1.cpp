#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,x;
        long long k,h;
        cin >> n >> k;
        vector<int> a(n);
        long long sum = 0;
        for (int i = 0;i < n;i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        cin >> h >> x;
        sort(a.begin(),a.end(),greater<int>());
        int cnt = 0;
        while (cnt < n)
        {
            for (int i = 0;i < x;i++)
            {
                if (sum > k) h -= k;
                else h -= sum;
            }
            sum -= a[cnt++];
        }
        if (h >= 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    



    return 0;
}