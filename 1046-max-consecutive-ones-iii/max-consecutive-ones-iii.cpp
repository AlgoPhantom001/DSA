class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int count=0;
        int maxi=0;

        int n=nums.size();

        while(j<n){
            if(nums[j]==0) count++;

            while(count>k){
                if(nums[i]==0){
                    count--;
                    i++;                   
                } 
                else {
                    i++;
                }
            }

            maxi=max(maxi,j-i+1);
            j++;



        }
        return maxi ;
    }
};