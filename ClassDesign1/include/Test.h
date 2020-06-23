#include "MyMethod.h"
#include "MyPara.h"


class Test:public MyPara,public MethodBase{
public:
    Test(){
        _A=0.0;_B=0.0;_C=1.0;
    }

    virtual void SetValues() override{
        _A=1.0;_B=2.0;_C=3.0;_D=4.0;
    }
    virtual void PrintValues() override{
        cout<<"A="<<_A<<", B="<<_B<<", C="<<_C<<", D="<<_D<<endl;
    }

private:
    int _D;
};