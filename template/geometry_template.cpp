#include <bits/stdc++.h>
using namespace std;

/*
    C++ 计算几何模板（整理自灵茶山艾府 geometry.go 思路）

    使用建议：
    1. 整数坐标优先使用 P = Point<long long>，叉积/点积相关判断尽量走 __int128，避免爆 long long。
    2. 需要交点、距离、圆等浮点结果时使用 PF = Point<long double>。
    3. 浮点输出建议 cout << fixed << setprecision(15)。
    4. 计算几何题最容易错在：精度 eps、边界点、共线、线段端点、坐标范围。
*/

namespace geom {
    using ll = long long;
    using i128 = __int128_t;
    using ld = long double;

    const ld EPS = 1e-12L;
    const ld PI = acosl(-1.0L);
    const i128 INF128 = (i128(1) << 120);

    // 浮点数符号：>EPS 为 1，<-EPS 为 -1，否则认为是 0
    int sgn(ld x) {
        if (x > EPS) return 1;
        if (x < -EPS) return -1;
        return 0;
    }

    bool eq(ld a, ld b) { return fabsl(a - b) <= EPS; }

    // 输出 __int128 调试/交答案用
    string to_string_i128(i128 x) {
        if (x == 0) return "0";
        bool neg = x < 0;
        if (neg) x = -x;
        string s;
        while (x) {
            s.push_back(char('0' + x % 10));
            x /= 10;
        }
        if (neg) s.push_back('-');
        reverse(s.begin(), s.end());
        return s;
    }

    // floor(sqrt(x))，适合 x 在 long long 范围内，避免 sqrt 精度误差
    ll isqrt(ll x) {
        ll r = sqrtl((ld)x);
        while ((i128)(r + 1) * (r + 1) <= x) ++r;
        while ((i128)r * r > x) --r;
        return r;
    }

    // ceil(sqrt(x))
    ll ceil_sqrt(ll x) {
        ll r = isqrt(x);
        return (i128)r * r == x ? r : r + 1;
    }

    bool is_square(ll x) {
        if (x < 0) return false;
        ll r = isqrt(x);
        return (i128)r * r == x;
    }

    // 计算 a^n，但超过 cap 就提前返回 cap+1，防溢出
    ll pow_cap(ll a, int n, ll cap) {
        i128 res = 1, base = a;
        while (n) {
            if (n & 1) {
                res *= base;
                if (res > cap) return cap + 1;
            }
            n >>= 1;
            if (n) {
                base *= base;
                if (base > cap) base = (i128)cap + 1;
            }
        }
        return (ll)res;
    }

    // 返回 floor(x^(1/n))，x>=0, n>1
    ll floor_root_n(ll x, int n) {
        if (x == 0) return 0;
        if (n > 62) return 1;
        ll r = pow((ld)x, 1.0L / n);
        while (pow_cap(r + 1, n, x) <= x) ++r;
        while (pow_cap(r, n, x) > x) --r;
        return r;
    }

    // 浮点数 gcd：常用于角度 gcd，例如 CF 1C
    ld gcd_float(ld a, ld b) {
        a = fabsl(a), b = fabsl(b);
        while (a > EPS) {
            ld t = fmodl(b, a);
            b = a;
            a = t;
        }
        return b;
    }

    template<class T>
    struct Point {
        T x, y;

        Point() : x(0), y(0) {}
        Point(T x, T y) : x(x), y(y) {}

        bool operator < (const Point& b) const {
            if (x != b.x) return x < b.x;
            return y < b.y;
        }

        bool operator == (const Point& b) const {
            return x == b.x && y == b.y;
        }

        bool operator != (const Point& b) const {
            return !(*this == b);
        }

        Point operator + (const Point& b) const { return {x + b.x, y + b.y}; }
        Point operator - (const Point& b) const { return {x - b.x, y - b.y}; }
        Point operator - () const { return {-x, -y}; }
        Point operator * (T k) const { return {x * k, y * k}; }
        Point operator / (T k) const { return {x / k, y / k}; }

