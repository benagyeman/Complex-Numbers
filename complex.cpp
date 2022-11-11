#include<iostream>
#include<cmath>
#include "complex.hpp"
using namespace std;
ComplexNumber::ComplexNumber()
{
    mRealPart = 0.0;
    mImaginaryPart = 0.0;
}

ComplexNumber::ComplexNumber(double x, double y)
{
    mRealPart = x;
    mImaginaryPart = y;
}

double ComplexNumber::CalculateModulus() const 
{
    return sqrt(mRealPart*mRealPart + mImaginaryPart*mImaginaryPart);
}

double ComplexNumber::CalculateArgument() const
{
    return atan2(mImaginaryPart, mRealPart);
}

ComplexNumber ComplexNumber::CalculatePower(double n) const 
{
    double _mod = CalculateModulus();
    double _arg = CalculateArgument();
    double _mod_new = pow(_mod, n);
    double _arg_new = _arg * n;
    double realPart_new = _mod_new*cos(_arg_new);
    double imaginaryPart_new = _mod_new*sin(_arg_new);
    ComplexNumber z(realPart_new, imaginaryPart_new);
    return z;
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
    return *this; // This refers to the pointer of the complex number being returned
}

// Overloading the unary (-) operator

ComplexNumber ComplexNumber::operator-() const 
{
    ComplexNumber w;
    w.mRealPart = -mRealPart;
    w.mImaginaryPart = -mImaginaryPart;
    return w;
}

// Overload the binary (+) operator
ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const 
{
    ComplexNumber w;
    w.mRealPart = mRealPart + z.mRealPart;
    w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
    return w;
}

//Overload the binary (-) operator
ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const 
{
    ComplexNumber w;
    w.mRealPart = mRealPart + z.mRealPart;
    w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
    return w;
}

// Overload the insertion << operator
std::ostream& operator<<(std::ostream& output, const ComplexNumber& z)
{
    output << "(" << z.mRealPart << " ";
    if (z.mImaginaryPart>=0)
    {
        output <<"+"<< z.mImaginaryPart<< "i)";
    }
    else 
    {
        output <<"-"<< -z.mImaginaryPart<< "i)";
    }
    return output;
}