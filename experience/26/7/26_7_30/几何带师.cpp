#include<bits/stdc++.h>
using namespace std;
#define int long long
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)1e5 + 9;
const int mod = (int)1e9 + 7;

using ff = long double;
using ll = long long;
constexpr ff eps = 1e-9;
constexpr ff inf = 1e18;

template <typename T>
//判断浮点数正负还是0
int sgn(T x) {
    if constexpr (is_floating_point_v<T>) {
        if (abs(x) < eps) return 0;
        return x < 0 ? -1 : 1;
    } else {
        return (x > 0) - (x < 0); 
    }
}

template <class T> 
//创建点与向量,加减乘除
struct Point {
    T x, y;
//     Point<int> a;          (0, 0)
//     Point<int> b(2, 3);    (2, 3)    
    Point (T _x = 0, T _y = 0) : x(_x), y(_y) {}

    Point operator + (const Point& p) const {return Point(x + p.x, y + p.y); }
//     Point<int> a(1, 2);
//     Point<int> b(3, 4);
//     auto c = a + b; // (4, 6)
    Point operator - (const Point& p) const {return Point(x - p.x, y - p.y); }
//     放大缩小向量长度
    Point operator * (const T& v) const {return Point(x * v, y * v); }
    Point operator / (const T& v) const {return Point(x / v, y / v); }
    // 点乘
    T dot (const Point& p) const {return x * p.x + y * p.y; }
    // 叉乘
    T cross (const Point& p) const {return x * p.y - y * p.x; }
// 点乘符号
    T operator * (const Point& p) const {return dot(p); }
// 叉乘符号
    T operator ^ (const Point& p) const {return cross(p); }
    //长度平方
    T len2() const {return x * x + y * y; }
    //实际长度
    ff len() const {return hypot(x, y); }
    //逆时针转90°
    //构造法向量
    Point rot90() const {return Point(-y, x); }
    //顺时针转90°
    Point rot90r() const {return Point(y, -x); }
    //旋转任意角
    //单位是弧度，逆时针是正
    // const ff PI = acos(-1);
    // Point<ff> v(1, 0);
    // auto u = v.rot(PI / 2); // 约为 (0, 1)
    // auto result = o + (p - o).rot(rad);
    Point<ff> rot(ff rad) const {
        return Point<ff>(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
    }
    //返回与向量同方向，长度为1的浮点向量
    Point<ff> unit() const {
        ff l = len();
        return Point<ff>(x / l, y / l);
    }
    
// 按 x 为第一关键字、y 为第二关键字排序
// 用于 sort、set、map，不表示几何中的左右关系
    bool operator < (const Point& p) const {
        return sgn(x - p.x) == 0 ? sgn(y - p.y) < 0 : sgn(x - p.x) < 0;
    }
// 先按y，再x排序与上面相反

    // bool operator < (const Point& p) const {
    //     return sgn(y - p.y) == 0 ? sgn(x - p.x) < 0 : sgn(y - p.y) < 0;
    // }
// 判断两个点是否相同
    bool operator == (const Point& p) const {
        return sgn(x - p.x) == 0 && sgn(y - p.y) == 0;
    }
    //输入
    // Point<int> p;
    // cin >> p;

    friend istream& operator>>(istream& is, Point& p) {
        return is >> p.x >> p.y;
    }
    //输出
    // cout << p;    
    friend ostream& operator<<(ostream& os, const Point& p) {
        return os << p.x << " " << p.y;
    }
};

template <class T>
//极角排序
int half(const Point<T>& p) {
    return p.y > 0 || (p.y == 0 && p.x > 0) ? 0 : 1;
}

template <class T>
// 把向量按照从 x 轴正方向开始的逆时针顺序排序
// 绕原点排序
// vector<Point<int>> v(n);
// sort(v.begin(), v.end(), polar_cmp<int>);
// 绕o点排序
// sort(points.begin(), points.end(), [&](auto a, auto b) {
//     return polar_cmp(a - o, b - o);
// });
bool polar_cmp(const Point<T>& a, const Point<T>& b) {
    int ha = half(a), hb = half(b);
    if (ha != hb) return ha < hb; 
    return sgn(a ^ b) > 0;        
}

// Vector 只是 Point 的类型别名，二者底层完全相同
template <class T> using Vector = Point<T>;

template <class T>
// 创建直线
// 起点+方向向量
// 直接创建
// Line<ff> l(p, v);
// 两点创建
// auto l = Line<ff>::make(a, b);
// p是a，a不能跟b相同
struct Line {
    Point<T> p, v;
    Line() {}
    Line(Point<T> _p, Point<T> _v) : p(_p), v(_v) {}

