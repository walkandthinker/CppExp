#include <iostream>
#include <chrono>
#include <cmath>

#include "Vector2D.h"
#include "Array2D.h"

using namespace std;

int main(int args,char *argv[])
{
    int nStep=10;
    int N=5000;
    int i,j,step;

    for(int i=0;i<args;++i)
    {
        if(string(argv[i]).find("-n")!=string::npos)
        {
            if(i+1<args) N=atoi(argv[i+1]);
            if(N<1) N=1;
        }
        else if(string(argv[i]).find("-step")!=string::npos)
        {
            if(i+1<args) nStep=atoi(argv[i+1]);
            if(nStep<1) nStep=1;
        }
    }

    Vector2D vecA(N,0.0);
    Array2D  arrA(N,0.0);
    cout<<"Matrix size= "<<N<<", steps= "<<nStep<<endl;
    cout<<"Star to execute vector's code ..."<<endl;
    auto vecstart=chrono::high_resolution_clock::now();
    for(step=0;step<nStep;++step){
        //vecA=0.0;
        for(i=1;i<=N;++i){
            for(j=1;j<=N;++j){
                vecA(i,j)=sqrt(i*i+j*j);
            }
        }
    }
    cout<<"Vec(1,1)="<<vecA(1,1)<<", Vec(end,end)="<<vecA(N,N)<<endl;
    auto vecend=chrono::high_resolution_clock::now();
    double durationVec=chrono::duration_cast<chrono::microseconds>(vecend-vecstart).count()/1.0e6;
    cout<<"Finish vector's code !"<<endl;
    cout<<"Total time="<<durationVec<<" [s], average time="<<durationVec/nStep<<" [s]"<<endl<<endl;

    cout<<"Start to execut array's code ..."<<endl;
    auto arrstart=chrono::high_resolution_clock::now();
    for(step=0;step<nStep;++step){
        //arrA=0.0;
        for(i=1;i<=N;++i){
            for(j=1;j<=N;++j){
                arrA(i,j)=sqrt(i*i+j*j);
            }
        }
    }
    cout<<"Arr(1,1)="<<arrA(1,1)<<", arrA(end,end)="<<arrA(N,N)<<endl;
    auto arrend=chrono::high_resolution_clock::now();
    double durationArr=chrono::duration_cast<chrono::microseconds>(arrend-arrstart).count()/1.0e6;
    cout<<"Finish array's code !"<<endl;
    cout<<"Total time="<<durationArr<<" [s], average time="<<durationArr/nStep<<" [s]"<<endl<<endl;

    return 0;
}