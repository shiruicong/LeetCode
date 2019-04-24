class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {     
        int m = nums1.size();
        int n = nums2.size();
        //int *a=new int[n+m];
        int a[m+n];
        int i=0, j=0, k=0, mid;
        double result;
        while(i<m&&j<n)
        {
            if(nums1[i]>nums2[j])
            {
                a[k] = nums2[j];
                k++;
                j++;
            }
            else if(nums1[i]<=nums2[j])
            {
                a[k] = nums1[i];
                k++;
                i++;
            }
        }
        while(i<m)
        {
            a[k]=nums1[i];
            k++;
            i++;
        }
        while(j<n)
        {
            a[k]=nums2[j];
            k++;
            j++;
        }
        mid = m+n;
        if(mid%2)
            result = a[mid/2];
        else
            result = (a[mid/2-1]+a[mid/2])/2.0;
        return result;
    }
};