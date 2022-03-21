#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Complex {
private:
    float realPart_ = 0.0;
    float imaginaryPart_ = 0.0;
public:
    Complex(const float &realP, const float &imaginaryP) {
        realPart_ = realP;
        imaginaryPart_ = imaginaryP;
    }

    Complex(float realP) {
        realPart_ = realP;
    }

    void setRealNumber(const float &realP)
    {
        realPart_= realP;
    }
    void set_im(const float &imaginaryP)
    {
        imaginaryPart_= imaginaryP;
    }
    float getRealNumber()
    {
        return realPart_;
    }
    float getImaginaryNumber()
    {
        return imaginaryPart_;
    }
    void print()
    {
        if (realPart_ != 0)
            cout << realPart_;
        if (imaginaryPart_ != 0)
        {
            if (imaginaryPart_ > 0)
                cout << "+" << imaginaryPart_ << endl;
            else
                cout << imaginaryPart_ << "i" << endl;
        }
    }
    Complex add(const Complex &complexx)
    {
        return {realPart_ + complexx.realPart_, imaginaryPart_+complexx.imaginaryPart_};
    }
};

int main()
{
    Complex a(1.0, -2.0); // creates 1-2i
    Complex b(3.14); // creates 3.14

    b.set_im(-5);

    Complex c = a.add(b);

    c.print(); // prints 4.14-7i
    return 0;
}
