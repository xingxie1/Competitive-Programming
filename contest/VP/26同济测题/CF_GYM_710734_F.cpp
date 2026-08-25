#include <bits/stdc++.h>
using namespace std;

// 保留你的习惯：int 统一替换为 long long。
// 若不喜欢宏，可删除本行并把整数点写成 Point<long long>。
#define int long long

using i128 = __int128_t;
using u128 = __uint128_t;
using ff = long double;

using arr2 = array<int, 2>;
using arr3 = array<int, 3>;

constexpr ff EPS = 1e-9;
constexpr ff INF = 1e100;
const ff PI = acos(-1.0);

constexpr int MOD998 = 998244353;
constexpr int INV2_998 = 499122177;

// 0. 基础工具
//int sgn(T x)判断浮点数正负还是0
//i128 gcd128(i128 a, i128 b)
//void print128(i128 x)输出128
//int norm_mod(i128 x, int mod = MOD998)i128 整数规范到 [0, mod)
//int mul_mod(int a, int b, int mod = MOD998)数乘取模
//int inv_mod_prime(int a, int mod = MOD998)算逆元
//bool same_point(const Point<T>& a, const Point<T>& b)判断浮点相同
// i128 dot128(const Point<int>& a, const Point<int>& b)
// i128 cross128(const Point<int>& a, const Point<int>& b)
// i128 orient128(a -> b -> c中间的b是什么转向
//     const Point<int>& a,
//     const Point<int>& b,
//     const Point<int>& c
// )
// polar_cmp极角排序
// polar_cmp128
// bool same_direction128(const Point<int>& a, const Point<int>& b)128判断距离是否相同
// bool online(Point<T> p, Line<T> l)点是否在直线上
// bool onray(Point<T> p, Point<T> o, Point<T> d)点 p 是否在以 o 为起点、d 为方向向量的射线上
// i128 len2_128(const Point<int>& a)距离平方128
// bool onseg(Point<T> p, Point<T> a, Point<T> b)点是否在线段上
// int unseg(Point<T> a, Point<T> b, Point<T> c, Point<T> d)返回线段相交类型
// online128
// onray128
// onseg128
// segment_intersection_type128返回线段相交类型128
// Point<ff> inter(Line<ff> a, Line<ff> b)两直线交点
// Point<ff> proj(Point<ff> p, Line<ff> l)点在直线上的投影
// ff dist_p_s(Point<ff> p, Point<ff> a, Point<ff> b)点到线段距离
// ff dist_s_s(Point<ff> a, Point<ff> b, Point<ff> c, Point<ff> d)两线段之间的距离

template <class T>
//判断浮点数正负还是0
int sgn(T x) {
    if constexpr (is_floating_point_v<T>) {
        if (abs(x) < EPS) return 0;
        return x < 0 ? -1 : 1;
    } else {
        return (x > 0) - (x < 0);
    }
}

i128 abs128(i128 x) {
    return x < 0 ? -x : x;
}

i128 gcd128(i128 a, i128 b) {
    a = abs128(a);
    b = abs128(b);
    while (b != 0) {
        i128 r = a % b;
        a = b;
        b = r;
    }
    return a;
}

string to_string128(i128 x) {
    if (x == 0) return "0";
    bool negative = x < 0;
    if (negative) x = -x;

    string s;
    while (x > 0) {
        s.push_back(char('0' + (int)(x % 10)));
        x /= 10;
    }
    if (negative) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}
//输出128
void print128(i128 x) {
    cout << to_string128(x);
}

// 将任意 i128 整数规范到 [0, mod)。
int norm_mod(i128 x, int mod = MOD998) {
    x %= mod;
    if (x < 0) x += mod;
    return (int)x;
}

// 适用于 long long 范围模数的安全模乘。
int mul_mod(int a, int b, int mod = MOD998) {
    return (int)((i128)norm_mod(a, mod) * norm_mod(b, mod) % mod);
}

int qpow(int a, int b, int mod = MOD998) {
    int ans = 1 % mod;
    a = norm_mod(a, mod);
    while (b > 0) {
        if (b & 1) ans = mul_mod(ans, a, mod);
        a = mul_mod(a, a, mod);
        b >>= 1;
    }
    return ans;
}
//逆元
// mod 为质数且 a 不被 mod 整除时使用。
int inv_mod_prime(int a, int mod = MOD998) {
    return qpow(a, mod - 2, mod);
}

// 1. 点与向量

