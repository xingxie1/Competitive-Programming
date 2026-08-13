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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int last = a[0],cnt = 0;
    for (int i = 1;i < n;i++)
    {
        if (a[i] == last || a[i] == 7 - last)
        {
            cnt++;
            if (i + 1 < n) 
            {
                vt b = {1,2,3,4,5,6};
                int y = a[i + 1];
                for (int x : b)
                {
                    if (x != last && x != 7 - last && x != y && x != 7 - y)
                    {
                        last = x;
                        break;
                    }
                }
                
            }
        }
        else 
        {
            last = a[i];
        }
    }
    cout << cnt << endl;
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