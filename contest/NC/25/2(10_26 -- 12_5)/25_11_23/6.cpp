#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> cnt;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
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