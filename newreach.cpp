# include<iostream>
# include<set>
# include<vector>
#include<bits/stdc++.h> 
#include <fstream>
#include <string>
using namespace std;

vector<vector<string>> nodes;
int number_of_nodes=0;

void create_node(set<string> marking)
{
	cout<<"create node called";
	bool count = false;
	for(int i=0;i<nodes.size();i++)
	{	
		for(int j=0;j<nodes[i].size();j++)
		{
			if(marking.find(nodes[i][j]) == marking.end())
			{
					count=true;
					break;
			}
		}
	}
	if(count || number_of_nodes == 0)
	{
		cout<<"Marking size: "<<marking.size();
		set<string> :: iterator itr;
		nodes.push_back(std::vector<string> ());
		for(itr = marking.begin(); itr!= marking.end() ; ++itr )
		{
			cout<<*itr<<" ";
			nodes[number_of_nodes].push_back(*itr);
		}
		cout<<"\n";
		number_of_nodes++;
	}
}

int main()
{
	vector<vector<string>> input;
	vector<vector<string>> output;

	vector<vector<string>> tps;

	set<string> marking;

	input.push_back(std::vector<string> ());
	output.push_back(std::vector<string> ());

	input[0].push_back("p5");
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
	output[2].push_back("p4");

	input.push_back(std::vector<string> ());
	output.push_back(std::vector<string> ());

	input[3].push_back("p3");
	input[3].push_back("p4");
	output[3].push_back("p5");

	tps.push_back(std::vector<string> ());

	tps[0].push_back("t2");
	//tps[0].push_back("t1");
	//tps[0].push_back("t3");

	tps.push_back(std::vector<string> ());

	tps[1].push_back("t3");

	tps.push_back(std::vector<string> ());

	tps[2].push_back("t4");
	//tps[2].push_back("t2");

	tps.push_back(std::vector<string> ());

	tps[3].push_back("t4");

	tps.push_back(std::vector<string> ());

	tps[4].push_back("t1");

	std::vector<string> transitions{"t1","t2","t3","t4"};
	std::vector<string> places{"p1","p2","p3","p4","p5"};

	marking.insert("p1");
	marking.insert("p2");
	bool indicator = true;

	create_node(marking);

	set<string> :: iterator iter;
	//for(iter=marking.begin();iter != marking.end();iter++)
	//for(int i=0;i<marking.size();i++)
	while(marking.size() != 0 && indicator)
	{
		auto iter = marking.begin();
		auto it1 = std::find(places.begin(),places.end(),*iter);
		int index1 = std::distance(places.begin(), it1);
		cout<<"Inside 1\n";
		for(int j=0;j<tps[index1].size();j++)
		{
			cout<<tps[index1][j];
			auto it2 = std::find(transitions.begin(),transitions.end(),tps[index1][j]);
			int index2 = std::distance(transitions.begin(), it2);	
			cout<<"Inside 2 "<<*it2<<"\n";
			cout<<"Index 2 "<<index2;
			
			for(int x=0;x<input[index2].size();x++)
			{
				cout<<"Inside 3\n";
				if(marking.find(input[index2][x]) == marking.end())
					indicator = false;
			}

			if(indicator)
			{
				for(int y=0;y<input[index2].size();y++)
				{
					cout<<"Inside 4\n";
					marking.erase(marking.find(input[index2][y]));
				}
				for(int z=0;z<output[index2].size();z++)
				{
					cout<<"Inside 5\n";
					marking.insert(output[index2][z]);
				}
				create_node(marking);
			}
		}
	}


	return 0;

}


