#include <bits/stdc++.h>
using namespace std;

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
        sort(a.begin(),a.end());
        long long ans = 0;
        long long sum1 = 0,sum2 = 0,sum3 = 0,sum4 = 0;
        if (n % 2 == 1)
        {
            int medium1 = a[n/2],medium2 = a[n/2 - 1];
            for (int i = 0;i < n;i++)
            {
                if (i != 0) sum1 += abs(a[i] - medium1);
                if (i != n-1) sum2 += abs(a[i] - medium2);
            }
            ans = min(sum1,sum2);
        }
        else 
        {
            int medium1 = a[n/2],medium2 = a[n/2 - 1];
            for (int i = 0;i < n;i++)
            {
                if (i != 0) sum3 += abs(a[i] - medium1);
                if (i != n-1) sum4 += abs(a[i] - medium2);
            }
            ans = min(sum3,sum4);
        }
        cout << ans << endl;
    }

    return 0;
}