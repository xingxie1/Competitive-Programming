#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

struct node
{
    vpii b;
    int id = 0;// 0单张 1对子 2两对 3三条 4顺子 5同花 6葫芦（3 + 2） 7四条 8同花顺 9皇家
    node ()
    {
        int f = 1;//花色相同
        vt cnt(15);
        vpii a = b;
        sort(a.begin(),a.end(),[&](auto& x,auto& y) {
            return x.fi > y.fi;
        });
        for (int i = 0;i < a.size();i++)
        {
            if (a[i].se != a[0].se) f = 0;
            cnt[a[i].fi]++;
        }
        if (f) 
        {
            id = 5;
            int ff = 0;
            for (int i = 2;i <= 10;i++)
            {
                if (cnt[i] && cnt[i + 1] && cnt[i + 2] && cnt[i + 3] && cnt[i + 4]) ff = 1;
            }
            if (ff) id = 8;
            if (id == 8) 
            {
                if (cnt[14]) id = 9;
            }
        }
        else 
        {
            int f3 = 0;
            int c2 = 0;
            for (int i = 2;i <= 14;i++)
            {
                if (cnt[i] == 4) id = 7;
                if (cnt[i] == 3) 
                {
                    f3 = 1;
                }
                if (cnt[i] == 2) 
                {
                    c2++;
                }
            }
            if (f3)
            {
                if (c2) id = 6;
                else id = 3;
            }
            else if (c2 == 2) id = 2;
            else if (c2 == 1) id = 1;
            int ff = 0;
            for (int i = 2;i <= 10;i++)
            {
                if (cnt[i] && cnt[i + 1] && cnt[i + 2] && cnt[i + 3] && cnt[i + 4]) ff = 1;
            }
            if (f) id = max(id,4);
        }
        // if (id == 0) {}
        // else if (id == 1) 
        // {

        // }
    }
    void fff ()
    {
        int f = 1;//花色相同
        vt cnt(15);
        vpii a = b;
        sort(a.begin(),a.end(),[&](auto& x,auto& y) {
            return x.fi > y.fi;
        });
        for (int i = 0;i < a.size();i++)
        {
            if (a[i].se != a[0].se) f = 0;
            cnt[a[i].fi]++;
        }
        if (f) 
        {
            id = 5;
            int ff = 0;
            for (int i = 2;i <= 10;i++)
            {
                if (cnt[i] && cnt[i + 1] && cnt[i + 2] && cnt[i + 3] && cnt[i + 4]) ff = 1;
            }
            if (ff) id = 8;
            if (id == 8) 
            {
                if (cnt[14]) id = 9;
            }
        }
        else 
        {
            int f3 = 0;
            int c2 = 0;
            for (int i = 2;i <= 14;i++)
            {
                if (cnt[i] == 4) id = 7;
                if (cnt[i] == 3) 
                {
                    f3 = 1;
                }
                if (cnt[i] == 2) 
                {
                    c2++;
                }
            }
            if (f3)
            {
                if (c2) id = 6;
                else id = 3;
            }
            else if (c2 == 2) id = 2;
            else if (c2 == 1) id = 1;
            int ff = 0;
            for (int i = 2;i <= 10;i++)
            {
                if (cnt[i] && cnt[i + 1] && cnt[i + 2] && cnt[i + 3] && cnt[i + 4]) ff = 1;
            }
            if (f) id = max(id,4);
        }
    }
    bool operator < (const node& B) const
    {
        if (id != B.id) return id < B.id;
        else 
        {
            if (b == B.b) return true;
            // return b < B.b;
            for (int i = 0;i < b.size();i++)
            {
                if (b[i].fi == B.b[i].fi) continue;
                return b[i].fi < B.b[i].fi;
            }
        }
    }
};

void solve()
{
    set<pii> used;
    node a,b;
    a.b.resize(4);
    b.b.resize(4);
    vvt vis(15,vt(4,1));
    for (int i = 0;i < 8;i++)
    {
        string s;
        cin >> s;
        int x = 0,y;
        if (s[0] >= '2' && s[0] <= '9') x = s[0] - '0';
        else if (s[0] == 'T') x = 10;
        else if (s[0] == 'J') x = 11;
        else if (s[0] == 'Q') x = 12;
        else if (s[0] == 'K') x = 13;
        else x = 14;
        if (s[1] == 'C') y = 0;
        else if (s[1] == 'D') y = 1;
        else if (s[1] == 'H') y = 2;
        else y = 3;
        used.insert({x,y}); 
        if (i < 4) a.b[i] = {x,y};
        else b.b[i - 4] = {x,y};
        // cout << x << " " << y << endl;
        vis[x][y] = 0;
    }
    for (int i = 2;i <= 14;i++)
    {
        for (int j = 0;j < 4;j++)
        {
            int f = 1;
            if (used.count({i,j})) continue;
            for (int ii = 2;ii <= 14;ii++)
            {
                for (int jj = 0;jj < 4;jj++)
                {
                    if ((ii == i && jj == j) || (used.count({ii,jj}))) continue;
                    a.b.push_back({ii,jj});
                    b.b.push_back({i,j});
                    if (b < a) f = 0; 
                    a.fff();
                    b.fff();
                    if (a < b) 
                    {
                        vis[ii][jj] = 0;
                    }
                    a.b.pop_back();
                    b.b.pop_back();
                }
            }
            if (f) 
            {
                cout << "GeiWoCaPiXie" << endl;
                return ;
            }
        }
    }
    for (int i = 2;i <= 14;i++)
    {
        for (int j = 0;j < 4;j++)
        {
            if (vis[i][j]) 
            {
                // cout << i << " " << j << endl;
                cout << "WoYaoYanPai" << endl;
                return ;
            }
        }
    }
    cout << "PaiMeiYouWenTi" << endl;
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