// Matrix
// Verify : 
//
#include <bits/stdc++.h>


/* Matrix */
// Operators
// +(SquareMatrix), -(SquareMatrix), *(SquareMatrix), *(T), *(std::vector<T>)
// +=(SquareMatrix), -=(SquareMatrix), *=(SquareMatrix), *=(T)
// [](std::size_t), [][](std::size_t)
// os<<
//
// Methods
// pow(i32) -> SquareMatrix, size() -> std::size_t
//
template <class T> class SquareMatrix {
    using Vec = std::vector<T>;
    using VecVec = std::vector<Vec>;
  public:
    constexpr SquareMatrix(std::size_t n) noexcept : mat(VecVec(n, Vec(n))) {}
    constexpr SquareMatrix(std::size_t n, T init) noexcept : mat(VecVec(n, Vec(n, init))) {}

    friend std::ostream &operator<<(std::ostream& os, const SquareMatrix& m) {
        std::size_t i = 0;
        for (const auto& v : m.mat) {
            os << (i++ == 0 ? "[[" : " [");
            std::size_t j = 0;
            for (const auto& n : v) os << n << (++j == v.size() ? ']' : ' ');
            os << (i == m.mat.size() ? "]\n" : "\n");
        }
        return os;
    }

    auto& operator[](std::size_t idx) & { return mat[idx]; }
    const auto& operator[](std::size_t idx) const& { return mat[idx]; }
    auto operator[](std::size_t idx) const&& noexcept { return std::move(mat[idx]); }

    constexpr SquareMatrix operator+(const SquareMatrix m) const { return SquareMatrix(*this) += m; }
    constexpr SquareMatrix operator-(const SquareMatrix m) const { return SquareMatrix(*this) -= m; }
    constexpr SquareMatrix operator*(const SquareMatrix m) const { return SquareMatrix(*this) *= m; }
    constexpr SquareMatrix operator*(const T c) const noexcept { return SquareMatrix(*this) *= c; }
    constexpr SquareMatrix& operator+=(const SquareMatrix m) {
        assert(size() == m.size());
        for (std::size_t i = 0; i < size(); ++i) {
            for (std::size_t j = 0; j < size(); ++j) {
                mat[i][j] += m.mat[i][j];
            }
        }
        return *this;
    }
    constexpr SquareMatrix& operator-=(const SquareMatrix m) {
        assert(size() == m.size());
        for (std::size_t i = 0; i < size(); ++i) {
            for (std::size_t j = 0; j < size(); ++j) {
                mat[i][j] -= m.mat[i][j];
            }
        }
        return *this;
    }
    constexpr SquareMatrix& operator*=(const SquareMatrix m) {
        assert(size() == m.size());
        VecVec ret(size(), Vec(size()));
        for (std::size_t i = 0; i < size(); ++i) {
            for (std::size_t j = 0; j < size(); ++j) {
                for (std::size_t k = 0; k < size(); ++k) {
                    ret[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        mat = std::move(ret);
        return *this;
    }
    constexpr SquareMatrix& operator*=(const T c) noexcept {
        for (std::size_t i = 0; i < size(); ++i) {
            for (std::size_t j = 0; j < size(); ++j) {
                mat[i][j] *= c;
            }
        }
        return *this;
    }

    constexpr Vec operator*(const Vec v) const {
        assert(size() == v.size());
        Vec ret(size());
        for (std::size_t i = 0; i < size(); ++i) {
            for (std::size_t j = 0; j < size(); ++j) {
                ret[i] += mat[i][j] * v[j];
            }
        }
        return ret;
    }

    constexpr SquareMatrix pow(std::int_fast32_t n) noexcept {
        SquareMatrix ret = SquareMatrix::make_id(size());
        SquareMatrix a(*this);
        while (n > 0) {
            if (n & 1) ret *= a;
            a = a * a, n >>= 1;
        }
        return ret;
    }

    std::size_t size() const noexcept { return mat.size(); }

    constexpr static SquareMatrix make_id(std::size_t n) noexcept {
        SquareMatrix mt(n);
        for (std::size_t i = 0; i < n; ++i) {
            mt[i][i] = 1;
        }
        return mt;
    }
  private:
    VecVec mat;
};
using MI = SquareMatrix<std::int_fast32_t>;
