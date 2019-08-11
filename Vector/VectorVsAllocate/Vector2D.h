#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>


using namespace std;

class Vector2D
{
public:
    Vector2D(const int &n,const double &val):_N(n),_N2(n*n){
        _vals.reserve(n*n);
        for(size_t i=0;i<n*n;++i) _vals.push_back(val);
        srand(time(0));
    }
    ~Vector2D(){_vals.clear();}

    inline void Rand(){
        for(auto &it:_vals) it=1.0*rand()/RAND_MAX;
    }

    inline void Print() const {
        for(int i=1;i<=_N;++i){
            for(int j=1;j<=_N;++j){
                cout<<(*this)(i,j)<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    inline double  operator()(const int &i,const int &j) const {return _vals[(i-1)*_N+j-1];}
    inline double& operator()(const int &i,const int &j) {return _vals[(i-1)*_N+j-1];}

    // constexpr double  operator()(const int &i,const int &j) const {return _vals[(i-1)*_N+j-1];}
    // constexpr double& operator()(const int &i,const int &j) {return _vals[(i-1)*_N+j-1];}
    //***************************************
    // operator overload
    //***************************************
    // =
    inline Vector2D& operator=(const double &val){
        fill(_vals.begin(),_vals.end(),val);return *this;
    }
    inline Vector2D& operator=(const Vector2D &vec){
        _vals=vec._vals;return *this;
    }
    // +

private:
    vector<double> _vals;
    const int _N,_N2;
};


#endif // VECTOR2D_H