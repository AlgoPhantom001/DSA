class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict={}
        for i ,no in enumerate(nums):
            if(no in dict): return [dict[no],i]
            tar=target-no
            dict[tar]=i
        