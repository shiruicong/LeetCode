class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """ 
        if len(s)<2:
            return len(s)
        maxlength = 0
        set_s = set(s)
        dic = dict(zip(set_s, [-1]*len(set_s))) 
        left = -1
        for index, char in enumerate(s):
            if dic[char] != -1: 
                left = max (left, dic[char])    #一定要加max
                dic[char] = index
                right = index
                maxlength = max(maxlength, right - left)
                 
            if dic[char] == -1:
                dic[char] = index
                right = index
                maxlength = max (maxlength, right - left)   
                
        return maxlength