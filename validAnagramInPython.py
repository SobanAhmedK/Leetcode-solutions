# Given two strings s and t, return true if t is an anagram of s, and false otherwise.
# An Anagram is a word or phrase formed by rearranging the letters of a different word 
# or phrase, typically using all the original letters exactly once.
# Example 1:
# Input: s = "anagram", t = "nagaram"
# Output: true
# Example 2:
# Input: s = "rat", t = "car"
# Output: false
# Constraints:
# 1 <= s.length, t.length <= 5 * 104
# s and t consist of lowercase English letters.

class Solution(object):
    def isAnagram(self, s, t):
        s_map=dict()
        t_map=dict()
        flag=True

        if len(s)!=len(t):
            flag=False
            return flag
        else:
            for letter in s:
                if(letter in s_map):
                    s_map[letter]+=1
                else:
                    s_map[letter]=1
            for letter in t:
                if(letter not in s_map):
                    flag=False
                    return flag
                   
                elif(letter in t_map):
                    t_map[letter]+=1
                    if (t_map[letter]>s_map[letter]):
                        flag=False
                        return flag
                else:
                    t_map[letter]=1
        return flag
