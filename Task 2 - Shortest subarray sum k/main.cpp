#include <iostream>
#include <bits/stdc++.h>


using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int best = INT32_MAX;
        int left = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum >= target){
                best = min(best,i-left+1);
                sum-=nums[left];
                left++;
                   
            }
        }

        if(best == INT32_MAX) return 0;
        return best;
    }
};


int main(){
    vector<int> arr = {2,3,1,2,4,3};
    auto answer = Solution().minSubArrayLen(7,arr);

    std::cout << answer <<endl;
    return 0;
}