        Point& operator += (const Point& b) { x += b.x; y += b.y; return *this; }
        Point& operator -= (const Point& b) { x -= b.x; y -= b.y; return *this; }
        Point& operator *= (T k) { x *= k; y *= k; return *this; }
        Point& operator /= (T k) { x /= k; y /= k; return *this; }
    };

    using P = Point<ll>;      // 整数点/向量
    using PF = Point<ld>;     // 浮点点/向量

    template<class T>
    istream& operator >> (istream& in, Point<T>& p) {
        return in >> p.x >> p.y;
    }

    template<class T>
    ostream& operator << (ostream& out, const Point<T>& p) {
        return out << p.x << ' ' << p.y;
    }

    PF toPF(P a) { return PF((ld)a.x, (ld)a.y); }

    template<class T>
    T dot(Point<T> a, Point<T> b) {
        return a.x * b.x + a.y * b.y;
    }

    template<class T>
    T cross(Point<T> a, Point<T> b) {
        return a.x * b.y - a.y * b.x;
    }

    // cross(a,b,c) = (b-a) × (c-a)
    template<class T>
    T cross(Point<T> a, Point<T> b, Point<T> c) {
        return cross(b - a, c - a);
    }

    i128 dot128(P a, P b) {
        return (i128)a.x * b.x + (i128)a.y * b.y;
    }

    i128 cross128(P a, P b) {
        return (i128)a.x * b.y - (i128)a.y * b.x;
    }

    i128 cross128(P a, P b, P c) {
        return cross128(b - a, c - a);
    }

    int sgn128(i128 x) {
        if (x > 0) return 1;
        if (x < 0) return -1;
        return 0;
    }

    template<class T>
    T len2(Point<T> a) {
        return dot(a, a);
    }

    i128 len2_128(P a) {
        return dot128(a, a);
    }

    template<class T>
    T dis2(Point<T> a, Point<T> b) {
        return len2(a - b);
    }

    i128 dis2_128(P a, P b) {
        return len2_128(a - b);
    }

    template<class T>
    ld len(Point<T> a) {
        return sqrtl((ld)len2(a));
    }

    template<class T>
    ld dis(Point<T> a, Point<T> b) {
        return len(a - b);
    }

    bool equal(PF a, PF b) {
        return eq(a.x, b.x) && eq(a.y, b.y);
    }

    // 两向量是否平行/共线
    bool parallel(P a, P b) { return cross128(a, b) == 0; }
    bool parallel(PF a, PF b) { return sgn(cross(a, b)) == 0; }

    // 逆时针/顺时针旋转 90 度
    template<class T>
    Point<T> rotate_ccw90(Point<T> a) { return {-a.y, a.x}; }

    template<class T>
    Point<T> rotate_cw90(Point<T> a) { return {a.y, -a.x}; }

    // 逆时针旋转 rad 弧度
    PF rotate(PF a, ld rad) {
        ld s = sinl(rad), c = cosl(rad);
        return {a.x * c - a.y * s, a.x * s + a.y * c};
    }

    // 单位向量。注意 a 不能是零向量
    PF unit(PF a) {
        return a / len(a);
    }

    // 单位法向量：把 a 逆时针转 90 度再单位化
    PF normal(PF a) {
        return unit(PF(-a.y, a.x));
    }

    // 把向量 a 截断/拉伸为长度 l
    PF trunc(PF a, ld l) {
        return unit(a) * l;
    }

    // a 到 b 的有向夹角，范围 (-pi, pi]
    // 返回正数：b 在 a 左侧；返回负数：b 在 a 右侧
    template<class T>
    ld angle_to(Point<T> a, Point<T> b) {
        return atan2l((ld)cross(a, b), (ld)dot(a, b));
    }

    // 极角排序：按 [0, 2pi) 排序，不需要 atan2，适合整数向量
    // 上半平面在前；同方向时短的在前
    int half(P a) {
        return (a.y > 0 || (a.y == 0 && a.x >= 0)) ? 0 : 1;
    }

