/****************************************************************************
 * Copyright 2013 Evan Drumwright
 * This library is distributed under the terms of the GNU Lesser General Public 
 * License (found in COPYING).
 ****************************************************************************/

#ifndef ORIGIN2
#error This class is not to be included by the user directly. Use Origin2d.h or Origin2f.h instead.
#endif

class POINT2;

/// A two-dimensional floating point vector used for computational geometry calculations
class ORIGIN2
{
  public:
    ORIGIN2() {}
    ORIGIN2(REAL x, REAL y);
    ORIGIN2(const REAL* array);
    ORIGIN2(const POINT2& p);
    REAL norm_inf() const { return std::max(std::fabs(_data[0]), std::fabs(_data[1])); }
    REAL norm() const { return std::sqrt(norm_sq()); }
    REAL norm_sq() const { return sqr(_data[0]) + sqr(_data[1]); }
    static REAL norm(const ORIGIN2& v) { return std::sqrt(norm_sq(v)); }
    static REAL norm_sq(const ORIGIN2& v) { return v.norm_sq(); }
    void set_zero() { _data[0] = _data[1] = 0.0; }
    static ORIGIN2 zero() { return ORIGIN2(0.0, 0.0); }
    ORIGIN2& operator=(const POINT2& p);
    ORIGIN2& operator=(const ORIGIN2& v) { _data[0] = v[0]; _data[1] = v[1]; return *this; }
    ORIGIN2 operator+(const ORIGIN2& v) const { return ORIGIN2(_data[0] + v[0], _data[1] + v[1]); }
    POINT2 operator+(const POINT2& p) const;
    POINT2 operator-(const POINT2& p) const;
    ORIGIN2 operator-(const ORIGIN2& v) const { return ORIGIN2(_data[0] - v[0], _data[1] - v[1]); }
    ORIGIN2& operator+=(const ORIGIN2& v) { _data[0] += v[0]; _data[1] += v[1];  return *this; }
    ORIGIN2& operator-=(const ORIGIN2& v) { _data[0] -= v[0]; _data[1] -= v[1];  return *this; }
    ORIGIN2& operator*=(REAL scalar) { _data[0] *= scalar; _data[1] *= scalar; return *this; }
    ORIGIN2& operator/=(REAL scalar) { _data[0] /= scalar; _data[1] /= scalar; return *this; }
    ORIGIN2 operator*(REAL scalar) const { ORIGIN2 v = *this; v *= scalar; return v; }
    ORIGIN2 operator/(REAL scalar) const { ORIGIN2 v = *this; v /= scalar; return v; }
    ORIGIN2 operator-() const { return ORIGIN2(-_data[0], -_data[1]); }
    REAL* data() { return _data; }
    const REAL* data() const { return _data; }
    REAL& operator[](const unsigned i);
    const REAL& operator[](const unsigned i) const;
    REAL* data(unsigned i);
    const REAL* data(unsigned i) const;
    REAL x() const { return _data[0]; }
    REAL y() const { return _data[1]; }
    REAL& x() { return _data[0]; }
    REAL& y() { return _data[1]; }

  private:
    REAL _data[2];
    static REAL sqr(REAL x) { return x*x; }
}; // end class

inline ORIGIN2 operator*(REAL scalar, const ORIGIN2& v) { return v * scalar; }

/// Writes a ORIGIN2 to the specified stream
inline std::ostream& operator<<(std::ostream& out, const ORIGIN2& v)
{
  out << '[' << v[0] << ',' << ' ' << v[1] << ']' << ' ';
  return out;
};

