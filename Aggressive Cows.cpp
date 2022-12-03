You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:

Input:
n=5 
k=3
stalls = [1 2 4 8 9]
Output:
3
Explanation:
The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, 
which also is the largest among all possible ways.

Solution:

class Solution {
public:
    bool ispossible(int mid,vector<int> &stalls,int k)
    {
        int temp=stalls[0],count=1;
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-temp>=mid)
            {
                temp=stalls[i];
                count++;
            }
            if(count==k)
             return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int diff_max=stalls[n-1]-stalls[0],diff_min=1,ans=1;
        while(diff_min<=diff_max)
        {
            int mid=(diff_max+diff_min)/2;
            if(ispossible(mid,stalls,k))
            {
                diff_min=mid+1;
                ans=max(ans,mid);
            }
            else
            {
                diff_max=mid-1;
            }
        }
        return ans;
        
    }
};
