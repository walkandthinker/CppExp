#include "MeshInterface.h"

void MeshInterface::CreateMesh(){
    int P=2;
    _nNodesPerElmt=P+1;
    _nNodesPerBCElmt=1;
    _nBCElmts=2;
    _nElmts=_nBulkElmts+_nBCElmts;
    _nNodes=_nBulkElmts*P+1;
    double dx=1.0;

    _ElmtConn.resize(_nElmts,vector<int>(0));
    _NodeCoords.resize(_nNodes*4,0.0);
    for(int i=0;i<_nNodes;i++){
        _NodeCoords[i*4+0]=1.0;
        _NodeCoords[i*4+1]=i*dx;
        _NodeCoords[i*4+2]=0.0;
        _NodeCoords[i*4+3]=0.0;
    }

    _ElmtConn[0].push_back(1);
    _ElmtConn[0].push_back(1);
    _ElmtConn[1].push_back(1);
    _ElmtConn[1].push_back(_nNodes);

    for(int e=0;e<_nBulkElmts;e++){
        _ElmtConn[2+e].clear();
        _ElmtConn[2+e].push_back(_nNodesPerElmt);
        for(int j=1;j<=_nNodesPerElmt;j++){
            _ElmtConn[2+e].push_back(e*P+j);
        }
    }
}