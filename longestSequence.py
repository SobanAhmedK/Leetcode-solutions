# Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

# You must write an algorithm that runs in O(n) time.
# Example 1:
# Input: nums = [100,4,200,1,3,2]
# Output: 4
# Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
# Example 2:
# Input: nums = [0,3,7,2,5,8,4,6,0,1]
# Output: 9
# #


class Solution(object): 
   

   def longestConsecutive( self,nums):
        if not nums:
            return 0

        set_nums = set(nums)
        n = sorted(set_nums, key=lambda x: (x >= 0, x))
        counting = n[0]
        l = 1
        maxlength = 1  

        for num in n[1:]: 
            if num == counting + 1:
                counting = num
                l += 1
                maxlength = max(maxlength, l)  
            else:
                counting = num
                l = 1 

        return maxlength
    
    
    #in this solution on larger inputs complexity will be O(N logN) because or sorting function