template <class T>
struct Point {
    T x, y;

    Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}

    Point operator+() const { return *this; }
    Point operator-() const { return Point(-x, -y); }

    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
//     放大缩小向量长度
    Point operator*(const T& k) const { return Point(x * k, y * k); }
    Point operator/(const T& k) const { return Point(x / k, y / k); }

    Point& operator+=(const Point& p) {
        x += p.x;
        y += p.y;
        return *this;
    }

    Point& operator-=(const Point& p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }

    // 整数坐标很大时，下面三个函数可能溢出；紧随其后有 i128 对应版。
    // 点乘
    T dot(const Point& p) const { return x * p.x + y * p.y; }
    // 叉乘
    T cross(const Point& p) const { return x * p.y - y * p.x; }
    T len2() const { return x * x + y * y; }

    T operator*(const Point& p) const { return dot(p); }
    T operator^(const Point& p) const { return cross(p); }

    ff len() const { return hypot((ff)x, (ff)y); }
    //hypot 等价于 sqrt(x * x + y * y)
    //逆时针转90°
    //构造法向量
    Point rot90() const { return Point(-y, x); }
    //顺时针转90°
    Point rot90r() const { return Point(y, -x); }
    //旋转任意角
    //单位是弧度，逆时针是正
    // const ff PI = acos(-1);
    // Point<ff> v(1, 0);
    // auto u = v.rot(PI / 2); // 约为 (0, 1)
    // auto result = o + (p - o).rot(rad);
    Point<ff> rot(ff rad) const {
        return Point<ff>(
            (ff)x * cos(rad) - (ff)y * sin(rad),
            (ff)x * sin(rad) + (ff)y * cos(rad)
        );
    }
    //返回与向量同方向，长度为1的浮点向量
    Point<ff> unit() const {
        ff length = len();
        return Point<ff>((ff)x / length, (ff)y / length);
    }

    // 按 x 为第一关键字、y 为第二关键字排序
    // 用于 sort、set、map，不表示几何中的左右关系
    bool operator<(const Point& p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    // 判断两个点是否相同
    //整数点用
    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }

    friend istream& operator>>(istream& is, Point& p) {
        return is >> p.x >> p.y;
    }

    friend ostream& operator<<(ostream& os, const Point& p) {
        return os << p.x << ' ' << p.y;
    }
};

template <class T>
Point<T> operator*(const T& k, const Point<T>& p) {
    return p * k;
}

template <class T>
using Vector = Point<T>;
//判断浮点是否相同
template <class T>
bool same_point(const Point<T>& a, const Point<T>& b) {
    return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;
}

//点乘叉乘128防溢出

i128 dot128(const Point<int>& a, const Point<int>& b) {
    return (i128)a.x * b.x + (i128)a.y * b.y;
}

i128 cross128(const Point<int>& a, const Point<int>& b) {
    return (i128)a.x * b.y - (i128)a.y * b.x;
}
//orient128() 接收的是三个点，判断从
//a -> b -> c
//中间的b是什么转向
i128 orient128(
    const Point<int>& a,
    const Point<int>& b,
    const Point<int>& c
) {
    return cross128(b - a, c - a);
}

i128 len2_128(const Point<int>& a) {
    return dot128(a, a);
}

// 2. 极角排序

template <class T>
int half(const Point<T>& p) {
    return sgn(p.y) > 0 || (sgn(p.y) == 0 && sgn(p.x) > 0) ? 0 : 1;
}

// 普通版：整数分量很大时 a^b、len2() 可能溢出。
// 把向量按照从 x 轴正方向开始的逆时针顺序排序
// 绕原点排序
// vector<Point<int>> v(n);
// sort(v.begin(), v.end(), polar_cmp<int>);
// 绕o点排序
// sort(points.begin(), points.end(), [&](auto a, auto b) {
//     return polar_cmp(a - o, b - o);
// });
template <class T>
bool polar_cmp(const Point<T>& a, const Point<T>& b) {
    int ha = half(a), hb = half(b);
    if (ha != hb) return ha < hb;

    auto cr = a ^ b;
    if (sgn(cr) != 0) return sgn(cr) > 0;
    return a.len2() < b.len2();
}

//极角排序防溢出

bool polar_cmp128(const Point<int>& a, const Point<int>& b) {
    int ha = half(a), hb = half(b);
    if (ha != hb) return ha < hb;

    i128 cr = cross128(a, b);
    if (cr != 0) return cr > 0;
    return len2_128(a) < len2_128(b);
}

