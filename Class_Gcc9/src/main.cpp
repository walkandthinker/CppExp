#include <iostream>
#include "Vec.h"

using namespace std;

int main(){
    Vec vec1,vec2(2),vec3;

    cout<<vec1;
    vec1+=1;
    cout<<vec1;
    cout<<"vec2:"<<vec2;
    vec3=vec1+vec2;
    cout<<"vec3:"<<vec3<<endl;
    return 0;
}