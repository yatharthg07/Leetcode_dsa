class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int temp=m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1[temp]=nums1[i];
                temp--;
                i--;
            }
            else
            {
                nums1[temp]=nums2[j];
                temp--;
                j--;
            }
        }
        while(i>=0)
        {
            nums1[temp--]=nums1[i--];
        }
        while(j>=0)
        {
            nums1[temp--]=nums2[j--];
        }
        
    }
};