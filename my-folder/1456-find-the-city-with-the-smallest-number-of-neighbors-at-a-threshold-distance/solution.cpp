#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int> (n,INT_MAX));
        for(auto it:edges)
        {
            mat[it[0]][it[1]]=it[2];
            mat[it[1]][it[0]]=it[2];       
        }
        for(int i=0;i<n;i++)
        {
            mat[i][i]=0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(mat[i][k]<INT_MAX && mat[k][j]<INT_MAX)
                    {
                        mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        } 


        vector<pair<int,int>> cit;
        for(int i=0;i<n;i++)
        {
            cit.push_back({0,i});
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(i==j)
                {
                    continue;
                }
                if(mat[i][j]<=distanceThreshold)
                {
                    cit[i].first++;
                }


            }
        }
        sort(cit.begin(),cit.end());

        for(int i=0;i<n;i++)
        {
            cout<<cit[i].first<<" "<<cit[i].second<<endl;
        }
        for(int i=0;i<n-1;i++)
        {
            if(cit[i+1].first>cit[i].first)
            {
                return cit[i].second;
            }
        }
        return cit[n-1].second;
        // auto upper = upper_bound(cit.begin(), cit.end(),*cit.begin());
        // return cit[upper-cit.begin()-1].second;


    
    }
};
