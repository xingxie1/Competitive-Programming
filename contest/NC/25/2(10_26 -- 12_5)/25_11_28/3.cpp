#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

vector<vector<int>> dir = {{-2,-1},{2,-1},{-2,1},{2,1},{1,2},{1,-2},{-1,2},{-1,-2}};
vector<vector<int>> nxt = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int bfs(vector<pair<int,int>>& a,int x,int y)
{
    int cnt = 0;
    for (int i = 0;i < a.size();i++)
    {
        for (int j = 0;j < 8;j++)
        {
            int dx = a[i].fi + dir[j][0],dy = a[i].se + dir[j][1];
            if (dx == x && dy == y) return 1;
        }
    }
    return 0;
}
void solve()
{
    int x,y,n;
    cin >> x >> y >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    int flag1 = 0,flag2 = 0;//1 下一步  2 当前
    int cnt = 0;
    for (int j = 0;j < 8;j++)
    {
        int dx = x + nxt[j][0],dy = y + nxt[j][1];
        int b = bfs(a,dx,dy);
        cnt += (b == 1);
    }
    if (cnt == 8) flag1 = 1;//下一步无路走

    int b = bfs(a,x,y);
    if (b == 1) 
    {
        flag2 = 1;
    }
    
    if (flag2 == 0 && flag1 == 1) cout << "A" << endl;
    else if (flag2 == 1 && flag1 == 1) cout << "B" << endl;
    else cout << "C" << endl;
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