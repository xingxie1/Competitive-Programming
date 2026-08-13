#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> s(n+1);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }
    long long sum = 0;
    for (int i = 0;i < n;i++)
    {
        sum += 1LL * (a[i] * (s[n] - s[i+1]));
    }
    cout << sum << endl;

    

    return 0;
}