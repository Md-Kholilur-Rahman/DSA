#include<bits/stdc++.h>
using namespace std;

int bin_to_dec(int n){
    int ans = 0, power = 1;
    while(n){
        int rem  = n % 10;    //reminder by base2
        n /= 10;
        ans += rem * power;
        power *= 2;         //multiply by base1
    }
    return ans;
}

int main(){
    int bin;
    cout << "Enter a binary number: "; 
    cin >> bin;
    cout << "Decimal: " << bin_to_dec(bin) << endl;
    
    return 0;
}