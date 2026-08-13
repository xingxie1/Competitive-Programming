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
    vvt a(n,vt(n));
    int L = 0,R = n - 1,U = 0,D = n - 1;
    int x = n * n - 1,op = 0;
    while (1)
    {
        if (op == 0) 
        {
            for (int j = L;j <= R;j++) 
            {
                a[U][j] = x--;
                if (x <= 0) break;
            }
            U++;
        }
        else if (op == 1)
        {
            for (int i = U;i <= D;i++) 
            {
                a[i][R] = x--;
                if (x <= 0) break;
            }
            R--;
        }
        else if (op == 2) 
        {
            for (int j = R;j >= L;j--)
            {
                a[D][j] = x--;
                if (x <= 0) break;
            }
            D--;
        }
        else 
        {
            for (int i = D;i >= U;i--) 
            {
                a[i][L] = x--;
                if (x <= 0) break;
            }
            L++;
        }
        if (x <= 0) break;
        op++;
        op %= 4;
    }
    for (int i = 0;i < n;i++) 
    {
        for (int x : a[i]) cout << x << " ";
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