bool same_direction128(const Point<int>& a, const Point<int>& b) {
    return cross128(a, b) == 0 && dot128(a, b) > 0;
}

// 3. 直线、射线、线段

template <class T>
struct Line {
    Point<T> p;  // 起点
    Point<T> v;  // 方向向量

    Line() = default;
    Line(Point<T> p_, Point<T> v_) : p(p_), v(v_) {}

    static Line make(Point<T> a, Point<T> b) {
        return Line(a, b - a);
    }
};

// 普通版：整数坐标很大时叉积、点积可能溢出
//点是否在直线上
template <class T>
bool online(Point<T> p, Line<T> l) {
    return sgn((p - l.p) ^ l.v) == 0;
}

template <class T>
// 点 p 是否在以 o 为起点、d 为方向向量的射线上
// 包含射线端点 o
bool onray(Point<T> p, Point<T> o, Point<T> d) {
    // 零向量不能表示正常射线
    // 这里把退化射线当作单独一个点 o
    if (sgn(d.len2()) == 0) return same_point(p, o);
    Point<T> op = p - o;
    // 叉乘为 0：共线
    // 点乘 >= 0：与射线方向相同或位于端点
    return sgn(d ^ op) == 0 && sgn(d * op) >= 0;
}

template <class T>
//点是否在线段上
// if (onseg(p, a, b)) {
    // p 在线段 ab 上
// }
bool onseg(Point<T> p, Point<T> a, Point<T> b) {
    return sgn((p - a) ^ (p - b)) == 0
        && sgn((p - a) * (p - b)) <= 0;
}

template <class T>
int segment_intersection_type(
    Point<T> a, Point<T> b,
    Point<T> c, Point<T> d
) {
    if (
        max(a.x, b.x) < min(c.x, d.x) ||
        max(c.x, d.x) < min(a.x, b.x) ||
        max(a.y, b.y) < min(c.y, d.y) ||
        max(c.y, d.y) < min(a.y, b.y)
    ) {
        return 0;
    }

    int c1 = sgn((b - a) ^ (c - a));
    int c2 = sgn((b - a) ^ (d - a));
    int c3 = sgn((d - c) ^ (a - c));
    int c4 = sgn((d - c) ^ (b - c));

    if (c1 == 0 && c2 == 0) return 3;
    if (c1 * c2 < 0 && c3 * c4 < 0) return 1;
    if (c1 * c2 <= 0 && c3 * c4 <= 0) return 2;
    return 0;
}

// 返回线段相交类型
// 0：不相交；1：规范相交；2：端点相交；3：共线且有重合
template <class T>
int unseg(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
    return segment_intersection_type(a, b, c, d);
}

// 整数几何防溢出

bool online128(Point<int> p, Line<int> l) {
    return cross128(p - l.p, l.v) == 0;
}

bool onray128(Point<int> p, Point<int> o, Point<int> d) {
    if (len2_128(d) == 0) return p == o;
    Point<int> op = p - o;
    return cross128(d, op) == 0 && dot128(d, op) >= 0;
}

bool onseg128(Point<int> p, Point<int> a, Point<int> b) {
    return orient128(a, b, p) == 0
        && dot128(p - a, p - b) <= 0;
}

int segment_intersection_type128(
    Point<int> a, Point<int> b,
    Point<int> c, Point<int> d
) {
    if (
        max(a.x, b.x) < min(c.x, d.x) ||
        max(c.x, d.x) < min(a.x, b.x) ||
        max(a.y, b.y) < min(c.y, d.y) ||
        max(c.y, d.y) < min(a.y, b.y)
    ) {
        return 0;
    }

    int c1 = sgn(orient128(a, b, c));
    int c2 = sgn(orient128(a, b, d));
    int c3 = sgn(orient128(c, d, a));
    int c4 = sgn(orient128(c, d, b));

    if (c1 == 0 && c2 == 0) return 3;
    if (c1 * c2 < 0 && c3 * c4 < 0) return 1;
    if (c1 * c2 <= 0 && c3 * c4 <= 0) return 2;
    return 0;
}

// 必须保证两直线不平行且方向向量非零。
Point<ff> line_intersection(Line<ff> a, Line<ff> b) {
    ff t = ((b.p - a.p) ^ b.v) / (a.v ^ b.v);
    return a.p + a.v * t;
}
// 两直线交点
// Point<ff> p = inter(l1, l2);
// 必须保证两直线不平行
// 用之前先判断线段交点情况或者向量叉乘不为零
Point<ff> inter(Line<ff> a, Line<ff> b) {
    return line_intersection(a, b);
}

