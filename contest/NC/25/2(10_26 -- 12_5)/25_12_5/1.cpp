#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    vector<int> a(14),b(14);
    for (int i = 0;i < 4;i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0;i < 4;i++)
    {
        int x;
        cin >> x;
        b[x]++;
    }
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());

    int win_p = 0,pin_p = 0,los_p = 0;
    int win_q = 0,pin_q = 0,los_q = 0;

    if (a[0] == 4) 
    {
        if (b[0] == 4)
        {
            win_p = 0;
            win_q = 1;
            pin_p = 1;
            pin_q = 1;
            los_p = 0;
            los_q = 1;
        }  
        else if (b[0] == 3) 
        {
            win_p = 12;
            win_q = 13;
            los_p = 0;
            los_q = 1;
            pin_p = 1;
            pin_q = 13;
        }
        else 
        {
            win_p = 1;
            win_q = 1;
            los_p = 0;
            los_q = 1;
            pin_p = 0;
            pin_q = 1;
        }
    } 
    else if (a[0] == 3)
    {
        if (b[0] == 4)
        {
            win_p = 0;
            win_q = 1;
            pin_p = 1;
            pin_q = 13;
            los_p = 12;
            los_q = 13;
        }
        else if (b[0] == 3)
        {
            win_p = 12;
            win_q = 169;
            pin_p = 145;
            pin_q = 169;
            los_p = 12;
            los_q = 169;
        }
        else if (b[0] == 2)
        {
            if (b[1] == 2)
            {
                win_p = 24;
                win_q = 169;
                pin_p = 123;
                pin_q = 169;
                los_p = 22;
                los_q = 169;
            }
            else 
            {
                win_p = 2;
                win_q = 13;
                pin_p = 11;
                pin_q = 13;
                los_p = 0;
                los_q = 1;
            }
        }
        else 
        {
            win_p = 2;
            win_q = 13;
            pin_p = 11;
            pin_q = 13;
            los_p = 0;
            los_q = 1;
        }
    }
    else if (a[0] == 2)
    {
        if (a[1] == 2)
        {
            if (b[0] == 4)
            {
                win_p = 0;
                win_q = 1;
                pin_p = 0;
                pin_q = 1;
                los_p = 1;
                los_q = 1;
            }
            else if (b[0] == 3)
            {
                win_p = 22;
                win_q = 169;
                pin_p = 123;
                pin_q = 169;
                los_p = 24;
                los_q = 169;
            }
            else if (b[0] == 2)
            {
                if (b[1] == 2)
                {
                    win_p = 22;
                    win_q = 169;
                    pin_p = 125;
                    pin_q = 169;
                    los_p = 22;
                    los_q = 169;
                }
                else 
                {
                    win_p = 2;
                    win_q = 13;
                    pin_p = 11;
                    pin_q = 13;
                    los_p = 0;
                    los_q = 1;
                }
            }
            else 
            {
                win_p = 2;
                win_q = 13;
                pin_p = 11;
                pin_q = 13;
                los_p = 0;
                los_q = 1;
            }
        }
        else 
        {
            if (b[0] == 4)
            {
                win_p = 1;
                win_q = 1;
                pin_p = 0;
                pin_q = 1;
                los_p = 0;
                los_q = 1;
            }
            else if (b[0] == 3)
            {
                win_p = 0;
                win_q = 1;
                pin_p = 11;
                pin_q = 13;
                los_p = 2;
                los_q = 13;
            }
            else if (b[0] == 2)
            {
                if (b[1] == 2)
                {
                    win_p = 0;
                    win_q = 1;
                    pin_p = 11;
                    pin_q = 13;
                    los_p = 2;
                    los_q = 13;
                }
                else 
                {
                    win_p = 0;
                    win_q = 1;
                    pin_p = 1;
                    pin_q = 1;
                    los_p = 0;
                    los_q = 1;
                }
            }
            else 
            {
                win_p = 0;
                win_q = 1;
                pin_p = 1;
                pin_q = 1;
                los_p = 0;
                los_q = 1;
            }
        }
    }
    else if (a[0] == 1)
    {
        win_p = 0;
        win_q = 1;
        if (b[0] == 4) 
        {
            pin_p = 0;
            pin_q = 1;
            los_p = 1;
            los_q = 1;
        }
        else if (b[0] == 3)
        {
            pin_p = 11;
            pin_q = 13;
            los_p = 2;
            los_q = 13;
        }
        else if (b[0] == 2)
        {
            if (b[1] == 2)
            {
                pin_p = 11;
                pin_q = 13;
                los_p = 2;
                los_q = 13;
            }
            else 
            {
                pin_p = 1;
                pin_q = 1;
                los_p = 0;
                los_q = 1;
            }
        }
        else 
        {
            pin_p = 1;
            pin_q = 1;
            los_p = 0;
            los_q = 1;
        }
    }


    cout << win_p << "/" << win_q << " " << pin_p << "/" << pin_q << " " << los_p <<"/" << los_q;

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