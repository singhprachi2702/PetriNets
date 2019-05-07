# include<iostream>
# include<unistd.h>
#include <fstream>
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
		{
			Initial[mark[i]]=1;
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

bool isnotmem(set<int> s, int x)
{
	if(s.count(x)!=0) 
    		return false;
	else
		return true;
} 
void reachability(transition t,Marking m)
{
	set<int> remaint;
	std::ofstream ofs;
	ofs.open("a.txt", std::ofstream::out | std::ofstream::trunc);
	ofs<<"digraph M {";	
  	
	set<int> s;
	bool flag=true;
	//cout<<"Step1";
	for(int i=0;i<t.preplace.size();i++)
		remaint.insert(i);
	//cout<<"Step2";
	/*for(auto it=remaint.begin();it != remaint.end();++it)
		cout<<*it<<" ";*/
	
	while(!remaint.empty())
	{
		/*cout<<"\nStart Printing remaint";
		for(auto it=remaint.begin();it != remaint.end();++it)
			cout<<*it<<" ";
		cout<<"\nEnd Printing remaint";*/

		for(int i=0;i<m.retsize();i++)
		{
			if(m.Initial[i]==1)
			{	
				s.insert(i);
				//cout<<i<<" ";
				//break;-------------------------->
			}
		}
		
		
		//cout<<"Step3";
		for (auto it=remaint.begin();it != remaint.end();++it) 
        	{
			flag=true;
			//cout<<"Step4";
			
			for(int i=0;i<t.preplace[*it].size();i++)
			{
				if(isnotmem(s,t.preplace[*it][i]))
				{
					flag=false;
					break;
				}
			}
			//cout<<"Step5";
			
			//cout<<"Print value of Flag"<<flag;
			//cout<<"Step 6";
			
			
			/*if(flag==true)
			{
				//cout<<"Hahaha"<<*it<<"\n";
				remaint.erase(*it);
				//cout<<"Again Hahaha"<<*it<<"\n";
				
				for(int i=0;i<t.preplace[*it].size();i++)
				{
					cout<<t.preplace[*it][i]<<" ";
					ofs<<t.preplace[*it][i]<<" ";
				}

				cout<<"->";
				ofs<<"->";
					
				for(int j=0;j<t.postplace[*it].size();++j)
				{	
					//cout<<"\ninside 1 for";				
					m.Initial[t.postplace[*it][j]]=1;
					cout<<t.postplace[*it][j]<<" ";
					ofs<<t.postplace[*it][j]<<" ";
				}
				for(int j=0;j<t.preplace[*it].size();++j)
				{
					//cout<<"\ninside 2 for";
					s.erase(t.preplace[*it][j]);
					m.Initial[t.preplace[*it][j]]=0;
				}
				//break;---------------------------------------------------->
				cout<<"\n";
				ofs<<"\n";
			}*/
			if(flag==true)
			{
				remaint.erase(*it);
				int i=0;
				while(i<t.preplace[*it].size())
				{	
					for(int j=0;j<t.postplace[*it].size();++j)
					{
						
							cout<<t.preplace[*it][i]<<"->";
							ofs<<t.preplace[*it][i]<<"->";

							m.Initial[t.postplace[*it][j]]=1;
							cout<<t.postplace[*it][j]<<"\n";
							ofs<<t.postplace[*it][j]<<"\n";

							s.erase(t.preplace[*it][i]);
							m.Initial[t.preplace[*it][i]]=0;

					}
				i++;
				}	
			}
		//cout<<"exiting for loop";	
		}
	//cout<<"exiting while loop";
	}
//cout<<"exiting function";
	ofs<<"}";
  	ofs.close();
}
int main()
{
	vector<vector<int> > vect{ 	{-1,1,0,0,0,0,0,0,0,0,0}, 
                               	  	{0,-1,1,0,0,0,0,0,1,0,0},
					{0,0,-1,1,0,1,0,0,0,0,0},
					{0,0,0,-1,1,0,0,0,0,0,0},
					{0,0,0,0,0,-1,1,0,0,0,0},
					{0,0,0,0,-1,0,-1,1,0,0,0},
					{0,0,0,0,0,0,0,0,-1,1,0},
			                {0,0,0,0,0,0,0,-1,0,-1,1} };

	transition t(vect);
	//t.print();
	vector<int> mark({2});
	Marking obj(mark);
	//obj.print();
	int x = obj.retsize();
	//cout<<x;
	//cout<<"\nCalling Reachability\n";
	reachability(t,obj);
	
  	//system("chmod 777 a.txt");
	//system("dot -Tpng test.txt -o diag.png");
	//system("dot -Tpng a.txt -o dia.png");
	cout<<"Process Complete !! ";
	return 0;
}