    bool polar_cmp(P a, P b) {
        int ha = half(a), hb = half(b);
        if (ha != hb) return ha < hb;
        i128 cr = cross128(a, b);
        if (cr != 0) return cr > 0;
        return len2_128(a) < len2_128(b);
    }

    /* -------------------- 直线与线段 -------------------- */

    template<class T>
    struct Line {
        Point<T> a, b;
        Line() {}
        Line(Point<T> a, Point<T> b) : a(a), b(b) {}
        Point<T> vec() const { return b - a; }
    };

    using LineI = Line<ll>;
    using LineF = Line<ld>;

    PF point_on_line(LineF l, ld t) {
        return l.a + l.vec() * t;
    }

    // 点 p 是否在直线 l 左侧。若等于 0，则在直线上
    bool on_left(PF p, LineF l) {
        return sgn(cross(l.vec(), p - l.a)) > 0;
    }

    // 点 p 是否在直线 l 上
    bool on_line(P p, LineI l) {
        return cross128(l.a - p, l.b - p) == 0;
    }

    // 点 p 是否在线段 l 上，包含端点
    bool on_seg(P p, LineI l) {
        return cross128(l.a - p, l.b - p) == 0 && dot128(l.a - p, l.b - p) <= 0;
    }

    bool on_seg(PF p, LineF l) {
        return sgn(cross(l.a - p, l.b - p)) == 0 && sgn(dot(l.a - p, l.b - p)) <= 0;
    }

    // 点 p 是否在射线 o + t*d 上，t>=0，包含起点
    bool on_ray(P p, P o, P d) {
        P v = p - o;
        return cross128(d, v) == 0 && dot128(d, v) >= 0;
    }

    // 点到直线距离
    ld dis_to_line(PF p, LineF l) {
        return fabsl(cross(l.vec(), p - l.a)) / len(l.vec());
    }

    // 点到线段距离
    ld dis_to_seg(PF p, LineF l) {
        if (equal(l.a, l.b)) return dis(p, l.a);
        PF v = l.vec();
        if (sgn(dot(v, p - l.a)) <= 0) return dis(p, l.a);
        if (sgn(dot(v, p - l.b)) >= 0) return dis(p, l.b);
        return fabsl(cross(v, p - l.a)) / len(v);
    }

    // 判断点 p 到线段 l 的距离是否 <= r，全程整数，避免浮点误差
    bool within_range(P p, LineI l, ll r) {
        P v = l.vec();
        P pa = p - l.a;
        P pb = p - l.b;
        i128 rr = (i128)r * r;
        if (dot128(v, pa) <= 0) return len2_128(pa) <= rr;
        if (dot128(v, pb) >= 0) return len2_128(pb) <= rr;
        i128 cr = cross128(v, pa);
        return cr * cr <= len2_128(v) * rr;
    }

    // 点 p 在直线 l 上的投影点
    PF projection(PF p, LineF l) {
        PF v = l.vec();
        ld t = dot(v, p - l.a) / len2(v);
        return l.a + v * t;
    }

    // 点 p 关于直线 l 的对称点
    PF symmetry(PF p, LineF l) {
        PF q = projection(p, l);
        return p + (q - p) * 2;
    }

    // 直线与直线交点。若平行/重合，返回 false
    bool line_intersection(LineF x, LineF y, PF& res) {
        PF vx = x.vec(), vy = y.vec();
        ld d = cross(vx, vy);
        if (sgn(d) == 0) return false;
        ld t = cross(vy, x.a - y.a) / d;
        res = x.a + vx * t;
        return true;
    }

    bool box_intersect(LineI x, LineI y) {
        return max(min(x.a.x, x.b.x), min(y.a.x, y.b.x)) <= min(max(x.a.x, x.b.x), max(y.a.x, y.b.x)) &&
               max(min(x.a.y, x.b.y), min(y.a.y, y.b.y)) <= min(max(x.a.y, x.b.y), max(y.a.y, y.b.y));
    }