Point<ff> projection(Point<ff> p, Line<ff> l) {
    ff t = ((p - l.p) * l.v) / (l.v * l.v);
    return l.p + l.v * t;
}
// 点在直线上的投影
// Point<ff> foot = proj(p, l);
// 返回点 p 到无限直线 l 的垂足
Point<ff> proj(Point<ff> p, Line<ff> l) {
    return projection(p, l);
}

ff distance_point_segment(Point<ff> p, Point<ff> a, Point<ff> b) {
    if (same_point(a, b)) return (p - a).len();
    Point<ff> v = b - a;
    ff t = ((p - a) * v) / (v * v);
    if (t < 0) return (p - a).len();
    if (t > 1) return (p - b).len();
    return (p - (a + v * t)).len();
}
//点到线段距离
// 函数内部自动区分：
// 垂足在线段内部：返回点到垂足的距离
// 垂足在线段外：返回点到较近端点的距离
// a == b：把线段当作一个点
ff dist_p_s(Point<ff> p, Point<ff> a, Point<ff> b) {
    return distance_point_segment(p, a, b);
}

ff distance_segment_segment(
    Point<ff> a, Point<ff> b,
    Point<ff> c, Point<ff> d
) {
    if (segment_intersection_type(a, b, c, d) != 0) return 0;
    return min({
        distance_point_segment(a, c, d),
        distance_point_segment(b, c, d),
        distance_point_segment(c, a, b),
        distance_point_segment(d, a, b)
    });
}
// 两线段之间的距离
// 如果两条线段相交，返回 0
// 如果不相交，计算四个端点到另一条线段距离的最小值
ff dist_s_s(Point<ff> a, Point<ff> b, Point<ff> c, Point<ff> d) {
    return distance_segment_segment(a, b, c, d);
}
// 4. 多边形面积、边界格点与 Pick 定理
// T area(const vector<Point<T>>& poly)多边形2倍面积
// ff Area(const vector<Point<T>>& poly)实际面积
// i128 area2_128(const vector<Point<int>>& poly)多边形2倍面积128
// int area2_mod_ccw(二倍面积取模
//     const vector<Point<int>>& poly,
//     int mod = MOD998
// )
// i128 boundary_lattice128(const vector<Point<int>>& poly)多边形边界格点数
// int boundary_lattice_mod(多边形边界格点数取模
//     const vector<Point<int>>& poly,
//     int mod = MOD998
// )
// 普通二倍面积：T 可能溢出。
template <class T>
T area2(const vector<Point<T>> &poly)
{
    T ans = 0;
    int n = (int)poly.size();
    for (int i = 0; i < n; ++i)
    {
        ans += poly[i] ^ poly[(i + 1) % n];
    }
    return abs(ans);
}

// 多边形面积
// 多边形顶点必须按顺时针或逆时针顺序给出
// 会返回面积的两倍
template <class T>
T area(const vector<Point<T>> &poly)
{
    return area2(poly);
}

template <class T>
// 返回实际面积
ff Area(const vector<Point<T>> &poly)
{
    return (ff)area2(poly) / 2.0;
}

i128 signed_area2_128(const vector<Point<int>> &poly)
{
    i128 ans = 0;
    int n = (int)poly.size();
    for (int i = 0; i < n; ++i)
    {
        ans += cross128(poly[i], poly[(i + 1) % n]);
    }
    return ans;
}
// 二倍面积防溢出
i128 area2_128(const vector<Point<int>> &poly)
{
    return abs128(signed_area2_128(poly));
}

// 二倍面积取模版
// 要求顶点按逆时针排列，因为模意义下不能直接做“绝对值”
// 每次乘法先取模，不保存真实面积；适合只需要答案 mod 的题
int area2_mod_ccw(
    const vector<Point<int>> &poly,
    int mod = MOD998)
{
    int ans = 0;
    int n = (int)poly.size();

    for (int i = 0; i < n; ++i)
    {
        const auto &a = poly[i];
        const auto &b = poly[(i + 1) % n];

        int term = norm_mod(
            (i128)norm_mod(a.x, mod) * norm_mod(b.y, mod) - (i128)norm_mod(a.y, mod) * norm_mod(b.x, mod),
            mod);

        ans += term;
        if (ans >= mod)
            ans -= mod;
    }

    return ans;
}

