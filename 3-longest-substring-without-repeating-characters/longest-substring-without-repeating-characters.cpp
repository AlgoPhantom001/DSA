class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int i=0;
        int j=0;

        int maxi=0;
        int n=s.size();
        unordered_map<char,int> mp;


        while(j<n){

            mp[s[j]]++;

            while(mp[s[j]]!=1){
                mp[s[i]]--;
                i++;
                
            }
            
            maxi=max(j-i+1,maxi);
            j++;


        }
        return maxi;


    }
};