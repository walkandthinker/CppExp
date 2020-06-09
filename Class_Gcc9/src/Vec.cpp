#include "Vec.h"


Vec::Vec(){
    _vals[0]=0.0;_vals[1]=0.0;_vals[2]=0.0;
}

Vec::Vec(double val){
    _vals[0]=val;_vals[1]=val;_vals[2]=val;
}

ostream& operator<<(ostream& os, const Vec& a){
    os<<a(1)<<" ,"<<a(2)<<", "<<a(3)<<endl;
    return os;
}