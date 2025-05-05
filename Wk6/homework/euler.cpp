#include <iostream>
#include <cmath>
using namespace std;
using fp128 = long double;
fp128 f(fp128 x, fp128 y){
    return y;
}
fp128 compute_0(fp128 h,fp128 x, fp128 y){
    return h*f(x,y);
}
fp128 euler(fp128 h,fp128 x, fp128 y){
    return (y+compute_0(h,x,y));
}
int main(){
    pair<fp128, fp128> values = {0,1};
    fp128 h = 1;
    int iterations = 3;
    int count = 0;
    cout << "Iteration " << count << ": " << "(" << values.first << "," << values.second << ")\n";
    for (; count<iterations;){
        values.first += h;
        values.second = euler(h,values.first,values.second);
        count++;
        cout << "Iteration " << count << ": " << "(" << values.first << "," << values.second << ")\n";
        
    }
}