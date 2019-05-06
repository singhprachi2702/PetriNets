# include<iostream>
# include<queue>
# include<bits/stdc++.h> 
# include<vector>
using namespace std;

class Marking
{
public:
	vector<int> Initial{vector<int>(11,0)};
	set<int> s;
	Marking(vector<int> mark)
	{
		
		for(int i=0;i<mark.size();i++)
		{
			Initial[mark[i]]=1;
			s.insert(mark[i]);
		}

			
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

class transition
{
public:
	vector<vector<int> > preplace;
 	vector<vector<int> > postplace;

	transition(vector<vector<int> > vect)
	{		                
	 	for(int i=0;i<vect.size();i++)
	 	{
	 		preplace.push_back(std::vector<int> ());
	 		postplace.push_back(std::vector<int> ());
	 		
	 		for(int j=0;j<vect[i].size();j++)
	 		{
	 			if(vect[i][j]==-1)
	 				preplace[i].push_back(j);
	 			if(vect[i][j]==1)
	 				postplace[i].push_back(j);
	 		}
	 	}	
	}

	void print()
	{
		cout<<"Preplace :";
		for(int i=0;i<preplace.size();i++)
		{
			for(int j=0;j<preplace[i].size();j++)
			{
				cout<<preplace[i][j]<<"  ";
			}
			cout<<"\n";
		}
		cout<<"Postplace";
		for(int i=0;i<postplace.size();i++)
		{
			for(int j=0;j<postplace[i].size();j++)
			{
				cout<<postplace[i][j]<<" ";
			}
			cout<<"\n";
		}
	}	
};
void reachability(transition t,Marking m)
{
	int i,j;
	bool flag=true;
	set<int> remainingt;
	
	for(int i=0;i<t.size();i++)
	{
		s.insert(i);
	}

	while()
}
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

	transition t(vect);
	t.print();
	vector<int> mark({0});
	Marking obj(mark);
	obj.print();
	int x = obj.retsize();
	cout<<x;
	cout<<"\n";
	cout<<"obj set"<<obj.s.size();
	reachability(t,obj);	

	return 0;
}