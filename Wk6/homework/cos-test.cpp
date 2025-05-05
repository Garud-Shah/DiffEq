#include <iostream>
#include <cmath>
using namespace std;
// using fp128 = long double;
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
int main(){
    // fp128 k; cin>>k;
    int k; cin >> k;
    cout << cos(M_PI);
}