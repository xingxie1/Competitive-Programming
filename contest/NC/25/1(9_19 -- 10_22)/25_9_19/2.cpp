#include <bits/stdc++.h>
using namespace std;

bool check(string s,int n)
{
    int cnt = 1;
    for (int i = 1;i < s.size();i++)
    {
        if (s[i] > s[i-1]) cnt++;
    }
    return cnt >= n;
}
int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = 0,r = n+1;
        while (l + 1 < r)
        {
            int mid = (l+r)/2;
            if (check(s,mid)) l = mid;
            else r = mid;
        }
        cout << l << endl;
    }
    



    return 0;
}