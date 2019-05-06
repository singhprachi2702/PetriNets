# include<iostream>
# include<queue>
# include<bits/stdc++.h> 
# include<vector>
using namespace std;

class Marking
{
	public:
	vector<int> Initial{vector<int>(11,0)};
	Marking(vector<int> mark)
	{
		
		for(int i=0;i<mark.size();i++)
			Initial[mark[i]]=1;
			
	}

	void print()
	{
		for(int i=0;i<Initial.size();i++)
			cout<<Initial[i]<<" ";
		cout<<"\n";
	}

	int retsize()
	{
		return Initial.size();
	}	
};

class Tset
{
	queue<int> transitions;
	set<int> s;
	vector<int> next;
	public:
	Tset(vector<vector<int> >vect, Marking obj)
	{
		for(int j=0;i<obj.retsize();j++)
		{
			if(obj[j]==1)
				s.insert(j);
		}
		next = enabledTransactions(vector<vector<int> > vect, Marking obj,set<int> s)
			
	} 

	bool ismem(set<int> s, int v)
	{
		std::vector<int>::iterator it; 		
		auto p = s.find(v)
		if(it != s.end())
			return true;
		else
			return false;
	}		

	vector<int> enabledTransactions(vector<vector<int> > vect, Marking obj,set<int> s)
	{
		for (int i=0; i<obj.retsize();i++)
		{
				
		}
	}
};

 
int main()
{
	
	vector<vector<int> > vect{ {-1,1,0,0,0,0,0,0,0,0,0}, 
                               {0,-1,1,0,0,0,0,0,1,0,0},
							   {0,0,-1,1,0,1,0,0,0,0,0},
							   {0,0,0,-1,1,0,0,0,0,0,0},
							   {0,0,0,0,0,-1,1,0,0,0,0},
							   {0,0,0,0,-1,0,-1,1,0,0,0},
							   {0,0,0,0,0,0,0,0,-1,1,0},
			                   {0,0,0,0,0,0,0,-1,0,-1,1} };

	vector<int> mark({0});
	Marking obj(mark);
	obj.print();
	int x = obj.retsize();
	cout<<x;
	cout<<"\n";
	Tset tset(vect,obj);
	for (int i = 0; i < vect.size(); i++) 
	{ 
        	for (int j = 0; j < vect[i].size(); j++) 
            		cout << vect[i][j] << " "; 
        cout << endl; 
    	} 
   	
		
	return 0;
}


