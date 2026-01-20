#include<bits/stdc++.h>
using namespace std;


/*
prints:
    -max_subarray_sum
    -starting and ending index of the sub array
*/
void max_sub_array_sum(vector<int> v){
    int prev_sm = 0, ans = 0; // if empty subarray int't allowed
                         // sm = ans = v[0];
                         // sm = sum upto v[i-1]
    int start = 0, end = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i] > v[i] + prev_sm){
            start = i;
            end = i;
            prev_sm = v[i];
        }
        else{
            prev_sm = v[i] + prev_sm;
        }
        if(prev_sm>ans){
            end = i;
            ans = prev_sm;
        }
    }
    cout << "Max subarray sum : " << ans << endl;
    cout << "Starting index: " << start  <<"    " << "Ending index: " << end << endl;
    cout << "SubArray: ";
    for(int i = start; i <= end; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

void f(vector<int> v){
    int sm = 0, ans =0;
    for(int i=0; i<v.size(); i++){
        sm = max(v[i], v[i]+sm);
        ans = max(ans, sm);
    }
    cout << ans << endl;
    return;
}

int main(){
    vector<int> vec = {3, -4, 5, 4, -1, 7, -8};
    max_sub_array_sum(vec);
    

    return 0;
}