#pragma once


#include <iomanip>
#include <cmath>


using namespace std;


class Vec{
public:
    Vec();
    Vec(double val);

    //**************************************
    //*** for operator overload
    //**************************************
    Vec& operator=(const Vec &a)=default;
    Vec& operator=(const double &val){
        _vals[0]=val;_vals[1]=val;_vals[2]=val;
        return *this;
    }


    inline double& operator()(const int &i){
        return _vals[i-1];
    }
    inline double operator()(const int &i)const{
        return _vals[i-1];
    }

    //*******************************************
    //*** for +
    inline Vec operator+(const Vec &a)const{
        Vec temp;
        temp._vals[0]=_vals[0]+a._vals[0];
        temp._vals[1]=_vals[1]+a._vals[1];
        temp._vals[2]=_vals[2]+a._vals[2];
        return temp;
    }
    //*******************************************
    //*** for +=
    inline Vec& operator+=(const Vec &a){
        _vals[0]=_vals[0]+a._vals[0];
        _vals[1]=_vals[1]+a._vals[1];
        _vals[2]=_vals[2]+a._vals[2];
        return *this;
    }
    //*******************************************
    //*** for +=
    inline Vec& operator+=(const double &a){
        _vals[0]=_vals[0]+a;
        _vals[1]=_vals[1]+a;
        _vals[2]=_vals[2]+a;
        return *this;
    }

    //******************************************************
    //*******************************************
    //*** for -
    inline Vec operator-(const Vec &a)const{
        Vec temp;
        temp._vals[0]=_vals[0]-a._vals[0];
        temp._vals[1]=_vals[1]-a._vals[1];
        temp._vals[2]=_vals[2]-a._vals[2];
        return temp;
    }
    //*******************************************
    //*** for -=
    inline Vec& operator-=(const Vec &a){
        _vals[0]=_vals[0]-a._vals[0];
        _vals[1]=_vals[1]-a._vals[1];
        _vals[2]=_vals[2]-a._vals[2];
        return *this;
    }
    //*******************************************
    //*** for -=
    inline Vec& operator-=(const double &a){
        _vals[0]=_vals[0]-a;
        _vals[1]=_vals[1]-a;
        _vals[2]=_vals[2]-a;
        return *this;
    }


    //******************************************************
    //*** for *
    inline double operator*(const Vec &a)const{
        return _vals[0]*a._vals[0]+_vals[1]*a._vals[1]+_vals[2]*a._vals[2];
    }
    //*******************************************
    //*** for *
    inline Vec operator*(const double &a){
        Vec temp;
        temp._vals[0]=_vals[0]*a;
        temp._vals[1]=_vals[1]*a;
        temp._vals[2]=_vals[2]*a;
        return temp;
    }
    //*******************************************
    //*** for *=
    inline Vec& operator*=(const double &a){
        _vals[0]=_vals[0]*a;
        _vals[1]=_vals[1]*a;
        _vals[2]=_vals[2]*a;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Vec& a);

private:
    double _vals[3];
};