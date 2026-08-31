#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using vll = vector<ll>;

void solve()
{
    string s;
    map<string,char> p;
    p[".-"] = 'A';
    p["-..."] = 'B';
    p["-.-."] = 'C';
    p["-.."] = 'D';
    p["."] = 'E';
    p["..-."] = 'F';
    p["--."] = 'G';
    p["...."] = 'H';
    p[".."] = 'I';
    p[".---"] = 'J';
    p["-.-"] = 'K';
    p[".-.."] = 'L';
    p["--"] = 'M';
    p["-."] = 'N';
    p["---"] = 'O';
    p[".--."] = 'P';
    p["--.-"] = 'Q';
    p[".-."] = 'R';
    p["..."] = 'S';
    p["-"] = 'T';
    p["..-"] = 'U';
    p["...-"] = 'V';
    p[".--"] = 'W';
    p["-..-"] = 'X';
    p["-.--"] = 'Y';
    p["--.."] = 'Z';
    while (cin >> s) 
    {
        string t,ans;
        for (char c : s)
        {
            if (c == '\n') break;
            if (c == '/') 
            {
                if (t.empty()) ans += ' ';
                else 
                {
                    ans += p[t];
                    t.clear();
                }
            }
            else t += c;
        }
        if (!t.empty()) ans += p[t];
        cout << ans << endl;
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