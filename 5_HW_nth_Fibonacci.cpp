#include<bits/stdc++.h>
using namespace std;

int nthFibonacci(int n){
    int a=0, b=1, temp;
    if(n==1){return 0;}
    if(n==2){return 1;};
    for(int i=3; i<=n; i++){
        temp = a;
        a=b;
        b=a+temp;
    }
    return b;
}

int main(){
    int n;
    cin >> n;
    cout << nthFibonacci(n) << endl;


    return 0;
}