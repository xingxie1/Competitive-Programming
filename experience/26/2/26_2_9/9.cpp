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

struct Exam
{
    int id,s,d,c;
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<Exam> e(m);
    vt cnt(m + 1),ans(n);
    for (int i = 0;i < m;i++) 
    {
        int s,d,c;
        cin >> s >> d >> c;
        e[i] = {i + 1,s - 1,d - 1,c};
        ans[d - 1] = m + 1;
    }
    sort(e.begin(),e.end(),[](auto& a,auto& b){
        return a.d < b.d;
    });
    
    for (int i = 0;i < m;i++)
    {
        for (int j = e[i].s;j < e[i].d && e[i].c > 0;j++)
        {
            if (ans[j] == 0) 
            {
                ans[j] = e[i].id;
                e[i].c--;
            }
        }
        if (e[i].c > 0)
        {
            cout << -1 << endl;
            return ;
        }
    }
    for (int x : ans) cout << x << " ";
    cout << endl;
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