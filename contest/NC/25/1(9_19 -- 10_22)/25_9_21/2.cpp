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
        long long sum = 0;
        int cnt = 0;
        int mn = INT_MAX,mn2 = INT_MAX;
        for (int i = 0;i < n;i++)
        {
            cin >> a[i];
            sum += a[i];
            if (a[i] < mn) 
            {
                mn = a[i];
                cnt = 1;
            }
            else if (a[i] == mn)
            {
                cnt = 2;
            }

        }
        sum = 1LL * 2 * sum;
        if (cnt == 2)
        {
            sum -= 2*mn;
        }
        else 
        {
            for (int i = 0;i < n;i++)
            {
                if (a[i] != mn) 
                    mn2 = min(mn2,a[i]);
            }
            sum = sum - mn - mn2;
        }

        cout << sum << endl;
    }

    return 0;
}