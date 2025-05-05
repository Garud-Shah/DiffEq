#include <iostream>
#include <cmath>
using namespace std;
using fp128 = long double;
fp128 fn(fp128 x, fp128 y){

    return ;
}
fp128 f(fp128 x, fp128 y){
    return fn(x,y);
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
    pair<fp128, fp128> values = {0,0.1};
    cout << "You are running an RK-4 based solver for differential equations.";
    string str = "XX";
    while(str[0] != '1'){
        cout << "Please input your INITIAL VALUE for x:";
        long double x; cin >> x;
        cout << "Please confirm your value for x by inputting 1. If not, input 0.";
        cin >> str;
        if(str[0]=='0'){
            for(int i=0; i<1'000'000'000;)
            cout << "\x1B[2J\x1B[H"
        }
    }
    
    fp128 h = 0.35;
    int iterations = 60;
    int count = 0;
    cout << "Iteration " << count << ": " << "(" << values.first << "," << values.second << ")\n";
    for (; count<iterations;){
        values.first += h;
        values.second = RK_4(h,values.first,values.second);
        count++;
        cout << "Iteration " << count << ": " << "(" << values.first << "," << values.second << ")\n";        
    }
}