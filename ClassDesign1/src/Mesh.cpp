#include "Mesh.h"

Mesh::Mesh(int mode){
    _MeshMode=mode;
}

void Mesh::ReadMesh(){
    if(_MeshMode==0){
        AbaqusIO::ReadMesh();
    }
    else if(_MeshMode==1){
        Gmsh2IO::ReadMesh();
    }
}

void Mesh::PrintMesh() const{
    if(_MeshMode==0){
        AbaqusIO::PrintMesh();
    }
    else if(_MeshMode==1){
        Gmsh2IO::PrintMesh();
    }
}