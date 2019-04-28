class Solution {
public:
    int reverse(int x) {
        int p[32];
        int flag =1;
        int i = 0, k = 0;
        if(x <= -2147483648)
            return 0;
        if(x >= 2147483647)
            return 0;
        if (x <0)
        {
            flag = -1;
            x = -x;
        }        
        while(x!=0)
        {
            k = x % 10;
            p[i] = k;
            x = x/10;
            i++;
        }
      
        double sum =0;
        for (int j=0; j<i; j++)
        {         
             if (p[j]!=0 )
            {
                
                sum += p[j] * pow(10,(i-1-j));
            }           
        }
        sum = sum * flag;
        if(sum <= -2147483648)
            return 0;
        if(sum >= 2147483647)
            return 0;
        else
            return sum;
    }
};