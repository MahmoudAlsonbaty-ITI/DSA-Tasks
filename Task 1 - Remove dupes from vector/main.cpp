#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>


using namespace std;
class Solution {
public:
    vector<int> removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        int res = 0;

        for(int i =0; i< nums.size();i++){
            if(freq.count(nums[i]) != 0){
                nums.erase(nums.begin() + i);
                i--;
                continue;
            }
            freq[nums[i]] = 1;
        }
        return nums;
    }
};

int main(){
    vector<int> arr = {2,1,3,1,2,4,3};
    auto answer = Solution().removeDuplicates(arr);

    for(auto t:answer){
        cout << t <<endl;
    }
    // std::cout << answer <<endl;
    return 0;
}

