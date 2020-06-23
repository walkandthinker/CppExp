#pragma once

#include <iostream>
#include <iomanip>
#include <string>


using namespace std;


class MethodBase{
public:
    // MethodBase()=delete;

    virtual void SetValues()=0;
    virtual void PrintValues()=0;
};