#include <iostream>
#include <cmath>
using namespace std;
using fp128 = long double;
fp128 f(fp128 x, fp128 y){
    fp128 k = 2.7;
    return (k/(x*x*x*x)-y*y);
}
fp128 compute_0(fp128 h,fp128 x, fp128 y){
    return h*f(x,y);
}
fp128 compute_1(fp128 h,fp128 x, fp128 y){
    return h*f(x+h/2,y + compute_0(h,x,y)/2);
}
fp128 compute_2(fp128 h,fp128 x, fp128 y){
    return h*f(x+h/2,y + compute_1(h,x,y)/2);
}
fp128 compute_3(fp128 h,fp128 x, fp128 y){
    return h*f(x+h,y + compute_2(h,x,y));
}
fp128 RK_4(fp128 h,fp128 x, fp128 y){
    fp128 correction6 = compute_0(h,x,y) + 2*compute_1(h,x,y) + 2*compute_2(h,x,y) + compute_3(h,x,y);
    fp128 correction = correction6/6;
    return (y+correction);
}
int main(){
    pair<fp128, fp128> values = {0.6,-1};
    fp128 h = 0.01;
    int iterations = 100;
    int count = 0;
    cout << "Iteration " << count << ": " << "(" << values.first << "," << values.second << ")\n";
    for (; count<iterations;){
        values.second = RK_4(h,values.first,values.second);
        values.first += h;
        count++;
        cout << "Iteration " << count << ": " << "(" << values.first << "," << values.second << ")\n";
        
    }
}