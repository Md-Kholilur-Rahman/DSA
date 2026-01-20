#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}

int ncr(int n, int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}

// int fact(int n){
//     int ans = 1;
//     for(int i=1; i<=n; i++){
//         ans = ans*i;
//     }
//     return ans;
// }
// int ncr2(int n, int r){
//     return fact(n)/(fact(r)*fact(n-r));
// }


int main(){
    int n, r;
    cout << "Enter n and r:" << endl;
    cin >> n >> r;
    cout << ncr(n, r) << endl;

    return 0;
}