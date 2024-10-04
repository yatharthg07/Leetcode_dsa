class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        long long check=skill[0]+skill[n-1];
        long long ans=0;
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            if(skill[l]+skill[r]!=check){
                return -1;
            }
            else
            {
                ans+=(skill[l]*skill[r]);
            }
            l++;
            r--;
        }
        return ans;
    }
};