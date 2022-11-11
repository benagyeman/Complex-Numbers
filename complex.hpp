#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include<iostream>


class ComplexNumber
{

    private:
    double mRealPart;
    double mImaginaryPart;

    public:

    ComplexNumber(); // A constructor, overriding the default one

    ComplexNumber( double x, double y); // A constructor that assigns values to the real and imaginary parts

    double CalculateModulus() const;
    double CalculateArgument() const;

    ComplexNumber CalculatePower( double n) const;

    // Implement some operator overloading 

    ComplexNumber& operator= (const ComplexNumber& z); // Overload the assignment operator
    ComplexNumber operator- () const; // Overload the unary (-) operator

    ComplexNumber operator+ (const ComplexNumber& z) const; //Overload the binary (+) operator
    ComplexNumber operator- (const ComplexNumber& z) const; //Overload the binary (-) operator

    friend std::ostream& operator<< (std::ostream& output, const ComplexNumber& z); //Overload the << operator


};

#endif