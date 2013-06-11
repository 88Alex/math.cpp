#ifndef MATH_CPP
#define MATH_CPP 1
#define MATH_CPP_VERSION 1.0
#endif

#ifndef QUATERNION_HPP
#define QUATERNION_HPP 1

class Quaternion
{
    public: double r, i, j, k;
    Quaternion(r_, i_, j_, k_)
    {
        r = r_; i = i_; j = j_; k = k_;
    }
    static const Quaternion ZERO = Quaternion(0, 0, 0, 0);
    Quaternion operator+(const Quaternion* other)
    {
        Quaternion result;
        result.r = r + other.r;
        result.i = i + other.i;
        result.j = j + other.j;
        result.k = k + other.k;
        return result;
    }
    Quaternion operator-(const Quaternion* other)
    {
        Quaternion result;
        result.r = r - other.r;
        result.i = i - other.i;
        result.j = j - other.j;
        result.k = k - other.k;
        return result;
    }
    Quaternion operator*(const Quaternion* other)
    {
        Quaternion result;
        double a1 = r, a2 = other.r, b1 = i, b2 = other.i;
        double c1 = j, c2 = other.j, d1 = k, d2 = other.k;
        result.r = ( a1*a2 ) - ( b1*b2 ) - ( c1*c2 ) - ( d1*d2 );
        result.i = ( a1*b2 ) + ( b1*a2 ) + ( c1*d2 ) - ( d1*d2 );
        result.j = ( a1*c2 ) - ( b1*d2 ) + ( c1*a2 ) + ( d1*b2 );
        result.k = ( a1*d2 ) + ( b1*a2 ) - ( c1*b2 ) + ( d1*c2 );
        return result;
    }
}

global operator-(const Quaternion* param)
{
    return Quaternion.ZERO - param;
}
