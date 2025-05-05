#include <iostream>
#include <cmath>
using namespace std;
using fp128 = long double;
// int factorial(int number){
//     int running = 1; for(int i=1; i<=number; i++){running *= i;}
//     return running;
// }
// fp128 exp(fp128 number, int power){
//     int running = 1; for(int i=1; i<=number; i++){running *= power;}
//     return running;
// }
// fp128 cos(fp128 number){
//     int N=11;
//     fp128 running = 0;
//     for(int i=0; i<N; i++){
//         if (i%2 == 1){
//             running -= exp(number,2*i)/factorial(2*i);
//         } else {
//             running += exp(number,2*i)/factorial(2*i);
//         }
//     }
//     return running;
// }
fp128 f(fp128 x, fp128 y){
    // return y;
    return (1+x*sin(x*y));
    // return (x+y+4)*(x+y+4);
}

fp128 euler_corr(fp128 h,fp128 x, fp128 y){
    return h*f(x,y);
}
fp128 euler(fp128 h,fp128 x, fp128 y){
    return y+euler_corr(h,x,y);
}
fp128 improved_euler_corr(fp128 h,fp128 x, fp128 y){
    return h*(f(x,y)+f(x+h,euler(h,x,y)))*1/2;
}
int main(){
    freopen("out","w",stdout);
    pair<fp128, fp128> values = {0,0};
    fp128 h = 0.05;
    int iterations = 24;
    int count = 0;
    cout << "Running Improved Euler" << endl;
    // cout << "Iteration " << count << ": " << "(" << values.first << ",";
    cout << values.second;
    cout << ")";
    cout << "\n";
    for (;count<iterations;){
        values.second += improved_euler_corr(h,values.first,values.second);
        values.first += h;
        count++;
        // cout << "Iteration " << count << ": " << "(" << values.first << ",";
        cout << values.second;
        // cout << ")";
        cout << "\n";
    }
}