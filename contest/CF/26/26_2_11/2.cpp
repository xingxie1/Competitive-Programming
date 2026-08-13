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
    vt p(n),a(n);
    for (int i = 0;i < n;i++) cin >> p[i];
    for (int i = 0;i < n;i++) cin >> a[i];

    map<int,int> pos;
    vt b;
    for (int i = 0;i < n;i++)
    {   
        pos[p[i]] = i;
    }
    for (int i = 0;i < n;i++)
    {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        b.push_back(a[i]);
        i = j - 1;
    }
    for (int i = 0;i + 1 < b.size();i++)
    {
        if (pos[b[i]] > pos[b[i + 1]]) 
        {
            cout << "NO" << endl;
            return ;
        }
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