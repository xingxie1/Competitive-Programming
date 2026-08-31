#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
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
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

struct Node {
    Node* son[2]{};
    int cnt = 0;
};

class Trie {
    Node* root = new Node();

    void destroy(Node* node) {
        if (node == nullptr) {
            return;
        }
        for (Node* son : node->son) {
            destroy(son);
        }
        delete node;
    }

public:
    ~Trie() {
        destroy(root);
    }

    void insert(int x) {
        Node* cur = root;
        cur->cnt++;

        for (int i = 29; i >= 0; i--) {
            int c = x >> i & 1;

            if (cur->son[c] == nullptr) {
                cur->son[c] = new Node();
            }

            cur = cur->son[c];
            cur->cnt++;
        }
    }

    void erase(int x) {
        Node* cur = root;
        cur->cnt--;

        for (int i = 29; i >= 0; i--) {
            int c = x >> i & 1;

            cur = cur->son[c];
            cur->cnt--;
        }
    }

    // 返回一个 y，使 x ^ y 最小
    int min_xor_num(int x) {
        Node* cur = root;
        int y = 0;

        for (int i = 29; i >= 0; i--) {
            int c = x >> i & 1;

            // 希望 x 和 y 当前位相同
            if (cur->son[c] != nullptr && cur->son[c]->cnt > 0) {
                cur = cur->son[c];
                y |= c << i;
            }
            else {
                c ^= 1;
                cur = cur->son[c];
                y |= c << i;
            }
        }

        return y;
    }

    // 返回 min(x ^ y)
    int min_xor(int x) {
        int y = min_xor_num(x);
        return x ^ y;
    }

    // 返回一个 y，使 x ^ y 最大
    int max_xor_num(int x) {
        Node* cur = root;
        int y = 0;

        for (int i = 29; i >= 0; i--) {
            int c = x >> i & 1;

            // 希望 x 和 y 当前位不同
            if (cur->son[c ^ 1] != nullptr && cur->son[c ^ 1]->cnt > 0) {
                c ^= 1;
                cur = cur->son[c];
                y |= c << i;
            }
            else {
                cur = cur->son[c];
                y |= c << i;
            }
        }

        return y;
    }

    // 返回 max(x ^ y)
    int max_xor(int x) {
        int y = max_xor_num(x);
        return x ^ y;
    }
};

void solve()
{
    int n;
    cin >> n;
    vt a(n),b;
    Trie tr;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        if (i) tr.insert(a[i] ^ a[i - 1]);
    }
    vt ans = {a[0]};
    int cur = a[0];
    for (int i = 0;i < n - 1;i++)
    {
        int y = tr.min_xor_num(cur);
        tr.erase(y);
        cur ^= y;
        ans.push_back(cur);
    }
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}