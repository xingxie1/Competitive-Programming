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
    map<int,int> cnt;
    for (int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    if (cnt.size() < cnt.begin()->first)
    {
        cout << cnt.begin()->first << endl;
    }
    else 
    {
        for (int i = cnt.size();;i++)
        {
            if (cnt.count(i)) 
            {
                cout << i << endl;
                return ;
            }
        }
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