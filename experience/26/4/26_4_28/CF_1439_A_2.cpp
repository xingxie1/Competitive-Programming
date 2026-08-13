#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvpii ans;
    
    // Step 1: 消除前 n-2 行
    for (int i = 0;i < n - 2;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == '1') 
            {
                a[i][j] = '0';
                vpii tmp = {{i,j}};
                
                // 修复：判断是否是最后一列，防止 j+1 越界
                if (j < m - 1) 
                {
                    tmp.push_back({i + 1,j});
                    tmp.push_back({i + 1,j + 1});
                    a[i + 1][j] = ((a[i + 1][j] - '0') ^ 1) + '0';
                    a[i + 1][j + 1] = ((a[i + 1][j + 1] - '0') ^ 1) + '0';
                } 
                else 
                {
                    // 如果是最后一列，翻转正下和左下
                    tmp.push_back({i + 1,j});
                    tmp.push_back({i + 1,j - 1});
                    a[i + 1][j] = ((a[i + 1][j] - '0') ^ 1) + '0';
                    a[i + 1][j - 1] = ((a[i + 1][j - 1] - '0') ^ 1) + '0';
                }
                ans.push_back(tmp);
            }
        }
    }
    
    // Step 2: 消除最后两行的前 m-2 列
    for (int j = 0;j < m - 2;j++)
    {
        if (a[n - 2][j] == '1' && a[n - 1][j] == '1')
        {
            vpii tmp = {{n - 1,j},{n - 2,j},{n - 2,j + 1}};
            a[n - 2][j + 1] = ((a[n - 2][j + 1] - '0') ^ 1) + '0';
            ans.push_back(tmp);
        }
        else if (a[n - 1][j] == '1')
        {
            vpii tmp = {{n - 1,j},{n - 1,j + 1},{n - 2,j + 1}};
            ans.push_back(tmp);
            a[n - 1][j + 1] = ((a[n - 1][j + 1] - '0') ^ 1) + '0';
            a[n - 2][j + 1] = ((a[n - 2][j + 1] - '0') ^ 1) + '0';
        }
        else if (a[n - 2][j] == '1')
        {
            vpii tmp = {{n - 2,j},{n - 1,j + 1},{n - 2,j + 1}};
            ans.push_back(tmp);
            a[n - 1][j + 1] = ((a[n - 1][j + 1] - '0') ^ 1) + '0';
            a[n - 2][j + 1] = ((a[n - 2][j + 1] - '0') ^ 1) + '0';
        }
    }
    
    // Step 3: 收尾右下角 2x2
    int cnt = 0;
    cnt += (a[n - 2][m - 2] == '1');
    cnt += (a[n - 2][m - 1] == '1');
    cnt += (a[n - 1][m - 1] == '1');
    cnt += (a[n - 1][m - 2] == '1');
    
    if (cnt == 2)
    {
        cnt = 1;
        int x1 = -1,y1 = -1,x2,y2;
        if (a[n - 2][m - 2] == '1') 
        {
            if (x1 == -1) { x1 = n - 2; y1 = m - 2; }
            else { x2 = n - 2; y2 = m - 2; }
        }
        if (a[n - 2][m - 1] == '1') 
        {
            if (x1 == -1) { x1 = n - 2; y1 = m - 1; }
            else { x2 = n - 2; y2 = m - 1; }
        }
        if (a[n - 1][m - 1] == '1') 
        {
            if (x1 == -1) { x1 = n - 1; y1 = m - 1; }
            else { x2 = n - 1; y2 = m - 1; }
        }
        if (a[n - 1][m - 2] == '1') 
        {
            if (x1 == -1) { x1 = n - 1; y1 = m - 2; }
            else { x2 = n - 1; y2 = m - 2; }
        }
        
        int x3 = -1, y3 = -1;
        for (int i = n - 2; i < n; i++) {
            for (int j = m - 2; j < m; j++) {
                if (a[i][j] == '0') {
                    x3 = i; y3 = j;
                }
            }
        }
        ans.push_back({{x1, y1}, {x2, y2}, {x3, y3}});
        a[x1][y1] = '0';
        a[x2][y2] = '0';
        a[x3][y3] = '1';
    }
    if (cnt == 3) 
    {
        cnt = 0;
        vpii tmp;
        for (int i = n - 2;i < n;i++)
        {
            for (int j = m - 2;j < m;j++)
            {
                if (a[i][j] == '1') tmp.push_back({i,j});
            }
        }
        ans.push_back(tmp);
    }
    if (cnt == 4) 
    {
        cnt = 1;
        ans.push_back({{n - 2, m - 2}, {n - 2, m - 1}, {n - 1, m - 2}});
        a[n - 2][m - 2] = '0';
        a[n - 2][m - 1] = '0';
        a[n - 1][m - 2] = '0';
    }
    if (cnt == 1)
    {
        pii p_one;
        vpii p_zeros;
        for (int i = n - 2; i < n; i++) {
            for (int j = m - 2; j < m; j++) {
                if (a[i][j] == '1') p_one = {i, j};
                else p_zeros.push_back({i, j});
            }
        }
        ans.push_back({p_one, p_zeros[0], p_zeros[1]});
        ans.push_back({p_one, p_zeros[0], p_zeros[2]});
        ans.push_back({p_one, p_zeros[1], p_zeros[2]});
    }

    cout << ans.size() << endl;
    for (int i = 0;i < ans.size();i++) 
    {   
        for (auto& [l,r] : ans[i]) cout << l + 1 << " " << r + 1 << " ";
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