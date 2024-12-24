#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0, q = 0;
    int element = 0;
    
    vector<int> arr;
    
    cin>>n;
    while(n--){
        cin>>element;
        arr.push_back(element);
    }
    
    cin>>q;
    
    int target = 0;
    
    while(q--){
        cin>>target;
        
        const auto result = lower_bound(arr.begin(), arr.end(), target);
        
        if (*result == target) {
            cout<< "Yes " << *result<<endl;
        } else {
            cout<<  "No " << *result<<endl;
        }
        
    }
    
    return 0;
}