#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans;
	    vector<int>ind(v,0);
	    for(int i=0;i<v;i++){
	        for(int x:adj[i]){
	            ind[x]++;
	    }
	    }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(ind[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int v:adj[u]){
                ind[v]--;
                if(ind[v]==0)
                q.push(v);
            }
        }
	    return ans;
	    
	}
};
int main()
{

    	vector<int> adj[7];
    	adj[2].push_back(1);
    	adj[5].push_back(0);
    	adj[4].push_back(0);
    	adj[4].push_back(1);
    	adj[3].push_back(1);
    	adj[2].push_back(3);
    	adj[6].push_back(3);
    	Solution obj;
    	vector<int> v=obj.topoSort(7, adj);
    	for(auto it:v)
    	cout<<it<<" ";


    return 0;
}