    static Line make(Point<T> a, Point<T> b) { 
    	return Line(a, b - a); 
    }
};

template <class T>
//点是否在直线上
bool online(Point<T> p, Line<T> l) {
    return sgn((p - l.p) ^ l.v) == 0;
}
template <class T>
// 点 p 是否在以 o 为起点、d 为方向向量的射线上
// 包含射线端点 o
bool onray(Point<T> p, Point<T> o, Point<T> d) {
    // 零向量不能表示正常射线
    // 这里把退化射线当作单独一个点 o
    if (sgn(d.len2()) == 0) {
        return p == o;
    }

    Point<T> op = p - o;

    // 叉乘为 0：共线
    // 点乘 >= 0：与射线方向相同或位于端点
    return sgn(d ^ op) == 0
        && sgn(d * op) >= 0;
}
template <class T>
//点是否在线段上
// if (onseg(p, a, b)) {
    // p 在线段 ab 上
// }
bool onseg(Point<T> p, Point<T> a, Point<T> b) {
    return sgn((p - a) ^ (p - b)) == 0 && sgn((p - a) * (p - b)) <= 0;
}

// 返回线段相交类型
// 0: 不相交
// 1: 规范相交 (交于内部唯一一点)
// 2: 端点相交 (形成 T 型或 L 型拐角)
// 3: 共线且部分/完全重合 (有无数个交点)
template <class T>
int unseg(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
    if (max(a.x, b.x) < min(c.x, d.x) || max(c.x, d.x) < min(a.x, b.x) || 
        max(a.y, b.y) < min(c.y, d.y) || max(c.y, d.y) < min(a.y, b.y)) {
        return 0;
    }
    int c1 = sgn((b - a) ^ (c - a));
    int c2 = sgn((b - a) ^ (d - a));
    int c3 = sgn((d - c) ^ (a - c));
    int c4 = sgn((d - c) ^ (b - c));

    if (c1 == 0 && c2 == 0) {
        return 3; 
    }

    if (c1 * c2 < 0 && c3 * c4 < 0) {
        return 1;
    }

    if (c1 * c2 <= 0 && c3 * c4 <= 0) {
        return 2; 
    }

    return 0;
}
// 两直线交点
// Point<ff> p = inter(l1, l2);
// 必须保证两直线不平行
// 用之前先判断线段交点情况或者向量叉乘不为零
Point<ff> inter(Line<ff> a, Line<ff> b) {
    ff t = ((b.p - a.p) ^ b.v) / (a.v ^ b.v);
    return a.p + a.v * t;
}
// 点在直线上的投影
// Point<ff> foot = proj(p, l);
// 返回点 p 到无限直线 l 的垂足
Point<ff> proj(Point<ff> p, Line<ff> l) {
    ff t = ((p - l.p) * l.v) / (l.v * l.v);
    return l.p + l.v * t;
}

//点到线段距离
// 函数内部自动区分：
// 垂足在线段内部：返回点到垂足的距离
// 垂足在线段外：返回点到较近端点的距离
// a == b：把线段当作一个点
ff dist_p_s (Point<ff>p, Point<ff> a, Point<ff> b) {
    if (a == b) return (p - a).len();
    Point<ff> v = b - a;
    ff t = ((p - a) * v) / (v * v);
    if (t < 0) return (p - a).len();
    if (t > 1) return (p - b).len();
    Point<ff> proj = a + v * t;
    return (p - proj).len();
}
// 两线段之间的距离
// 如果两条线段相交，返回 0
// 如果不相交，计算四个端点到另一条线段距离的最小值
ff dist_s_s (Point<ff> p1, Point<ff> p2, Point<ff> p3, Point<ff> p4) {
    if (unseg(p1, p2, p3, p4)) return 0;
    return min({dist_p_s(p1, p3, p4), dist_p_s(p2, p3, p4), dist_p_s(p3, p1, p2), dist_p_s(p4, p1, p2),});
}
 

template <class T> 
// 多边形面积
// 多边形顶点必须按顺时针或逆时针顺序给出
// 会返回面积的两倍
T area(const vector<Point<T>>& poly) {
    T res = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        res += (poly[i] ^ (poly[(i + 1) % n]));
    }
    return abs(res);
}

template <class T>
// 返回实际面积
ff Area (const vector<Point<T>>& poly) {
    return area(poly) / 2.0;
}

