class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i=0
        j=len(height)-1
        n=len(height)-1
        maxi=0
        while(j>=0 and i<=n):
            area=min(height[i],height[j])*(abs(j-i))
            maxi=max(area,maxi)
            if(height[i]>height[j]) : j-=1
            else: i+=1

        return maxi
            

        