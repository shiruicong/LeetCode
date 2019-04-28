class Solution(object):
    def myAtoi(self, str_):
        """
        :type str: str
        :rtype: int
        """
        flag = 0     //标记是不是第一个非空字符，当出现了第一个非空字符时，flag=1
        flag_1 = 0     //标记正，负号，当flag_1==0时，表示没有出现任何的“+”，“-”号，如果flag_1==“-1”，表示出现了“-”，否则为“+”
        sub = "0"
        for char in str_:
            if flag ==0:
                if char == " ":
                    if flag_1 ==0:
                        continue
                    else:
                        return 0
                elif char != " ":
                    if char == "+":
                        if flag_1 != 0:
                            return 0 
                        elif flag_1 == 0:
                            flag_1 = 1
                    elif char == "-":
                        if flag_1 != 0:
                            return 0 
                        elif flag_1 == 0:
                            flag_1 = -1
                    elif 48<=ord(char)<=57:
                        sub = char
                        flag = 1
                        if flag_1==0:
                            flag_1 = 1
                    else:
                        return 0
            elif flag !=0:
                if 48<=ord(char)<=57:
                    sub += char
                elif char == ".":
                    sub += char
                else:
                    break
        print(sub)           
        num = int(flag_1 * float(sub))
        if num < -2147483648 :
            return  -2147483648 
        if num > 2147483647:
            return  2147483647
        
        return num
                