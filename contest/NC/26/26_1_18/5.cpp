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
    string s;
    cin >> s;
    int n = s.size();
    int cnt0 = 0,cnt1 = 0,cntd = 0,cnts = 0;
    for (int i = 0;i < n - 1;i++)
    {
        char c = s[i],c2 = s[i + 1];
        if (c == '0' && c2 == '0') cnt0++;
        else if (c == '1' && c2 == '1') cnt1++;
        else if (c == '?') 
        {
            if (i == 0) cnts++;
            else if (s[i - 1] == s[i + 1]) cnts++;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}