#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string t;
    cin >> t;
    for (int i = 0;i < n;i++)
    {
        int j = i;
        if (t[i] == '0') continue;
        while (j < n && t[j] == '1') j++;
        if (j == i + 1) 
        {
            cout << i << endl;
            cout << "NO" << endl;
            return ;
        }
        i = j - 1;
    }
    cout << "YES" << endl;

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