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
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    if (n % 2) 
    {
        if (n < 27) cout << -1 << endl;
        else 
        {
            vt a(27);
            a[0] = a[4] = 1;
            a[1] = a[10] = a[26] = 2;
            a[2] = a[3] = 3;
            a[5] = a[6] = 4;
            a[7] = a[8] = 5;
            a[9] = a[13] = 6;
            a[11] = a[12] = 7;
            int x = 8;
            for (int i = 14;i < 25;i += 2)
            {
                a[i] = a[i + 1] = x++;
            }
            for (int y : a) cout << y << " ";
            for (int i = 27;i < n;i += 2) 
            {
                cout << x << " " << x << " ";
                x++;
            }
            cout << endl;
        }
    }
    else 
    {
        int x = 1;
        for (int i = 0;i < n;i += 2)
        {
            cout << x << " " << x << " ";
            x++;
        }
        cout << endl;
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