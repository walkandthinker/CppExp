#pragma once


#include <iostream>
#include <vector>
#include <cmath>

#include "MeshBase.h"

using namespace std;

class MeshBulk:public MeshBase{
public:
    MeshBulk();

    void CreateMesh() override;
    void PrintMesh()const override;
    void SetNx(const int &nx){_Nx=nx;}
    void SetNy(const int &ny){_Ny=ny;}

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
    void Create1DLagrangeMesh();
    void Create2DLagrangeMesh();

private:
    int _Nx=0,_Ny=0;
    vector<double> _NodeCoords;
    vector<vector<int>> _ElmtConn;
};