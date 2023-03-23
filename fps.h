
template<typename T, std::vector<T> (*Convolution)(std::vector<T>, std::vector<T>)>
class Fps : public std::vector<T> {
public:
    bool ntt_friendly_ = true;

    Fps &operator+=(const Fps &f) {
        if (f.size() > this->size()) {
            this->resize(f.size());
        }
        for (int i = 0; i < (int) f.size(); ++i) {
            (*this)[i] += f[i];
        }
        return *this;
    }

    Fps &operator+=(const T &c) {
        (*this)[0] += c;
        return *this;
    }

    Fps &operator-=(const Fps &f) {
        if (f.size() > this->size()) {
            this->resize(f.size());
        }
        for (int i = 0; i < (int) f.size(); ++i) {
            (*this)[i] -= f[i];
        }
        return *this;
    }

    Fps &operator-=(const T &c) {
        (*this)[0] -= c;
        return *this;
    }

    Fps &operator*=(const Fps &f) {
        (*this) = Convolution(*this, f);
        return *this;
    }

    Fps &operator*=(const T &c) {
        for (int i = 0; i < (int) this->size(); ++i) {
            (*this)[i] *= c;
        }
        return *this;
    }

    // multiply by x^d
    Fps &operator<<=(const long long d) {
        this->insert(this->begin(), d, T(0));
        return *this;
    }

    // cut the terms a_0x^0 to a_{d-1}x^{d-1}
    Fps &operator>>=(const long long d) {
        this->erase(this->begin(), this->begin() + d);
        return *this;
    }

    Fps operator+(const Fps &f) const {
        return Fps(*this) += f;
    }

    Fps operator+(const T &c) const {
        return Fps(*this) += c;
    }

    Fps operator-(const Fps &f) const {
        return Fps(*this) -= f;
    }

    Fps operator-(const T &c) const {
        return Fps(*this) -= c;
    }

    Fps operator*(const Fps &f) const {
        return Fps(*this) *= f;
    }

    Fps operator*(const T &c) const {
        return Fps(*this) *= c;
    }

    Fps operator<<(const long long d) const {
        return Fps(*this) <<= d;
    }

    Fps operator>>(const long long d) const {
        return Fps(*this) >>= d;
    }

    Fps operator-() const {
        Fps res(this->size);
        for (int i = 0; i < (int) this->size(); ++i) {
            res[i] = -(*this)[i];
        }
        return res;
    }

    Fps Integral() const {
        const int n = (int) this->size();
        Fps res(n + 1);
        res[0] = T(0);
        for (int i = 0; i < n; ++i) {
            res[i + 1] = (*this)[i] / T(i + 1);
        }
        return res;
    }

    Fps Derivative() const {
        const int n = (int) this->size();
        Fps res(std::max(0, n - 1));
        for (int i = 1; i < n; ++i) {
            res[i - 1] = (*this)[i] * T(i);
        }
        return res;
    }

    Fps Inverse() const {
        int n = (int) this->size();

    }


};