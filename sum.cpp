//Leetcode DSA Sheet
//Problem Link: https://leetcode.com/problems/3sum/submissions/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int k = 0;
        sort(nums.begin(), nums.end());
        
        if(nums.size() < 3)
            return ans;
        
        if(nums[0] > 0)
            return ans;
        
        for(int i = 0; i<nums.size();i++){
            
            if(i>0 && nums[i-1] == nums[i])
                continue;
            
            int low = i + 1;
            int high  = nums.size() - 1;
         
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum > 0)
                    high--;
                else if(sum < 0)
                    low++;
                else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    ans.push_back(temp);
                    int last_low = nums[low];
                    int last_high = nums[high];
                    
                    //toavoidduplication_of_lastlow_and_lasthigh_occurences
                    while(low<high && nums[low] == last_low)
                        low++;
                    while(low<high && nums[high] == last_high)
                        high--;
                    
                }
            }
            
        }
        return ans;
    }
};