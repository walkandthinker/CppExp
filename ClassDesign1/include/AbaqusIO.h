#pragma once

#include <iostream>
#include<iomanip>
#include<string>
#include<vector>

#include "MeshIOBase.h"

using namespace std;

class AbaqusIO:public MeshIOBase{
public:
    AbaqusIO();

    virtual void ReadMesh() override;
    virtual void PrintMesh() const override;


};