#pragma once


#include <iostream>
#include <string>
#include <vector>


using namespace std;

class MeshIOBase{
public:
    // MeshIOBase()=delete;
    virtual void ReadMesh()=0;
    virtual void PrintMesh()const=0;

protected:
    string _MeshFileName;
    vector<double> _NodeCoords;
    vector<vector<int>> _ElmtConn;
    int _nNodes,_nElmts;
    int _nNodesPerElmt;
};