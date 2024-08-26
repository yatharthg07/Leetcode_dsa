#define ll long long
class Solution {
public:
    ll ans=0;
    void merge(vector<int> &arr,ll low,ll mid,ll high)
    {
        vector<ll> temp;
        ll i=low;
        ll j=mid+1;
        while(i<=mid && j<=high)
        {
            while(j<=high && arr[i]>2ll*arr[j]  )
            {
                j++;
            }
            ans+=j-(mid+1);
            i++;
        }
        while(i<=mid)
        {
            ans+=j-(mid+1);
            i++;
        }
        i=low;
        j=mid+1;

        while(i<=mid && j<=high)
        {
            if(arr[i]<=arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;

            }
        }
        while(i<=mid)
        {
            temp.push_back(arr[i++]);
        }
        while(j<=high)
        {
            temp.push_back(arr[j++]);
        }
        
        for(int i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
        
    }
    void mergesort(vector<int> & arr,ll low,ll high)
    {
        if(low>=high)
        {
            return;
        }
        ll mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return ans;
        
    }
};