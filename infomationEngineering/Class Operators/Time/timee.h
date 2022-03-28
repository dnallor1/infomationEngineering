#pragma once
#include <iomanip>
#include <iostream>
class Timee{
private:
    int hour_;
    int minutes_;
    int seconds_;
public:
    Timee(const int &hour, const int &minutes, const int &seconds);
    Timee(const int &seconds);
    Timee();
    Timee getTimee();
    double getSeconds();
    void setTimee(int &hour,int &minutes, int &seconds);
    Timee operator-(const Timee &rhs) const;
    Timee operator+(const Timee &rhs) const;
    Timee operator*(const Timee &rhs) const;
    void printT() const;
    friend std::ostream &operator<<(std::ostream &str, Timee &rhs);
    friend std::istream &operator>>(std::istream &str, Timee &rhs);
};
