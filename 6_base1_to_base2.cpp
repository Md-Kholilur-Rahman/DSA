#include<bits/stdc++.h>
using namespace std;

int decimal_to_anybase(int n, int base){
    int sum  = 0, power = 1; 
    while(n){
        int rem = n % base;
        sum += rem * power;

        n /= base;
        power *= 10;
    }
    return sum;
}

int anybase_to_decimal(int n, int base){
    int sum = 0, power = 1; 
    while(n){
        int rem = n%10;
        sum += (rem * power);

        n /= 10;
        power *= base;
    }
    return sum;
}

int base1_to_base2(int n, int base1, int base2){
    return decimal_to_anybase(anybase_to_decimal(n, base1), base2);
}

int main(){
    int number, base1, base2;
    cout << "Enter number, base1, base2: "; 
    
    cout << base1_to_base2(23, 5, 7);

    return 0;
}