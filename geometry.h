namespace geometry {
    using scalar = long long;
    constexpr scalar EPS = 0;

    int Sign(const scalar a) {
        if (a < -EPS) return -1;
        if (a > EPS) return 1;
        return 0;
    }

    bool IsEqual(const scalar a, const scalar b) {
        return Sign(a - b) == 0;
    }

    struct Point {
        scalar x, y;

        Point() = default;

        Point(scalar _x, scalar _y) {
            x = _x, y = _y;
        }

        Point operator-() const {
            return {-x, -y};
        }

        Point operator+(const Point &b) const {
            return {x + b.x, y + b.y};
        }

        Point operator-(const Point &b) const {
            return {x - b.x, y - b.y};
        }

        Point operator*(const scalar &b) const {
            return {x * b, y * b};
        }

        Point operator/(const scalar &b) const {
            assert(!IsEqual(b, 0));
            return {x / b, y / b};
        }

        Point operator+=(const Point &b) {
            x += b.x;
            y += b.y;
            return *this;
        }

        Point operator-=(const Point &b) {
            x -= b.x;
            y -= b.y;
            return *this;
        }

        Point operator*=(const scalar b) {
            x *= b;
            y *= b;
            return *this;
        }

        Point operator/=(const scalar b) {
            assert(!IsEqual(b, 0.0));
            x /= b;
            y /= b;
            return *this;
        }

        bool operator==(const Point &b) const {
            return IsEqual(b.x, x) && IsEqual(b.y, y);
        }

        scalar Norm() const {
            return sqrt(x * x + y * y);
        }

        scalar SquaredNorm() const {
            return x * x + y * y;
        }

        scalar DotProduct(const Point &b) const {
            return x * b.x + y * b.y;
        }

        scalar CrossProduct(const Point &b) const {
            return x * b.y - y * b.x;
        }

        scalar Arg() const {
            return std::atan2(y, x);
        }

        Point Rotate(double theta) const {
            return {(scalar) (x * cos(theta) - y * sin(theta)), (scalar) (x * sin(theta) + y * cos(theta))};
        }
    };

    inline Point operator*(scalar a, const Point &b) {
        return {b.x * a, b.y * a};
    }

    inline bool operator<(const Point &a, const Point &b) {
        if (Sign(a.x - b.x) != 0) return Sign(a.x - b.x) < 0;
        else return Sign(a.y - b.y) < 0;
    }

    void SortByArgument(std::vector<Point> &v) {
        sort(v.begin(), v.end(), [&](Point a, Point b) { return a.Arg() < b.Arg(); });
    }

    Point Rotate(Point a, double theta) {
        return a.Rotate(theta);
    }

    scalar Distance(const Point &a, const Point &b) {
        return (a - b).Norm();
    }

    std::istream &operator>>(std::istream &is, Point &a) {
        scalar x, y;
        is >> x >> y;
        a = Point(x, y);
        return is;
    }

    std::ostream &operator<<(std::ostream &os, const Point &a) {
        os << "(" << a.x << ". " << a.y << ")";
        return os;
    }
}
using namespace geometry;