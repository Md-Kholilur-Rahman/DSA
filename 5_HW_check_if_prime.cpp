#include<bits/stdc++.h>
using namespace std;

bool is_prime(int x){
    if(x==1){return false;}
    for(int i=2; i*i<=x; i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    if(is_prime(n)){
        cout << "prime" << endl;
    }
    else{
        cout << "Not Prime" << endl;
    }

    return 0;
}