// 多边形边界格点数 B = sum gcd(|dx|, |dy|)
// 顶点必须是格点并按边界顺序给出
i128 boundary_lattice128(const vector<Point<int>> &poly)
{
    i128 ans = 0;
    int n = (int)poly.size();
    for (int i = 0; i < n; ++i)
    {
        Point<int> d = poly[(i + 1) % n] - poly[i];
        ans += gcd128(d.x, d.y);
    }
    return ans;
}

int boundary_lattice_mod(
    const vector<Point<int>> &poly,
    int mod = MOD998)
{
    int ans = 0;
    int n = (int)poly.size();
    for (int i = 0; i < n; ++i)
    {
        Point<int> d = poly[(i + 1) % n] - poly[i];
        int contribution = std::gcd(llabs(d.x), llabs(d.y)) % mod;
        ans += contribution;
        if (ans >= mod)
            ans -= mod;
    }
    return ans;
}

struct PickInfo
{
    i128 area2;    // 二倍面积
    i128 inside;   // 内部格点数
    i128 boundary; // 边界格点数
    i128 total;    // 内部 + 边界
};

PickInfo pick128(const vector<Point<int>> &poly)
{
    i128 a2 = area2_128(poly);
    i128 boundary = boundary_lattice128(poly);
    i128 inside = (a2 - boundary + 2) / 2;
    return {a2, inside, boundary, inside + boundary};
}

// 兼容旧函数名。
template <class T>
PickInfo pick(const vector<Point<T>> &poly)
{
    static_assert(is_integral_v<T>, "Pick theorem requires lattice points");
    vector<Point<int>> converted;
    converted.reserve(poly.size());
    for (const auto &p : poly)
        converted.emplace_back((int)p.x, (int)p.y);
    return pick128(converted);
}

struct PickModInfo
{
    int area2;
    int inside;
    int boundary;
    int total;
};

// 顶点必须逆时针，mod 必须为奇质数。
PickModInfo pick_mod_ccw(
    const vector<Point<int>> &poly,
    int mod = MOD998)
{
    int a2 = area2_mod_ccw(poly, mod);
    int boundary = boundary_lattice_mod(poly, mod);
    int inv2 = inv_mod_prime(2, mod);
    int inside = mul_mod(norm_mod((i128)a2 - boundary + 2, mod), inv2, mod);
    int total = inside + boundary;
    if (total >= mod)
        total -= mod;
    return {a2, inside, boundary, total};
}

void solve() 
{
    int n;
    cin >> n;
    vector<Point<ff>> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    auto f = [&](Point<ff> p,Point<ff> r1,Point<ff> r2) -> pair<ff,ff>
    {
        Line<ff> l(r1,r2 - r1);
        Point<ff> d = proj(p,l);
        return {min((r1 - d).len(),(r2 - d).len()),(p - d).len()};
    };
    vector<pair<ff,ff>> w;
    for(int i = 0 ; i < n ; i++){
        Point<ff> r1 = a[(i + n - 1) % n];
        Point<ff> r2 = a[(i + n - 2) % n];
        auto [x , y] = f(a[i],r1,r2);
        w.push_back({x,y});
    }
    for (int i = 0; i < n; i++)
    {
        Point<ff> r1 = a[(i + n + 1) % n];
        Point<ff> r2 = a[(i + n + 2) % n];
        auto [y , x] = f(a[i], r1, r2);
        w.push_back({x, y});
    }
    sort(w.begin(),w.end());
    ff yn = 1e100;
    vector<pair<ff, ff>> v;
    for(int i = 0 ; i < w.size() ; i++){
        if(w[i].second < yn){
            yn = w[i].second;
            v.push_back(w[i]);
        }
    }
    vector<Point<ff>> g;
    Point<ff> o(0,0);
    g.push_back(o);
    Point<ff> xx(v[0].first, 0);
    Point<ff> yy(0, v[v.size() - 1].second);
    g.push_back(xx);
    // cout << v.size() << "\n";
    int u = v.size();
    for(int i = 0 ; i < u - 2 ; i++){
        Point<ff> lx1(v[i].first, 0);
        Point<ff> ly1(0,v[i].second);
        Point<ff> lx2(v[i + 1].first, 0);
        Point<ff> ly2(0, v[i + 1].second);
        Line<ff> l1(lx1, ly1 - lx1);
        Line<ff> l2(lx2, ly2 - lx2);
        Point<ff> dd = inter(l1,l2);
        g.push_back(dd);
    }
    g.push_back(yy);
    cout << Area(g) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;

    cout << fixed << setprecision(30);
    while (test_cases--) solve();
    return 0;
}