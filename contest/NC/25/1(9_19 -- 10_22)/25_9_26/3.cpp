#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n,d;
    cin >> n >> d;
    vector<int> a;
    unordered_map<int,int> cnt;
    for (int i = d;i <= pow(10,n);i+=d)
        a.push_back(i);
    string s;
    cin >> s;
    for (int i = 0;i < n;i++)
        cnt[s[i]-'0']++;
    if (cnt[0]) 
    {
        cout << 0 << endl;
        return ;
    }
    for (int i = 0;i < a.size();i++)
    {
        vector<int> c(10);
        int y = a[i];
        while (y > 0)
        {
            int x = y % 10;
            c[x]++;
            y /= 10;
        }
        int flag = 1;
        for (int i = 0;i < 10;i++)
        {
            if (c[i] > cnt[i]) flag = 0;
        }
        if (flag)
        {
            cout << a[i] << endl;
            return ;
        }
    }
    cout << -1 << endl;
    
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}