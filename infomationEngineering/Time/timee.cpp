#include "timee.h"
#include <iomanip>
#include <iostream>
using namespace std;
Timee::Timee(const int &hour, const int &minutes , const int &seconds) {
    if(hour >= 0) hour_ = hour;
    else cout<<"Wrong Input!"<<endl;
    if(minutes >= 0) minutes_= minutes;
    else cout<<"Wrong Input!"<<endl;
    if(seconds >= 0) seconds_=seconds;
    else cout<<"Wrong Input!"<<endl;
}
Timee::Timee(const int &seconds) {
    if(seconds >= 0) {
        hour_ = seconds / 3600 ;
        minutes_ = (seconds - (hour_ * 3600)) / 60 ;
        seconds_= seconds - (hour_ * 3600) -(minutes_ * 60);
    }
    else cout<<"Wrong Input!"<<endl;
}
Timee::Timee(){}
void Timee:: setTimee(int &hour,int &minutes, int &seconds) {
    hour_=hour;
    minutes_=minutes;
    seconds_=seconds;
}
Timee Timee:: getTimee() {
    return {hour_ , minutes_, seconds_};
}
double Timee:: getSeconds() {
    return (hour_ * 3600) + minutes_ * 60 + seconds_; //converting into seconds
}
Timee Timee::operator-(const Timee &rhs) const {
    int New_seconds, New_minutes, New_hour = 0;
    if (rhs.hour_ < hour_) {
        New_hour = (hour_ * 3600 + minutes_ * 60 + seconds_) - (rhs.hour_ * 3600 + rhs.minutes_ * 60 + rhs.seconds_);
    }
    else {
        cout << "wrong input!";
    }
    if (rhs.minutes_ < minutes_) {
        New_minutes =  (minutes_ * 60 + seconds_) - (rhs.minutes_ * 60 + rhs.seconds_);
    }
    else {
        New_minutes = New_hour;
    }
    if (rhs.seconds_ < seconds_) {
        New_seconds = seconds_ - rhs.seconds_;
    }
    else {
        New_seconds = (60 + seconds_) - rhs.seconds_;
    }
    return Timee(New_hour/3600 ,New_minutes/60 , New_seconds );
}
Timee Timee::operator+(const Timee &rhs) const {
    return Timee(hour_ + rhs.hour_ ,minutes_ + rhs.minutes_ , seconds_ + rhs.seconds_ );
}
Timee Timee::operator*(const Timee &rhs) const {
    return Timee(hour_ * rhs.hour_ ,minutes_ * rhs.minutes_ , seconds_ * rhs.seconds_ );
}
ostream &operator<<(ostream &str, Timee &rhs){
    str << setw(2) << setfill('0') << rhs.hour_ << "h:"
        << setw(2) << setfill('0') << rhs.minutes_ << "m:"
        << setw(2) << setfill('0') << rhs.seconds_ << "s\n";
    return str;
}
istream &operator>>(istream &str, Timee &rhs){
    str >> rhs.hour_;
    str >> rhs.minutes_;
    str >> rhs.seconds_;
    return str;
}
