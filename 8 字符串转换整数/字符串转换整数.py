class Solution(object):
    def myAtoi(self, str_):
        """
        :type str: str
        :rtype: int
        """
        flag = 0     //����ǲ��ǵ�һ���ǿ��ַ����������˵�һ���ǿ��ַ�ʱ��flag=1
        flag_1 = 0     //����������ţ���flag_1==0ʱ����ʾû�г����κεġ�+������-���ţ����flag_1==��-1������ʾ�����ˡ�-��������Ϊ��+��
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
                