template <class T>
// 点与多边形关系
// 返回值	    含义
//   0	    多边形外部
//   1	    多边形内部
//   2	    多边形边界上
int ong (Point<T> p, const vector<Point<T>>& poly) {
    int n = poly.size();
    bool in = 0;
    for (int i = 0; i < n; i++) {
        Point<T> v1 = poly[i] - p;
        Point<T> v2 = poly[(i + 1) % n] - p;
        if (sgn(v1 ^ v2) == 0 && sgn(v1 * v2) <= 0) {
            return 2;
        }
        if (sgn(v1.y - v2.y) > 0) swap(v1, v2);
        if (sgn(v1.y) <= 0 && sgn(v2.y) > 0 && sgn(v1 ^ v2) > 0) {
            in ^= 1;
        }
    }
    if (in) return 1;
    else return 0;
}
//按x，y排序
bool cmp_x(const Point<ff>& a, const Point<ff>& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
//按y，x排序
bool cmp_y(const Point<ff>& a, const Point<ff>& b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}
//求弧度
//使用前保证不是零向量
template<class T>
long double angleRad(const Point<T>& a, const Point<T>& b) {
    return atan2l(
        fabsl((long double)(a ^ b)),
        (long double)(a * b)
    );
}
//转角度
template<class T>
double angleDegree(const Point<T>& a, const Point<T>& b) {
    const double PI = acos(-1.0);

    return angleRad(a, b) * 180.0 / PI;
}

// 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
// 根据题目用 FenwickTree<int> t(n) 或者 FenwickTree<long long> t(n) 初始化
template<typename T = int >
class FenwickTree {
    vector<T> tree;

public:
    // 使用下标 1 到 n
    FenwickTree(int n) : tree(n + 1) {}

    // a[i] 增加 val
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    void update(int i, T val) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += val;
        }
    }

    // 求前缀和 a[1] + ... + a[i]
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    T pre(int i) const {
        T res = 0;
        for (; i > 0; i &= i - 1) {
            res += tree[i];
        }
        return res;
    }

    // 求区间和 a[l] + ... + a[r]
    // 1 <= l <= r <= n
    // 时间复杂度 O(log n)
    T query(int l, int r) const {
        if (r < l) {
            return 0;
        }
        return pre(r) - pre(l - 1);
    }

    // 找到最小的下标 pos，满足 a[1] + ... + a[pos] >= k
    // 要求树状数组中维护的是频率/个数，并且 k >= 1 且 k <= pre(n)
    // 时间复杂度 O(log n)
    int kth(T k) const {
        int pos = 0;
        int bit = 1;

        while ((bit << 1) < tree.size()) {
            bit <<= 1;
        }

        for (; bit; bit >>= 1) {
            int nxt = pos + bit;

            if (nxt < tree.size() && tree[nxt] < k) {
                pos = nxt;
                k -= tree[nxt];
            }
        }

        return pos + 1;
    }
};


void solve() {
    const double PI = acos(-1.0);
    int n;
    cin >> n;
    Point<ff> a , b;
    cin >> a >> b;
    vector<Point<ff>> p(n);
    vector<Point<ff>> pl;
    vector<pair<ff,ff>> plj;
    vector<Point<ff>> pr;
    vector<pair<ff,ff>> prj;
    for(int i = 0 ; i < n ; i++){
        cin >> p[i];
    }
    for(int i = 0 ; i < n ; i++){
        if(sgn((a - b) ^ (p[i] - b)) > 0){
            pl.push_back(p[i]);
        }else{
            pr.push_back(p[i]);
        }
    }
    for(int i = 0 ; i < pl.size() ; i++){
        ff p1 = angleRad(pl[i] - a, b - a);
        ff p2 = angleRad(pl[i] - b, a - b);
        plj.push_back({p1,p2});
    }
    for(int i = 0 ; i < pr.size() ; i++){
        ff p1 = angleRad(pr[i] - a, b - a);
        ff p2 = angleRad(pr[i] - b, a - b);
        prj.push_back({p1,p2});
    }
    ranges::sort(plj);
    ranges::sort(prj);
    auto f = [&](vector<pair<ff,ff>>& pj)
    {
        vector<ff> tmp;
        for (auto& [l,r] : pj) tmp.push_back(r);
        ranges::sort(tmp);
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
        int m = tmp.size();
        FenwickTree tr(m);
        ll ans = 0;
        for (auto& [l,r] : pj) 
        {
            int id = ranges::lower_bound(tmp,r) - tmp.begin() + 1;
            ans += tr.pre(id);
            tr.update(id,1);
        }
        return ans;
    };
    ll ans = f(plj) + f(prj);
    // for (auto& [l,r] : plj) cout << l << " " << r << endl;
    // for (auto& [l,r] : prj) cout << l << " " << r << endl;
    auto f1 = [&](vector<pair<ff,ff>>& plj,vector<pair<ff,ff>>& prj)
    {
        vector<vector<ff>> p;
        vector<ff> tmp;
        for (auto& [l,r] : plj) 
        {
            p.push_back({l,r,0});
            tmp.push_back(r);
        }
        for (auto& [l,r] : prj)
        {
            p.push_back({PI - l,PI - r,1});
            tmp.push_back(PI - r);
        }
        ranges::sort(p);
        ranges::sort(tmp);
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
        int m = tmp.size();
        FenwickTree tr(m);
        ll ans = 0;
        for (int i = 0;i < p.size();i++) 
        {
            int id = ranges::lower_bound(tmp,p[i][1]) - tmp.begin() + 1;
            // cout << p[i][1] << " " << id << endl;
            if (p[i][2] == 0)
            {
                tr.update(id,1);
            }
            else 
            {
                ans += tr.pre(id);
            }
        }
        return ans;
    };
    ans += f1(plj,prj);
    cout << ans << endl;    
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
    cout << fixed << setprecision(15);
	// cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}