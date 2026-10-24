class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i=0
        j=len(nums)-1



        
        while(i<=j):

            while( j>=0 and nums[j]==val) : j-=1
            if(j<=i and nums[i]==val) : return i
            if(nums[i]==val):
                temp=nums[j]
                nums[i]=temp
                nums[j]=val
                j=j-1


            i+=1

        return i
        

