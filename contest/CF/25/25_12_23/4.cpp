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
    int N = (int)pow(2,n);
    vt a(N);
    int mx = N - 1;
    int j = 0;
    map<int,int> used;
    for (int i = 0;i < N;i++)
    {
        if (mx != 0)
        {
            a[i] = mx;
            used[mx]++;
            int d = (mx + 1) * 2;
            for (int j = 1;;j++)
            {
                if (mx + d * j > N) break;
                a[i + 1] = mx + d * j;
                used[a[i + 1]]++;
                i++; 
            }
            mx >>= 1;
        }
        else 
        {
            while (used.count(j))
            {
                j++;
            }
            a[i] = j++;
        }
    }
    for (int x : a) cout << x << " ";
    cout <<endl;
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