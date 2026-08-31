#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using vll = vector<ll>;
using pii = pair<int,int>;
using vpii = vector<pii>;

void solve()
{
    int n;
    while (cin >> n)
    {
        vector<string> a(n);
        for (int i = 0;i < n;i++) cin >> a[i];
        string s;
        cin.ignore();
        getline(cin,s);
        // cin >> s;
        // cout << s;
        // auto f1 = [&](vector<string>& a) 
        // {
        //     auto b = a;
        //     for (int i = 0;i < n;i++) 
        //     {
        //         for (int j = 0;j < n;j++) 
        //         {
        //             b[n - j - 1][i] = a[i][j];
        //             if (a[i][j] == 'v') b[n - j - 1][i] = '>';
        //             else if (a[i][j] == '>') b[n - j - 1][i] = '^';
        //             else if (a[i][j] == '^') b[n - j - 1][i] = '<';
        //             else if (a[i][j] == '<') b[n - j - 1][i] = 'v';
        //             else if (a[i][j] == '|') b[n - j - 1][i] = '-';
        //             else if (a[i][j] == '-') b[n - j - 1][i] = '|';
        //             else if (a[i][j] == '\\') b[n - j - 1][i] = '/';
        //             else if (a[i][j] == '/') b[n - j - 1][i] = '\\';
        //         }
        //     }
        //     a = b;
        // };
        // auto f2 = [&](vector<string>& a) 
        // {
        //     auto b = a;
        //     for (int i = 0;i < n;i++) 
        //     {
        //         for (int j = 0;j < n;j++)
        //         {
        //             // b[i][j] = a[j][n - i - 1];
        //             // if (a[j][n - i - 1] == '>') b[i][j] = 'v';
        //             // else if (a[j][n - i - 1] == 'v') b[i][j] = '<';
        //             // else if (a[j][n - i - 1] == '<') b[i][j] = '^';
        //             // else if (a[j][n - i - 1] == '^') b[i][j] = '>';
        //             // else if (a[j][n - i - 1] == '\\') b[i][j] = '/';
        //             // else if (a[j][n - i - 1] == '/') b[i][j] = '\\';
        //             b[j][n - i - 1] = a[i][j];
        //             if (a[i][j] == '>') b[j][n - i - 1] = 'v';
        //             else if (a[i][j] == 'v') b[j][n - i - 1] = '<';
        //             else if (a[i][j] == '<') b[j][n - i - 1] = '^';
        //             else if (a[i][j] == '^') b[j][n - i - 1] = '>';
        //             else if (a[i][j] == '\\') b[j][n - i - 1] = '/';
        //             else if (a[i][j] == '/') b[j][n - i - 1] = '\\';
        //         }
        //     }
        //     a = b;
        // };
        // auto f3 = [&](vector<string>& a) 
        // {
        //     auto b = a;
        //     for (int i = 0;i < n;i++)
        //     {
        //         for (int j = 0;j < n;j++)
        //         {
        //             b[i][j] = a[n - i - 1][j];
        //             if (a[n - i - 1][j] == '^') b[i][j] = 'v';
        //             else if (a[n - i - 1][j] == 'v') b[i][j] = '^';
        //             else if (a[n - i - 1][j] == '\\') b[i][j] = '/';
        //             else if (a[n - i - 1][j] == '/') b[i][j] = '\\';
        //         }
        //     }
        //     a = b;
        // };
        // auto f4 = [&](vector<string>& a)
        // {
        //     auto b = a;
        //     for (int i = 0;i < n;i++)
        //     {
        //         for (int j = 0;j < n;j++)
        //         {
        //             b[i][j] = a[i][n - j - 1];
        //             if (a[i][n - j - 1] == '<') b[i][j] = '>';
        //             else if (a[i][n - j - 1] == '>') b[i][j] = '<';
        //             else if (a[i][n - j - 1] == '\\') b[i][j] = '/';
        //             else if (a[i][n - j - 1] == '/') b[i][j] = '\\';
        //         }
        //     }
        //     a = b;
        // };
        // auto f5 = [&](vector<string>& a)
        // {
        //     auto b = a;
        //     for (int i = 0;i < n;i++)
        //     {
        //         for (int j = 0;j < n;j++)
        //         {
        //             b[i][j] = a[j][i];
        //             if (a[j][i] == '>') b[i][j] = 'v';
        //             else if (a[j][i] == '<') b[i][j] = '^';
        //             else if (a[j][i] == '^') b[i][j] = '<';
        //             else if (a[j][i] == 'v') b[i][j] = '>';
        //             else if (a[j][i] == '-') b[i][j] = '|';
        //             else if (a[j][i] == '|') b[i][j] = '-';
        //         }
        //     }
        //     a = b;
        // };
        // auto f6 = [&](vector<string>& a)
        // {
        //     auto b = a;
        //     for (int i = 0;i < n;i++)
        //     {
        //         for (int j = 0;j < n;j++)
        //         {
        //             b[i][j] = a[n - j - 1][n - i - 1];
        //             if (a[n - j - 1][n - i - 1] == '^') b[i][j] = '>';
        //             else if (a[n - j - 1][n - i - 1] == '>') b[i][j] = 'v';
        //             else if (a[n - j - 1][n - i - 1] == 'v') b[i][j] = '<';
        //             else if (a[n - j - 1][n - i - 1] == '<') b[i][j] = '^';
        //             else if (a[n - j - 1][n - i - 1] == '-') b[i][j] = '|';
        //             else if (a[n - j - 1][n - i - 1] == '|') b[i][j] = '-';
        //         }
        //     }
        //     a = b;
        // };
        int x = 0,y = 0;
        int f1 = 0;
        map<int,char> p;
        p[1] = '<';
        p[2] = '>';
        p[3] = '^';
        p[4] = 'v';
        p[5] = '|';
        p[6] = '-';
        p[7] = '/';
        p[8] = '\\';
        for (char c : s)
        {
            if (c == '<') 
            {
                int t = x;
                x = n - y - 1;
                y = t;
                for (int i = 1;i <= 8;i++)
                {
                    if (p[i] == 'v') p[i] = '>';
                    else if (p[i] == '>') p[i] = '^';
                    else if (p[i] == '^') p[i] = '<';
                    else if (p[i] == '<') p[i] = 'v';
                    else if (p[i] == '|') p[i] = '-';
                    else if (p[i] == '-') p[i] = '|';
                    else if (p[i] == '\\') p[i] = '/';
                    else if (p[i] == '/') p[i] = '\\';

                }
            }
            else if (c == '>') 
            {
                int t = y;
                y = n - x - 1;
                x = t;
                for (int i = 1;i <= 8;i++)
                {
                    if (p[i] == '>') p[i] = 'v';
                    else if (p[i] == 'v') p[i] = '<';
                    else if (p[i] == '<') p[i] = '^';
                    else if (p[i] == '^') p[i] = '>';
                    else if (p[i] == '\\') p[i] = '/';
                    else if (p[i] == '/') p[i] = '\\';
                }
            }
            else if (c == '-') 
            {
                x = n - x - 1;
                for (int i = 1;i <= 8;i++)
                {
                    if (p[i] == '^') p[i] = 'v';
                    else if (p[i] == 'v') p[i] = '^';
                    else if (p[i] == '\\') p[i] = '/';
                    else if (p[i] == '/') p[i] = '\\';
                }
            }
            else if (c == '|') 
            {
                y = n - y - 1;
                for (int i = 1;i <= 8;i++)
                {
                    if (p[i] == '<') p[i] = '>';
                    else if (p[i] == '>') p[i] = '<';
                    else if (p[i] == '\\') p[i] = '/';
                    else if (p[i] == '/') p[i] = '\\';
                }
            }
            else if (c == '\\')
            {
                swap(x,y);
                for (int i = 1;i <= 8;i++)
                {
                    if (p[i] == '>') p[i] = 'v';
                    else if (p[i] == '<') p[i] = '^';
                    else if (p[i] == '^') p[i] = '<';
                    else if (p[i] == 'v') p[i] = '>';
                    else if (p[i] == '-') p[i] = '|';
                    else if (p[i] == '|') p[i] = '-';
                }
            }
            else if (c == '/') 
            {
                swap(x,y);
                x = n - x - 1;
                y = n - y - 1;
                for (int i = 1;i <= 8;i++)
                {
                    if (p[i] == '^') p[i] = '>';
                    else if (p[i] == '>') p[i] = 'v';
                    else if (p[i] == 'v') p[i] = '<';
                    else if (p[i] == '<') p[i] = '^';
                    else if (p[i] == '-') p[i] = '|';
                    else if (p[i] == '|') p[i] = '-';
                }
            }
        }
        
        for (int i = 0;i < n;i++)
        {
            cout << a[i] << endl;
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}