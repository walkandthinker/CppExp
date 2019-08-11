#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Array2D
{
public:
    Array2D(const int &n,const double &val):_N(n),_N2(n*n){
        _vals=new double[n*n];
        assert(_vals==nullptr);
        for(size_t i=1;i<n*n;++i){
            _vals[i]=val;
        }
    }
    ~Array2D() {delete[] _vals;}

    inline void Rand(){
        for(int i=0;i<_N2;++i) _vals[i]=1.0*rand()/RAND_MAX;
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
    //***************************************
    // operator overload
    //***************************************
    // =
    inline Array2D& operator=(const double &val){
        if(_N2<8000){
            for(int i=0;i<_N2;++i) _vals[i]=val;
        }
        else{
            #pragma omp for schedule(static)
            for(int i=0;i<_N2;++i) {
                _vals[i]=val;
            }
        }
        ;return *this;
    }
    inline Array2D& operator=(const Array2D &vec){
        for(int i=0;i<_N2;++i) _vals[i]=vec._vals[i];
        return *this;
    }
private:
    double *_vals;
    const int _N,_N2;
};

#endif // ARRAY2D_H