# include<iostream>
# include<set>
# include<vector>
#include<bits/stdc++.h> 
#include <fstream>
#include <string>
using namespace std;

int main()
{
	vector<string> places{"p1","p2","p3"};
	vector<string> transitions{"t1","t2","t3"};
	int arr[3][3]={{-1 ,1, 0},{-1,0,1},{0,-1,1}};

	set<string> marking{"p1"};
	set<string> enabled;
	bool if_enabled = true;


	while(if_enabled)
	{
		for(int i=0;i<transitions.size();i++)
		{
			bool counter1=true;
			for(int j=0;j<places.size();j++)
			{
				if(arr[i][j]==-1)
				{
					if(marking.find(places[j]) == marking.end())
						counter1=false;
				}
			}
			if(counter1)
			{
				// cout<<"true : "<<transitions[i]<<"\n";
				// for(int j=0;j<places.size();j++)
				// {
				// 	auto pos = marking.find(places[j]);
				// 	if(pos != marking.end())
				// 		marking.erase(pos);
				// }
				enabled.insert(transitions[i]);
			}

		}
		if(enabled.size()>1)
		{

		}
	}

	return 0;
}