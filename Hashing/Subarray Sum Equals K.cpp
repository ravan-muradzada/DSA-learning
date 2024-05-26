#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k){
    int n = nums.size(), prefixSum, count, target;
    prefixSum = count = 0;
    
    unordered_map<int, int> mp; // sum, count of sum
    mp[0] = 1;
    
    for (int i = 0; i < n; ++i){
        prefixSum += nums[i];
        
        target = prefixSum - k;
        
        count += mp[target];
        
        mp[prefixSum]++;
    }
    
    return count;
}


int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 9;
    
    cout << subarraySum(nums, k);
    
    return 0;
}