    // 判断两线段是否相交，包含端点和重合
    bool seg_intersect(LineI x, LineI y) {
        if (!box_intersect(x, y)) return false;
        i128 c1 = cross128(x.a, x.b, y.a);
        i128 c2 = cross128(x.a, x.b, y.b);
        i128 c3 = cross128(y.a, y.b, x.a);
        i128 c4 = cross128(y.a, y.b, x.b);
        return sgn128(c1) * sgn128(c2) <= 0 && sgn128(c3) * sgn128(c4) <= 0;
    }

    struct SegInterResult {
        int state; // 0 不相交；1 规范相交；2 端点相交；3 重合，交集是一条线段
        PF l, r;   // state=1/2 时 l=r=交点；state=3 时 [l,r] 是重合部分端点
    };

    // 线段交点分类，整数输入，浮点输出交点
    SegInterResult seg_intersection(LineI s1, LineI s2) {
        SegInterResult res{0, PF(), PF()};
        if (!box_intersect(s1, s2)) return res;

        i128 c1 = cross128(s1.a, s1.b, s2.a);
        i128 c2 = cross128(s1.a, s1.b, s2.b);
        i128 c3 = cross128(s2.a, s2.b, s1.a);
        i128 c4 = cross128(s2.a, s2.b, s1.b);

        if (c1 == 0 && c2 == 0) { // 共线，交集可能是点或线段
            vector<P> v;
            if (on_seg(s1.a, s2)) v.push_back(s1.a);
            if (on_seg(s1.b, s2)) v.push_back(s1.b);
            if (on_seg(s2.a, s1)) v.push_back(s2.a);
            if (on_seg(s2.b, s1)) v.push_back(s2.b);
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            if (v.empty()) return res;
            if (v.size() == 1) return {2, toPF(v[0]), toPF(v[0])};
            return {3, toPF(v.front()), toPF(v.back())};
        }

        if (sgn128(c1) * sgn128(c2) <= 0 && sgn128(c3) * sgn128(c4) <= 0) {
            PF p;
            line_intersection(LineF(toPF(s1.a), toPF(s1.b)), LineF(toPF(s2.a), toPF(s2.b)), p);
            int state = (c1 == 0 || c2 == 0 || c3 == 0 || c4 == 0) ? 2 : 1;
            return {state, p, p};
        }
        return res;
    }

    // 过点 p，作一条垂直于直线 l 的直线
    LineI perpendicular(P p, LineI l) {
        P v = l.vec();
        return LineI(p, p + rotate_ccw90(v));
    }

    /* -------------------- 三角形常用心 -------------------- */

    // 三角形外心：外接圆圆心。三点共线时返回 false
    bool circumcenter(PF a, PF b, PF c, PF& o) {
        ld a1 = b.x - a.x, b1 = b.y - a.y;
        ld a2 = c.x - a.x, b2 = c.y - a.y;
        ld c1 = a1 * a1 + b1 * b1;
        ld c2 = a2 * a2 + b2 * b2;
        ld d = 2 * (a1 * b2 - a2 * b1);
        if (sgn(d) == 0) return false;
        o = {a.x + (c1 * b2 - c2 * b1) / d,
             a.y + (a1 * c2 - a2 * c1) / d};
        return true;
    }

    // 三角形外接圆半径
    ld circumradius(PF a, PF b, PF c) {
        return dis(a, b) * dis(a, c) * dis(b, c) / (2 * fabsl(cross(b - a, c - a)));
    }

    // 三角形垂心：H = A + B + C - 2O，其中 O 是外心
    bool orthocenter(PF a, PF b, PF c, PF& h) {
        PF o;
        if (!circumcenter(a, b, c, o)) return false;
        h = a + b + c - o * 2;
        return true;
    }

    // 三角形内心：按对边长度加权平均
    PF incenter(PF a, PF b, PF c) {
        ld x = dis(b, c), y = dis(a, c), z = dis(a, b);
        ld s = x + y + z;
        return {(x * a.x + y * b.x + z * c.x) / s,
                (x * a.y + y * b.y + z * c.y) / s};
    }

