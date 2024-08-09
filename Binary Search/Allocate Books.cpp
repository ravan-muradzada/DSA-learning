#include <bits/stdc++.h>
using namespace std;

void findMinMax(vector<int>& nums, int& left, int& right){
    left = nums[0];
    right = 0;
    for (int i = 0; i < nums.size(); ++i){
        left = max(left, nums[i]);
        right += nums[i];
    }    
}

int determine(vector<int>& arr, int mid){
    int st = 1, curr = 0;
    
    for (int i = 0; i < arr.size(); ++i){
        if (curr + arr[i] > mid){
            curr = 0;
            st++;
        }
        curr += arr[i];
    }
    
    return st;
}

int findPages(vector<int>& arr, int m){
    int left, right;
    findMinMax(arr, left, right);
    int mid, res = -1, st;
    
    while (left <= right){
        mid = (left + right) / 2;
        st = determine(arr, mid);
        
        if (st == m) res = mid;
        
        if (st > m){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    
    return res;
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
    int m = 3;    
    
    cout << findPages(arr, m) << endl;
        
    return 0;
}
