#pragma once

#include "MethodBase.h"

class MyMethod:public MethodBase{
public:
    MyMethod()=delete;
    virtual void SetValues() override{
        cout<<"Set values in MyMethod class"<<endl;
    }
    virtual void PrintValues() override{
        cout<<"Print values in MyMethod class"<<endl;
    }
};