    /* -------------------- 圆 -------------------- */

    struct Circle {
        PF o;
        ld r;
        Circle() : o(), r(0) {}
        Circle(PF o, ld r) : o(o), r(r) {}

        // 圆心角 rad 对应的圆上一点
        PF point(ld rad) const {
            return {o.x + r * cosl(rad), o.y + r * sinl(rad)};
        }
    };

    // 给定半径 r 和弦 AB，求圆心。
    // right=true：返回 AB 右侧的圆心；否则返回左侧。若不存在返回 false。
    bool circle_center_by_chord(PF a, PF b, ld r, PF& o, bool right = true) {
        ld d2 = dis2(a, b);
        if (d2 > 4 * r * r + EPS) return false;
        PF mid = (a + b) / 2;
        ld h = sqrtl(max((ld)0, r * r - d2 / 4));
        PF n = normal(b - a); // AB 左侧单位法向量
        o = right ? mid - n * h : mid + n * h;
        return true;
    }

    struct LineCircleResult {
        vector<PF> p; // 0/1/2 个交点
        ld t1, t2;    // 在线 l.a + t*(l.b-l.a) 上的参数；相切时 t1=t2
    };

    // 直线与圆交点。
    // 若拿它判断射线和圆：看 t2>=0；判断线段和圆：看 [t1,t2] 与 [0,1] 是否有交集。
    LineCircleResult line_circle_intersection(Circle c, LineF l) {
        LineCircleResult res{{}, 0, 0};
        PF v = l.vec();
        ld A = dot(v, v);
        ld B = 2 * dot(v, l.a - c.o);
        ld C = len2(l.a - c.o) - c.r * c.r;
        ld delta = B * B - 4 * A * C;
        if (delta < -EPS) return res;
        if (delta < EPS) {
            ld t = -B / (2 * A);
            res.t1 = res.t2 = t;
            res.p.push_back(point_on_line(l, t));
            return res;
        }
        delta = sqrtl(max((ld)0, delta));
        res.t1 = (-B - delta) / (2 * A);
        res.t2 = (-B + delta) / (2 * A);
        res.p.push_back(point_on_line(l, res.t1));
        res.p.push_back(point_on_line(l, res.t2));
        return res;
    }

    // 两圆交点。返回 0/1/2 个点。
    // 完全重合时无法用有限点表示，这里也返回空，需要按题意特判。
    vector<PF> circle_circle_intersection(Circle a, Circle b) {
        vector<PF> res;
        ld d = dis(a.o, b.o);
        if (sgn(d) == 0) return res;                    // 同心：重合或内含
        if (d > a.r + b.r + EPS) return res;             // 外离
        if (d < fabsl(a.r - b.r) - EPS) return res;      // 内含

        ld x = (d * d + a.r * a.r - b.r * b.r) / (2 * d);
        ld h2 = a.r * a.r - x * x;
        if (h2 < -EPS) return res;
        PF v = (b.o - a.o) / d;
        PF p = a.o + v * x;
        if (h2 < EPS) {
            res.push_back(p);
        } else {
            ld h = sqrtl(max((ld)0, h2));
            PF n = rotate_ccw90(v);
            res.push_back(p + n * h);
            res.push_back(p - n * h);
        }
        return res;
    }

    // 点 p 到圆 c 的切线，返回切点。p 在圆内则返回空；p 在圆上返回一个切点 p。
    vector<PF> tangent_points_from_point(Circle c, PF p) {
        vector<PF> res;
        PF op = p - c.o;
        ld d2 = len2(op);
        if (d2 < c.r * c.r - EPS) return res;
        if (eq(d2, c.r * c.r)) {
            res.push_back(p);
            return res;
        }
        ld d = sqrtl(d2);
        ld ang = atan2l(op.y, op.x);
        ld delta = acosl(c.r / d);
        res.push_back(c.point(ang + delta));
        res.push_back(c.point(ang - delta));
        return res;
    }

