#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.size();
        vector<int> a(n+1),b(n+1);
        for (int i = 0;i < n;i++)
        {
            if (s[i] == '(') a[i+1] = a[i] + 1;
            else a[i+1] = 0;
        }
        // cout << "a :";
        // for (int i = 0;i <= n;i++) cout << a[i] << " ";
        // cout << endl;
        for (int i = n-1;i >= 0;i--)
        {
            if (s[i] == ')') b[i] = b[i+1] + 1;
            else b[i] = 0;
        }
        // cout << "b :";
        // for (int i = 0;i <= n;i++) cout << b[i] << " ";
        // cout << endl;
        string tmp(s.begin(),s.begin() + k);
        cout << tmp <<endl;
        for (int i = k;i < n - k;i++)
        {
            tmp += s[i];
            if (a[i+1] == k && b[i+1] == k)
            {
                tmp.erase(tmp.end() - k,tmp.end());
                i += k;
            }
        }
        for (int i = n-k;i < n;i++) tmp += s[i];
        return tmp;
    }
};
int main ()
{
    Solution a;
    string s;
    int k;
    cin >> s >> k;
    string ans;
    ans = a.removeSubstring(s,k);
    // cout << ans;

    return 0;
}