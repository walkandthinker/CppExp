#pragma once


class MeshBase{

public:
    int _nNodes,_nNodesPerElmt,_nNodesPerBCElmt;
    int _nElmts,_nBulkElmts,_nBCElmts;

public:
    virtual void CreateMesh()=0;
    virtual void PrintMesh()const=0;

public:
    virtual int GetNodesNum()const=0;
    virtual int GetNodesNumPerElmt()const=0;
    virtual int GetNodesNumPerBCElmt()const=0;

    virtual int GetElmtsNum()const=0;
    virtual int GetBulkElmtsNum()const=0;
    virtual int GetBCElmtsNum()const=0;
};