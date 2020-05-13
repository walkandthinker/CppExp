#pragma once

#include "AbaqusIO.h"
#include "Gmsh2IO.h"


class Mesh:public AbaqusIO,public Gmsh2IO{
public:
    Mesh(int mode=0);

    virtual void ReadMesh() override;
    virtual void PrintMesh() const override;

    string GetMeshFileName()const{
        return AbaqusIO::_MeshFileName+"<--->"+Gmsh2IO::_MeshFileName;
    }

private:
    int _MeshMode;
};