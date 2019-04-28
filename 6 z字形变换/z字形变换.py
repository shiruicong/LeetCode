class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if len(s)<=1:
            return s
        if numRows==1:
            return s
        if numRows >= len(s):
            return s
        dic = dict(zip([i for i in range(numRows)], [-1]* numRows))
        i = 0;
        flag = 1
        for char in s:
            if dic[i]==-1:
                dic[i] = char
            elif dic[i] !=-1:
                temp = dic[i]
                temp = temp + char
                dic[i] = temp
            i = i+ flag
            if i == numRows -1:
                flag = -1
            if i == 0:
                flag = 1
        str_sum = ""
        for value in dic.values():
            str_sum += value
        return str_sum
            
            
            
            
                