#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long pre = 0,cnt = 0;
    for (int i = 0;i < n;i++)
    {
        int a;
        cin >> a;
        if (a > pre) cnt += (a - pre);
        pre = a;
    }
    cout << cnt << endl;

    

    return 0;
}