    // 最小圆覆盖，随机增量，期望 O(n)
    Circle minimum_enclosing_circle(vector<PF> p) {
        if (p.empty()) return Circle(PF(0, 0), 0);
        mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
        shuffle(p.begin(), p.end(), rng);

        Circle c(p[0], 0);
        auto inside = [&](PF x) {
            return dis2(x, c.o) <= c.r * c.r + EPS;
        };

        int n = p.size();
        for (int i = 0; i < n; i++) {
            if (inside(p[i])) continue;
            c = Circle(p[i], 0);
            for (int j = 0; j < i; j++) {
                if (inside(p[j])) continue;
                PF o = (p[i] + p[j]) / 2;
                c = Circle(o, dis(o, p[i]));
                for (int k = 0; k < j; k++) {
                    if (inside(p[k])) continue;
                    PF cc;
                    circumcenter(p[i], p[j], p[k], cc);
                    c = Circle(cc, dis(cc, p[i]));
                }
            }
        }
        return c;
    }

    // 固定半径 r 的圆最多覆盖多少个点，圆边界也算覆盖。O(n^2 log n)
    int max_covered_points(vector<P> p, ll r) {
        int n = p.size();
        if (n == 0) return 0;
        int ans = 1;
        struct Event {
            ld ang;
            int delta;
            bool operator < (const Event& e) const {
                if (!eq(ang, e.ang)) return ang < e.ang;
                return delta > e.delta; // 同角度先加入，保证边界点算覆盖
            }
        };
        for (int i = 0; i < n; i++) {
            vector<Event> ev;
            for (int j = 0; j < n; j++) if (i != j) {
                P v = p[j] - p[i];
                if (len2_128(v) > (i128)4 * r * r) continue;
                ld ang = atan2l((ld)v.y, (ld)v.x);
                if (ang < 0) ang += 2 * PI;
                ld delta = acosl(len(v) / (2.0L * r));
                ld L = ang - delta, R = ang + delta;
                if (L < 0) { // 区间跨过 0，需要拆成两段
                    ev.push_back({L + 2 * PI, 1});
                    ev.push_back({2 * PI, -1});
                    ev.push_back({0, 1});
                    ev.push_back({R, -1});
                } else if (R >= 2 * PI) { // 区间跨过 2pi，需要拆成两段
                    ev.push_back({L, 1});
                    ev.push_back({2 * PI, -1});
                    ev.push_back({0, 1});
                    ev.push_back({R - 2 * PI, -1});
                } else {
                    ev.push_back({L, 1});
                    ev.push_back({R, -1});
                }
            }
            sort(ev.begin(), ev.end());
            int cur = 1;
            ans = max(ans, cur);
            for (auto [ang, delta] : ev) {
                cur += delta;
                ans = max(ans, cur);
            }
        }
        return ans;
    }

    // 圆与坐标轴平行矩形是否有交集；矩形为 [x1,x2] × [y1,y2]
    bool circle_rectangle_overlap(ld r, ld ox, ld oy, ld x1, ld y1, ld x2, ld y2) {
        ld cx = (x1 + x2) / 2, cy = (y1 + y2) / 2;
        ld hx = (x2 - x1) / 2, hy = (y2 - y1) / 2;
        ld x = max((ld)0, fabsl(ox - cx) - hx);
        ld y = max((ld)0, fabsl(oy - cy) - hy);
        return x * x + y * y <= r * r + EPS;
    }

    /* -------------------- 多边形 -------------------- */

    // 多边形有向面积的 2 倍。点必须按顺/逆时针给出。
    // 返回正数表示逆时针，负数表示顺时针。
    i128 polygon_area2_signed(const vector<P>& p) {
        int n = p.size();
        i128 s = 0;
        for (int i = 0; i < n; i++) {
            s += cross128(p[i], p[(i + 1) % n]);
        }
        return s;
    }

    i128 polygon_area2_abs(const vector<P>& p) {
        i128 s = polygon_area2_signed(p);
        return s >= 0 ? s : -s;
    }

