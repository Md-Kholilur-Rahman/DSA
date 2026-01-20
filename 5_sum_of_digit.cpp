#include<bits/stdc++.h>
using namespace std;

int sum_of_digit(int n){
    int sum = 0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main(){
    int number;
    cin >> number;
    cout << "Sum of digit:" << sum_of_digit(number) << endl;
    return 0;
}