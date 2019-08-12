#include <iostream>
#include <chrono>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

#include "omp.h"



using namespace std;

int main(int args,char *argv[])
{
    int nStep=10;
    int N=50000;
    int i,j,step;

    int nProcessors = omp_get_max_threads();

    cout<<"OMP threads="<<nProcessors<<endl;

    chrono::high_resolution_clock::time_point initstart,initend;
    chrono::high_resolution_clock::time_point arrstart,arrend;
    chrono::high_resolution_clock::time_point arrompstart,arrompend;
    chrono::high_resolution_clock::time_point vecstart,vecend;
    chrono::high_resolution_clock::time_point foreachstart,foreachend;
    double arrtime,arromptime,vectime,foreachtime;

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

    cout<<"Matrix size= "<<N<<", steps= "<<nStep<<endl;


    double *arrA=new double[N];assert(arrA==nullptr);
    double *arrB=new double[N];assert(arrB==nullptr);
    vector<double> vecA,vecB;
    vecA.reserve(N);
    vecB.reserve(N);

    cout<<"Start to init allocated array..."<<endl;
    initstart=chrono::high_resolution_clock::now();
    for(size_t i=0;i<N;++i)
    {
        arrA[i]=0.0;arrB[i]=0.0;
    }
    initend=chrono::high_resolution_clock::now();
    cout<<"Allocated array initialized! "<<endl;
    cout<<"Start to init vector array..."<<endl;
    initstart=chrono::high_resolution_clock::now();
    for(size_t i=0;i<N;++i)
    {
        vecA.push_back(0.0);
        vecB.push_back(0.0);
    }
    initend=chrono::high_resolution_clock::now();
    cout<<"Vector array initialized! "<<endl;
    cout<<"Time elpased:"<<chrono::duration_cast<chrono::microseconds>(initend-initstart).count()/1.0e6<<endl;


    cout<<"Star to execute loops for array and vector ..."<<endl;
    arrtime=0.0;arromptime=0.0;
    vectime=0.0;foreachtime=0.0;
    for(step=0;step<nStep;++step){
        cout<<"Step="<<step+1<<", time elapse====> "; 
        // for allocated array loop
        arrstart=chrono::high_resolution_clock::now();
        for(size_t i=0;i<N;++i){
            arrA[i]=sin(i);
        }
        arrend=chrono::high_resolution_clock::now();
        arrtime+=chrono::duration_cast<chrono::microseconds>(arrend-arrstart).count()/1.0e6;
        cout<<"array= "<<chrono::duration_cast<chrono::microseconds>(arrend-arrstart).count()/1.0e6<<" [s],";
        // omp array time
        arrompstart=chrono::high_resolution_clock::now();
        #pragma omp parallel
        {
            #pragma omp for
            for(size_t i=0;i<N;++i){
                arrB[i]=sin(i);
            }
        }
        arrompend=chrono::high_resolution_clock::now();
        arromptime+=chrono::duration_cast<chrono::microseconds>(arrompend-arrompstart).count()/1.0e6;
        cout<<"array omp= "<<chrono::duration_cast<chrono::microseconds>(arrompend-arrompstart).count()/1.0e6<<" [s],";

        vecstart=chrono::high_resolution_clock::now();
        for(auto it=vecA.begin();it!=vecA.end();++it){
            *it=sin(distance(vecA.begin(),it));
        }
        vecend=chrono::high_resolution_clock::now();
        vectime+=chrono::duration_cast<chrono::microseconds>(vecend-vecstart).count()/1.0e6;
        cout<<"vector iterator= "<<chrono::duration_cast<chrono::microseconds>(vecend-vecstart).count()/1.0e6<<" [s],";

        foreachstart=chrono::high_resolution_clock::now();
        // int i=0;
        // for_each(vecB.begin(),vecB.end(),[&it](double &value){
        //     it=sin(i);i++;
        // });
        
        cout<<endl<<"\t";
        cout<<"arrA="<<arrA[N-1]<<", arrB="<<arrB[N-1]<<", vecA="<<vecA[N-1]<<endl;
        // foreachend=chrono::chrono::high_resolution_clock::now();
        cout<<endl<<endl;
    }
    cout<<"Final time:"<<endl;
    cout<<"           Array A     ="<<arrtime/nStep<<" [s]"<<endl;
    cout<<"           Array B(OMP)="<<arromptime/nStep<<" [s]"<<endl;
    cout<<"           Vec   A     ="<<vectime/nStep<<" [s]"<<endl;
    
    return 0;
}