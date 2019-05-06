# include<iostream>
# include<set>
# include<vector>
#include<bits/stdc++.h> 
#include <fstream>
#include <string>
using namespace std;

int main()
{
	vector<vector<string>> input;
	vector<vector<string>> output;

	vector<vector<string>> tps;

	set<string> marking;

	input.push_back(std::vector<string> ());
	output.push_back(std::vector<string> ());

	input[0].push_back("p0");
	output[0].push_back("p1");
	output[0].push_back("p2");

	input.push_back(std::vector<string> ());
	output.push_back(std::vector<string> ());

	input[1].push_back("p1");
	output[1].push_back("p3");

	input.push_back(std::vector<string> ());
	output.push_back(std::vector<string> ());

	// input[2].push_back("p3");
	input[2].push_back("p2");
	output[2].push_back("p3");

	/*input.push_back(std::vector<string> ());
	output.push_back(std::vector<string> ());

	input[3].push_back("p3");
	input[3].push_back("p4");
	output[3].push_back("p5");*/

	tps.push_back(std::vector<string> ());

	tps[0].push_back("t0");
	//tps[0].push_back("t1");
	//tps[0].push_back("t3");

	tps.push_back(std::vector<string> ());

	tps[1].push_back("t1");

	tps.push_back(std::vector<string> ());

	tps[2].push_back("t2");
	//tps[2].push_back("t2");

	/*tps.push_back(std::vector<string> ());

	tps[3].push_back("t4");

	tps.push_back(std::vector<string> ());

	tps[4].push_back("t1");*/

	std::vector<string> transitions{"t0","t1","t2"};
	std::vector<string> places{"p0","p1","p2","p3"};

	marking.insert("p0");
	// marking.insert("p2");

	vector<string> tocheck{"t0","t1","t2"};


	for(int i=0;i<tocheck.size();i++)
	{
		cout<<"Marking is : ";
		set<string> :: iterator itr;
		for (itr = marking.begin(); itr != marking.end(); ++itr) 
    	{ 
        cout<<*itr; 
    	} 
    	cout<<"\n";
		auto it = std::find(transitions.begin(),transitions.end(),tocheck[i]);
		int index1 = std::distance(transitions.begin(),it);
		cout<<index1<<" ";
		bool t =true;
		cout<<"value is "<<t<<"\n";
		for(int j=0;j<input[index1].size();j++)
		{
			cout<<"\n Inside for loop";
			if(marking.find(input[index1][j]) == marking.end())
			{
				cout<<" input"<<input[index1][j]<<"not present";
				t= false;
				break;
			}
		}
		if(!t)
		{
			cout<<"\nFiring not possible ";
			return 0;
		}
		else
		{
			for(int x=0; x<input[index1].size();x++)
			{
				marking.erase(input[index1][x]);
			}
			for(int y=0 ; y<output[index1].size();y++)
			{
				marking.insert(output[index1][y]);
			}
		}
	}

	cout<<"\nFiring Possible";
	return 0;
}
