#include "MeshInterface.h"

MeshInterface::MeshInterface(){
    _nNodes=0;_nNodesPerElmt=0;_nNodesPerBCElmt=0;
    _nElmts=0;_nBulkElmts=0;_nBCElmts=0;
    _NodeCoords.clear();
    _ElmtConn.clear();
}

void MeshInterface::PrintMesh()const{
    cout<<"*** information for connectivity:"<<endl;
    for(int e=0;e<static_cast<int>(_ElmtConn.size());e++){
        cout<<"***\t"<<e+1<<":";
        for(int j=0;j<_ElmtConn[e][0];j++) cout<<_ElmtConn[e][1+j]<<" ";
        cout<<endl;
    }
    cout<<"*** information for node coordinates:"<<endl;
    for(int i=1;i<=GetNodesNum();i++){
        cout<<"***\t"<<i<<"-th node:";
        cout<<GetIthNodeJthCoord(i,1)<<", "
            <<GetIthNodeJthCoord(i,2)<<", "
            <<GetIthNodeJthCoord(i,3)<<endl;
    }
}