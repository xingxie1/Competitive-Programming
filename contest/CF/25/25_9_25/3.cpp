#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(n);
    unordered_map<int,int> hash(n);
    for (int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        hash[x]++;   
    }
    int ans = hash[k];
    int cnt = 0;

    for (int i = 0;i < k;i++)
    {
        if (hash[i] == 0) cnt++;
    }
    if (cnt > ans) ans = cnt; 
    cout << ans << endl;
    
    
    
}

int main()
{
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}