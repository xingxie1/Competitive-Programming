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
    string s;
    cin >> s;
    int flag = 0;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '0')
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout << 0 << endl;
        return ;
    }
    int l = 0;
    while (s[l] == '0')
    {
        l++;
    }
    string tmp(s.begin() + l,s.end());
    while (l--) tmp += '0';
    int c = 0,ans = 0;
    for (int i = 0;i < n;i++)
    {
        if (tmp[i] == '0')
        {
            c++;
        }
        else 
        {
            ans = max(ans,c);
            c = 0;
        }
    }
    ans = max(ans,c);
    // cout << tmp << endl;
    cout << ans << endl;
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