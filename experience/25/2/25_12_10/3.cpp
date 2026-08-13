// https://codeforces.com/problemset/problem/1360/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    int cnt0 = 0,cnt1 = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        if (a[i] & 1) cnt1++;
        else cnt0++;
    }
    sort(a.begin(),a.end());
    if (cnt0 % 2 == 0 && cnt1 % 2 == 0) 
    {
        cout << "YES" << endl;
    }
    else
    {
        int flag = 0;
        for (int i = 0;i + 1 < n;i++)
        {
            if (a[i] + 1 == a[i + 1]) 
            {
                flag = 1;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
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