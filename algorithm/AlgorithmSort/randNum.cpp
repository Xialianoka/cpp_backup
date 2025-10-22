
#include<iostream>
// #include<cstdlib>
#include<ctime>
#include<random>
 
using namespace std;
 
int main(){
    default_random_engine e;
    uniform_real_distribution<double> u(0.0,1.0);  //左闭右闭区间
    e.seed(time(0));
    
    for(int i=0;i<10;i++){
        cout<<(int)((u(e))*100)<<endl;
    }
 
    system("pause");
    return 0;
}