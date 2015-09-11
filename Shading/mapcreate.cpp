#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
using namespace std;
float dis(float x)
{
    //x/=20;
    float mu=0;
    float pi=2;
    return 20/(pi*sqrt(6.28))*exp(-pow((x-mu),2)/(2*pi*pi));
}
void mapcreate()
{
    ofstream cout("map.txt");
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            cout<<j-10<<" "<<round(100*dis(abs(i-10))*dis(abs(j-10)))/100<<" "<<i-10<<endl;
            //cout<<j-10<<" "<<(rand()%300)/100.0<<" "<<i-10<<endl;
        }
    }
}