    ld polygon_area(const vector<PF>& p) {
        int n = p.size();
        ld s = 0;
        for (int i = 0; i < n; i++) s += cross(p[i], p[(i + 1) % n]);
        return fabsl(s) / 2;
    }

    // 格点多边形边界上的格点数 b = sum gcd(|dx|, |dy|)
    ll boundary_lattice_points(const vector<P>& p) {
        int n = p.size();
        ll b = 0;
        for (int i = 0; i < n; i++) {
            ll dx = llabs(p[(i + 1) % n].x - p[i].x);
            ll dy = llabs(p[(i + 1) % n].y - p[i].y);
            b += gcd(dx, dy);
        }
        return b;
    }

    // Pick 定理：A = i + b/2 - 1
    // 返回格点多边形内部格点数 i
    i128 interior_lattice_points(const vector<P>& p) {
        i128 area2 = polygon_area2_abs(p);
        ll b = boundary_lattice_points(p);
        return (area2 - b + 2) / 2;
    }

    // 点在任意多边形内判定，O(n)
    // 返回 0：外部；1：内部；2：边界上
    int point_in_polygon(const vector<P>& poly, P q) {
        bool in = false;
        int n = poly.size();
        for (int i = 0; i < n; i++) {
            P a = poly[i], b = poly[(i + 1) % n];
            if (on_seg(q, LineI(a, b))) return 2;

            // 水平射线法：判断边 ab 是否穿过 q 向右的射线
            int y1 = (a.y <= q.y && q.y < b.y);
            int y2 = (b.y <= q.y && q.y < a.y);
            i128 cr = cross128(a, b, q);
            if ((y1 && cr > 0) || (y2 && cr < 0)) in = !in;
        }
        return in ? 1 : 0;
    }

    // Andrew 凸包。返回逆时针凸包，不重复首点。
    // strict=true：边上的共线中间点会被删掉；strict=false：保留边界共线点。
    vector<P> convex_hull(vector<P> p, bool strict = true) {
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
        int n = p.size();
        if (n <= 1) return p;

        vector<P> h;
        auto bad = [&](P a, P b, P c) {
            i128 cr = cross128(a, b, c);
            return strict ? cr <= 0 : cr < 0;
        };

        for (int i = 0; i < n; i++) {
            while (h.size() >= 2 && bad(h[h.size() - 2], h.back(), p[i])) h.pop_back();
            h.push_back(p[i]);
        }
        int lower = h.size();
        for (int i = n - 2; i >= 0; i--) {
            while ((int)h.size() > lower && bad(h[h.size() - 2], h.back(), p[i])) h.pop_back();
            h.push_back(p[i]);
        }
        h.pop_back();
        return h;
    }

