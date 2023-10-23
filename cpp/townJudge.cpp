#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
void bfs(unordered_map<int,unordered_map<int,int>>&mp,int s,vector<bool>&visited){
queue<int>q;
visited[s]=true;
q.push(s);
while(!q.empty()){
int u=q.front();
q.pop();
auto itr=mp.find(s);
for(auto t=(itr->second).begin();t!=(itr->second).end();t++)
{
	if(visited[t->first]==false){
		visited[t->first]=true;
		q.push(t->first);
	
	}
}
}
}
bool bfsdis(unordered_map<int,unordered_map<int,int>>&mp,int v){
	vector<bool>visited(v+1,false);
	for(int i=1;i<=mp.size();i++){
		if(visited[i]==false){
			bfs(mp,i,visited);
		}	
	}
	int fg=0;
	int chk;
	for(int i=1;i<v+1;i++){
		if(fg==1 && visited[i]==false){			
			return false;}	
		else if(visited[i]==true)chk=i;
	}	
	for(auto itr=mp.begin();itr!=mp.end();itr++){
        int fg2=0;
		//cout<<itr->first<<"->";
        for(auto t=(itr->second).begin();t!=(itr->second).end();t++)
                if(t->first==chk)fg2=1;
        if(fg2==0)return false;

}
return true;
}
int main(){
cout<<"enter r and c";
int r,c;
cin>>r>>c;
cout<<"enter n"<<endl;
int v;
cin>>v;
vector<vector<int>>mat;
for(int i=0;i<r;i++){
	vector<int>t;
	for(int j=0;j<c;j++){
		int g;
		cin>>g;
		t.push_back(g);
	}
	mat.push_back(t);
}
cout<<"printing matrix"<<endl;
for(int i=0;i<r;i++){
	for(int j=0;j<c;j++)
		cout<<mat[i][j]<<" ";
	cout<<endl;
}
unordered_map<int,unordered_map<int,int>>mp;
for(int i=0;i<r;i++){
	mp[mat[i][0]][mat[i][1]]++;
}
cout<<"hii"<<endl;
cout<<"printing mp"<<endl;
for(auto itr=mp.begin();itr!=mp.end();itr++){
	cout<<itr->first<<"->";
	for(auto t=(itr->second).begin();t!=(itr->second).end();t++)
		cout<<t->first<<" ";
	cout<<endl;

}
if(bfsdis(mp,v))cout<<"thier is judje"<<endl;
else cout<<"no";
return 0;
}
