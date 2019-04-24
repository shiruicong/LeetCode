class Solution {
public:
    string longestPalindrome(string s) {  
        
        string str="";
        int len = s.length();
        if (len==0)
        {
            return str; 
        }
        
        string sub;
        int length[len][len];
        int left = 0;
        int right = 0;
        int max_len = 0;
        
        for(int i=0; i<len; i++)
        {
            for(int j=0; j<len; j++)
            {
                if(i==j)
                {
                    length[i][j] = 1;
                }
              if(j>i)
              {
                  length[i][j]=0;
              }
          }
        }
        for(int i=0; i<len; i++)
        {
          for(int j=0; j<i; j++)
            {
                if(i!=j)
                {
                    if(s[i]!=s[j])
                    {
                        length[i][j] = -1;
                    }
                    if(s[i]==s[j])
                    {
                        if(length[i-1][j+1]==-1)
                        {
                          length[i][j] = -1;  
                        }
                         if(length[i-1][j+1]>=0)
                        {
                          length[i][j] = length[i-1][j+1]+2;  
                        }
                        
                        if (length[i][j]>max_len)
                        {
                            max_len = length[i][j];
                            left = j;
                            right = i;
                        }
                    }                                                
                }
            }  
        }
       // printf("%d    %d\n", left,right);
        //for(int i=0; i<len; i++)
       // {
            //for(int j=0; j<i+1; j++)
            //{
                //printf("%d\t",length[i][j]);
          //}
          //  printf("\n");
        // }
        sub = s.substr(left, right+1);
        sub = sub.substr(0, right-left+1);
        return sub;
        
    }
};