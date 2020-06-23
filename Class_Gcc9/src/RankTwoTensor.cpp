//****************************************************************
//* This file is part of the AsFem framework
//* A Simple Finite Element Method program (AsFem)
//* All rights reserved, Yang Bai @ CopyRight 2020
//* https://github.com/yangbai90/AsFem.git
//* Licensed under GNU GPLv3, please see LICENSE for details
//* https://www.gnu.org/licenses/gpl-3.0.en.html
//****************************************************************

#include "RankTwoTensor.h"


//***************************************
//*** the constructors for different usage!!!
//***************************************
RankTwoTensor::RankTwoTensor()
:_N(3),_N2(3*3){
    for(int i=0;i<_N2;++i){
        _vals[i]=0.0;
    }
}
RankTwoTensor::RankTwoTensor(const double &val)
:_N(3),_N2(3*3){
    for(int i=0;i<_N2;++i){
        _vals[i]=val;
    }
}
RankTwoTensor::RankTwoTensor(const RankTwoTensor &a)
:_N(3),_N2(3*3){
    for(int i=0;i<_N2;++i){
        _vals[i]=a._vals[i];
    }
}
//***
RankTwoTensor::RankTwoTensor(const InitMethod &method)
:_N(3),_N2(3*3){
    switch(method){
        case InitMethod::InitZero:
            SetToZeros();
            break;
        case InitMethod::InitIdentity:
            SetToIdentity();
            break;
        default:
            printf("*** Error: unsupported rank-2 tensor fill method                !!!   ***\n");
            abort();
            break;
    }
}
//****(from voigt notation)
RankTwoTensor::RankTwoTensor(const double &v11,const double &v22,const double &v12)
:_N(3),_N2(3*3){
    (*this)(1,1)=v11;(*this)(1,2)=v12;(*this)(1,3)=0.0;
    (*this)(2,1)=v12;(*this)(2,2)=v22;(*this)(2,3)=0.0;
    (*this)(3,1)=0.0;(*this)(3,2)=0.0;(*this)(3,3)=0.0;
}
RankTwoTensor::RankTwoTensor(const double &v11,const double &v22,const double &v33,
                             const double &v23,const double &v31,const double &v12)
:_N(3),_N2(3*3){
    (*this)(1,1)=v11;(*this)(1,2)=v12;(*this)(1,3)=v31;
    (*this)(2,1)=v12;(*this)(2,2)=v22;(*this)(2,3)=v23;
    (*this)(3,1)=v31;(*this)(3,2)=v23;(*this)(3,3)=v33;
}
RankTwoTensor::RankTwoTensor(const double &v11,const double &v12,
                             const double &v21,const double &v22)
:_N(3),_N2(3*3){
    // for 2d voigt
    (*this)(1,1)=v11;(*this)(1,2)=v12;(*this)(1,3)=0.0;
    (*this)(2,1)=v21;(*this)(2,2)=v22;(*this)(2,3)=0.0;
    (*this)(3,1)=0.0;(*this)(3,2)=0.0;(*this)(3,3)=0.0;
}
RankTwoTensor::RankTwoTensor(const double &v11,const double &v12,const double &v13,
                  const double &v21,const double &v22,const double &v23,
                  const double &v31,const double &v32,const double &v33)
:_N(3),_N2(3*3){
    // for 3d voigt
    (*this)(1,1)=v11;(*this)(1,2)=v12;(*this)(1,3)=v13;
    (*this)(2,1)=v21;(*this)(2,2)=v22;(*this)(2,3)=v23;
    (*this)(3,1)=v31;(*this)(3,2)=v32;(*this)(3,3)=v33;
}
//********************************************************
//set tensor from voigt notation
//*****
void RankTwoTensor::SetFromVoigt(const double &v11,const double &v22,const double &v12){
    (*this)(1,1)=v11;(*this)(1,2)=v12;(*this)(1,3)=0.0;
    (*this)(2,1)=v12;(*this)(2,2)=v22;(*this)(2,3)=0.0;
    (*this)(3,1)=0.0;(*this)(3,2)=0.0;(*this)(3,3)=0.0;
}
void RankTwoTensor::SetFromVoigt(const double &v11,const double &v22,const double &v33,
                                 const double &v23,const double &v31,const double &v12){
    (*this)(1,1)=v11;(*this)(1,2)=v12;(*this)(1,3)=v31;
    (*this)(2,1)=v12;(*this)(2,2)=v22;(*this)(2,3)=v23;
    (*this)(3,1)=v31;(*this)(3,2)=v23;(*this)(3,3)=v33;
}
void RankTwoTensor::SetFromEulerAngle(const double &theta1,const double &theta2,const double &theta3){
    // set a rotation tensor from Euler-angle
    const double PI=3.14159265359;
    double x1=cos(theta1*PI/180.0);
    double x2=cos(theta2*PI/180.0);
    double x3=cos(theta3*PI/180.0);
    double y1=sin(theta1*PI/180.0);
    double y2=sin(theta2*PI/180.0);
    double y3=sin(theta3*PI/180.0);

    (*this)(1,1)= x1*x3-x2*y1*y3;
    (*this)(1,2)= x3*y1+x1*x2*y3;
    (*this)(1,3)= y2*y3;

    (*this)(2,1)=-x1*y3-x2*x3*y1;
    (*this)(2,2)= x1*x2*x3-y1*y3;
    (*this)(2,3)= x3*y2;

    (*this)(3,1)= y1*y2;
    (*this)(3,2)=-x1*y2;
    (*this)(3,3)= x2;
}
//****** for left hand scale times rank-2 tensor
RankTwoTensor operator*(const double &lhs,const RankTwoTensor &a){
    RankTwoTensor temp(0.0);
    for(int i=0;i<a._N2;++i) temp._vals[i]=lhs*a._vals[i];
    return temp;
}
