#pragma once

#include <iostream>
#include <vector>
#include <cmath>

#include "MeshBase.h"

using namespace std;

class MeshInterface:public MeshBase{
public:
    MeshInterface();
    void CreateMesh() override;
    void PrintMesh()const override;
    void SetElmtsNum(const int &ne){_nElmts=ne;}

    //************************************************
    //*** get basic information
    //*************************************************
    int GetNodesNum()const override{return _nNodes;}
    int GetNodesNumPerElmt()const override{return _nNodesPerElmt;}
    int GetNodesNumPerBCElmt()const override{return _nNodesPerBCElmt;}

    int GetElmtsNum()const override{return _nElmts;}
    int GetBulkElmtsNum()const override{return _nBulkElmts;}
    int GetBCElmtsNum()const override{return _nBCElmts;}

    double GetIthNodeJthCoord(const int &i,const int &j)const{
        return _NodeCoords[(i-1)*4+j];
    }
private:
    vector<double> _NodeCoords;
    vector<vector<int>> _ElmtConn;
};