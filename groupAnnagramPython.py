# Given an array of strings strs, group the anagrams together. You can return the answer in any order.
# An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
# typically using all the original letters exactly once.
# Example 1:
# Input: strs = ["eat","tea","tan","ate","nat","bat"]
# Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
# Example 2:
# Input: strs = [""]
# Output: [[""]]
# Example 3:
# Input: strs = ["a"]
# Output: [["a"]]
# Constraints:
# 1 <= strs.length <= 104
# 0 <= strs[i].length <= 100
# strs[i] consists of lowercase English letters.


class Solution:
  def groupAnagrams(self,strs):
    def create_char_frequency_dict(word):
        char_frequency = {}
        for char in word:
            char_frequency[char] = char_frequency.get(char, 0) + 1
        return char_frequency
    anagram_groups = {}
    for word in strs:
        word_char_frequency = create_char_frequency_dict(word)
        key = tuple(sorted(word_char_frequency.items()))
        if key in anagram_groups:
            anagram_groups[key].append(word)
        else:
            anagram_groups[key] = [word]
    result = list(anagram_groups.values())
    return result


