#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    int cnt0 = 0,cnt1 = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        if (a[i] % 2) cnt1++;
        else cnt0++;

    }
    if (cnt1 >= 1 && cnt0 >= 1) 
    {
        sort(a.begin(),a.end());
        for (int i = 0;i  <n;i++) cout << a[i] << " ";
        cout << endl;
    }
    else 
    {
        for (int i = 0;i  <n;i++) cout << a[i] << " ";
        cout << endl;
    }
    


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}