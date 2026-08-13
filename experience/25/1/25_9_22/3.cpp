#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    map<long long,long long> mp;
    long long pre = 0,cnt = 0;
    mp[0] = 1;
    for (int i = 0;i < n;i++)
    {
        pre += a[i];
        if (mp.count(pre - x))
            cnt += mp[pre-x];
        mp[pre] ++;
    }
    cout << cnt << endl;

    

    return 0;
}