    // 点是否在凸多边形内，O(log n)。
    // 要求 poly 是严格凸包，逆时针，不重复首点。返回 true 包含边界。
    bool point_in_convex(const vector<P>& poly, P q) {
        int n = poly.size();
        if (n == 1) return q == poly[0];
        if (n == 2) return on_seg(q, LineI(poly[0], poly[1]));

        P p0 = poly[0];
        if (cross128(p0, poly[1], q) < 0) return false;
        if (cross128(p0, poly[n - 1], q) > 0) return false;

        int l = 1, r = n - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (cross128(p0, poly[m], q) >= 0) l = m;
            else r = m;
        }
        return cross128(poly[l], poly[(l + 1) % n], q) >= 0;
    }

    // 凸多边形直径平方，旋转卡壳 O(n)。要求 p 是逆时针凸包。
    i128 convex_diameter2(const vector<P>& p) {
        int n = p.size();
        if (n <= 1) return 0;
        if (n == 2) return dis2_128(p[0], p[1]);
        i128 ans = 0;
        int j = 1;
        for (int i = 0; i < n; i++) {
            int ni = (i + 1) % n;
            P edge = p[ni] - p[i];
            while (true) {
                int nj = (j + 1) % n;
                i128 a = cross128(edge, p[nj] - p[i]);
                i128 b = cross128(edge, p[j] - p[i]);
                if (a < 0) a = -a;
                if (b < 0) b = -b;
                if (a > b) j = nj;
                else break;
            }
            ans = max(ans, dis2_128(p[i], p[j]));
            ans = max(ans, dis2_128(p[ni], p[j]));
        }
        return ans;
    }

    // 平面最近点对距离平方，O(n log n)。若有重点，返回 0。
    i128 closest_pair2(vector<P> p) {
        sort(p.begin(), p.end());
        for (int i = 1; i < (int)p.size(); i++) {
            if (p[i] == p[i - 1]) return 0;
        }
        int n = p.size();
        if (n <= 1) return INF128;
        vector<P> tmp(n);

        function<i128(int, int)> dfs = [&](int l, int r) -> i128 {
            if (r - l <= 3) {
                i128 d = INF128;
                for (int i = l; i < r; i++) {
                    for (int j = i + 1; j < r; j++) d = min(d, dis2_128(p[i], p[j]));
                }
                sort(p.begin() + l, p.begin() + r, [](P a, P b) {
                    if (a.y != b.y) return a.y < b.y;
                    return a.x < b.x;
                });
                return d;
            }

            int m = (l + r) / 2;
            ll midx = p[m].x;
            i128 d = min(dfs(l, m), dfs(m, r));

            merge(p.begin() + l, p.begin() + m, p.begin() + m, p.begin() + r, tmp.begin(), [](P a, P b) {
                if (a.y != b.y) return a.y < b.y;
                return a.x < b.x;
            });
            copy(tmp.begin(), tmp.begin() + (r - l), p.begin() + l);

            vector<P> strip;
            for (int i = l; i < r; i++) {
                i128 dx = (i128)p[i].x - midx;
                if (dx * dx >= d) continue;
                for (int j = (int)strip.size() - 1; j >= 0; j--) {
                    i128 dy = (i128)p[i].y - strip[j].y;
                    if (dy * dy >= d) break;
                    d = min(d, dis2_128(p[i], strip[j]));
                }
                strip.push_back(p[i]);
            }
            return d;
        };

        return dfs(0, n);
    }

    /* -------------------- 曼哈顿距离常用变换 -------------------- */

    // 顺时针旋转 45 度并放大 sqrt(2) 倍：
    // (x,y) -> (x+y, y-x)
    // |x1-x2|+|y1-y2| = max(|dx'|, |dy'|)
    P rotate45(P p) {
        return {p.x + p.y, p.y - p.x};
    }

    // 点集最大曼哈顿距离
    ll max_manhattan(vector<P> p) {
        ll mn1 = LLONG_MAX, mx1 = LLONG_MIN;
        ll mn2 = LLONG_MAX, mx2 = LLONG_MIN;
        for (auto [x, y] : p) {
            mn1 = min(mn1, x + y);
            mx1 = max(mx1, x + y);
            mn2 = min(mn2, x - y);
            mx2 = max(mx2, x - y);
        }
        return max(mx1 - mn1, mx2 - mn2);
    }

    // d 维曼哈顿最大距离：max over masks of max(sum +/- a_i)-min(sum +/- a_i)
    ll max_manhattan_nd(const vector<vector<ll>>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int d = a[0].size();
        ll ans = 0;
        for (int mask = 0; mask < (1 << d); mask++) {
            ll mn = LLONG_MAX, mx = LLONG_MIN;
            for (int i = 0; i < n; i++) {
                ll s = 0;
                for (int j = 0; j < d; j++) {
                    if (mask >> j & 1) s += a[i][j];
                    else s -= a[i][j];
                }
                mn = min(mn, s);
                mx = max(mx, s);
            }
            ans = max(ans, mx - mn);
        }
        return ans;
    }
}

/*
void solve() {
    using namespace geom;

    // 示例：判断两线段是否相交
    P a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (seg_intersect(LineI(a, b), LineI(c, d)) ? "YES" : "NO") << '\n';
}
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve();
    return 0;
}
