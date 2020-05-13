#pragma once

#include <iostream>
#include<iomanip>
#include<string>
#include<vector>

#include "MeshIOBase.h"

using namespace std;

class Gmsh2IO:public MeshIOBase{
public:
    Gmsh2IO();

    virtual void ReadMesh() override;
    virtual void PrintMesh() const override;


};