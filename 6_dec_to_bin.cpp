#include<bits/stdc++.h>
using namespace std;

int pow_f(int base, int power){
    int ans =1; 
    for(int i=1; i<=power; i++){
        ans*=base;
    }
    return ans;
}


int decimal_to_binary(int n){
    int ans = 0, power = 0;
    while(n){
        ans=ans+((n%2)*pow_f(10, power));
        n/= 2;
        power++;
    }
    return ans;
}

int dec_to_bin(int n){
    int ans = 0, power = 1, rem;
    while(n){
        rem = n % 2;
        ans += rem * power;
        n /= 2;
        power *= 10;
    }
    return ans;
}
int main(){
    int dec;
    cout << "Enter the decimal value: ;";
    cin >> dec;

    cout << "Binary value: " << decimal_to_binary(dec) << endl;
    cout << "Binary value: " << dec_to_bin(dec) << endl;

    return 0;
}