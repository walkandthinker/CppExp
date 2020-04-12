#pragma once

#include "MeshBulk.h"
#include "MeshInterface.h"


class Mesh:public MeshBulk,public MeshInterface{
public:
    Mesh(){}
};