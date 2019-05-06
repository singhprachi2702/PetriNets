# include<iostream>
# include<set>
# include<vector>
#include<bits/stdc++.h> 
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string line;
	vector<string> places;
	vector<string> transitions;
	set<string> marking;
	int no_transitions, no_places;
	
	string word="";
  	ifstream myfile("example.txt");
  	if (myfile.is_open())
  	{
    	getline(myfile,line);
    	stringstream iss(line); 
 		iss >> word; 
        	
        while(iss >> word)
        {
        	auto it = std::find(places.begin(), places.end(), word);
 			if (it == places.end())
				places.push_back(word);
        }
        getline(myfile,line);
        stringstream isst(line);
        isst >> word;

        while(isst >> word)
        {
        	auto it = std::find(transitions.begin(), transitions.end(), word);
 			if (it == transitions.end())
        	transitions.push_back(word);
        }

        no_places = places.size();
    	no_transitions = transitions.size();
    	int arr[no_transitions][no_places];
    	for(int i=0;i<no_transitions;i++)
    	{
    		for(int j=0;j<no_places;j++)
    		{
    			arr[i][j]=0;
    		}
    	}

    	getline(myfile,line);
    	stringstream iss2(line);

    	iss2 >> word;

    	while(iss2>>word)
    	{
    		marking.insert(word);
    	}
    	// cout<<"Number of places : "<<no_places;
    	// cout<<"\nNumber of transitions : "<<no_transitions;

    	// vector<string> :: iterator itr; 
    	// cout << "\nThe places are : "; 
    	// for (itr = places.begin(); itr != places.end(); ++itr) 
    	// { 
     //    	cout<<*itr<<" "; 
    	// }

		while(getline(myfile,line))
		{
			bool track = true;
			stringstream isst(line);
			isst >> word;
			
			auto it1 = std::find(transitions.begin(),transitions.end(),word);
			

			if(it1!=transitions.end())
			{
				int row = std::distance(transitions.begin(), it1);	
				// cout<<"row : "<<row;
				while(isst >> word)
				{
					// cout<<"2 :"<<word<<"\n";
					if(word==",")
					{
						track=false;
					}
					if(track)
					{
						auto it2 = std::find(places.begin(),places.end(),word);
						int column = std::distance(places.begin(), it2);
						arr[row][column]=-1;
					}
					else
					{
						auto it2 = std::find(places.begin(),places.end(),word);
						int column = std::distance(places.begin(), it2);
						arr[row][column]=1;
					}
				}
			}
		}
		for(int i=0;i<places.size();i++)
		{
			cout<<places[i]<<" ";
		}
		cout<<"\n";		 
		for(int i=0;i<no_transitions;i++)
		{
			for(int j=0;j<no_places;j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}  	
    	myfile.close();
  	}
	else
	{
		cout << "Unable to open file"; 
	}
	
	for(int i=0;i<transitions.size();i++)
	{
		cout<<transitions[i]<<" ";
	}
	cout<<"Marking is : ";
	set <string> :: iterator sitr; 
   
    for (sitr = marking.begin(); sitr != marking.end(); ++sitr) 
    { 
        cout <<*sitr<<" "; 
    } 
    cout << endl; 
	/*
	set <string> :: iterator itr; 
    cout << "\nThe set places is : "; 
    for (itr = places.begin(); itr != places.end(); ++itr) 
    { 
        cout<<*itr<<" "; 
    }
    cout<<"\nThe set of transition is : ";
    for (itr = transitions.begin(); itr != transitions.end(); ++itr) 
    { 
        cout<<*itr<<" "; 
    }
    cout << endl;*/

	return 0;
}
