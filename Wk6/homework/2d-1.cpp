#include <iostream>
#include <cmath>
using namespace std;
double f(double x, double y){
    return 10*y*(1-y);
}
double compute_0(double h,double x, double y){
    return h*f(x,y);
}
double compute_1(double h,double x, double y){
    return h*f(x+h/2,y + compute_0(h,x,y)/2);
}
double compute_2(double h,double x, double y){
    return h*f(x+h/2,y + compute_1(h,x,y)/2);
}
double compute_3(double h,double x, double y){
    return h*f(x+h,y + compute_2(h,x,y));
}
double RK_4(double h,double x, double y){
    double correction6 = compute_0(h,x,y) + 2*compute_1(h,x,y) + 2*compute_2(h,x,y) + compute_3(h,x,y);
    double correction = correction6/6;
    return (y+correction);
}
int main(){
    pair<double, double> values = {0,0.1};
    double h = 0.001;
    int iterations = 40;
    int count = 0;
    cout << "Iteration " << count << ": " << "(" << values.first << "," << values.second << ")\n";
    for (; count<iterations;){
        values.first += h;
        values.second = RK_4(h,values.first,values.second);
        count++;
        cout << "Iteration " << count << ": " << "(" << values.first << "," << values.second << ")\n";
        
    }
}