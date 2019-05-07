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

class termination
{
public:
	vector<int> terminal{vector<int>(8,0)};

	termination(vector<int> t)
	{
		for(int i=0;i<t.size();i++)
		{
			terminal[t[i]]=1;
		}
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
bool ismem(set<int> s, int x)
{
	if(s.count(x)!=0)
			return true;
	else
		return false;
}
int reachability(transition t,Marking m,vector<int> v)
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
	
	bool b=true;

	while(!remaint.empty()&&(b))
	{
		/*cout<<"\nStart Printing remaint";
		for(auto it=remaint.begin();it != remaint.end();++it)
			cout<<*it<<" ";
		cout<<"\nEnd Printing remaint";*/
		b=false;
		

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

					for(int i=0;i<t.postplace[*it].size();i++)
					{
						if(ismem(s,t.postplace[*it][i]))
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
					bool first=true;
					if(flag==true)
					{
						remaint.erase(*it);
						int i=0;
						while(i<t.preplace[*it].size())
						{	
							cout<<t.preplace[*it][i]<<"->";
							ofs<<t.preplace[*it][i]<<"->";
							for(int j=0;j<t.postplace[*it].size();++j)
							{
									if(!first)
									{
										cout<<",";
										ofs<<",";
									}
									m.Initial[t.postplace[*it][j]]=1;
									cout<<t.postplace[*it][j];
									ofs<<t.postplace[*it][j];

									s.erase(t.preplace[*it][i]);
									m.Initial[t.preplace[*it][i]]=0;
									first=false;
							}
							cout<<"\n";
							ofs<<"\n";	
							i++;
							first=true;
						}	
					}

					
				//cout<<"exiting for loop";	
				}
			// cout<<"start";
			bool l ;
			for (auto it=remaint.begin(); it !=remaint.end(); ++it) 
        		{
        			l=true;
        			for(int j=0;j<t.preplace[*it].size();j++)
        				{
        					if(m.Initial[t.preplace[*it][j]]!=1)
        						l=false;
        				}
        			if(l==true)
        			{
        				b=true;
        			}
				}							
			// cout<<"end\n";
			//cout<<"exiting while loop";
		}
//cout<<"exiting function";
	ofs<<"}";
  	ofs.close();
  	for (auto it=remaint.begin();it != remaint.end();++it) 
        {
        	for(int i=0;i<v.size();i++)
        	{
    			if(*it==v[i])
    				return 0;
    		}
        }	
    return 1;
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
	vector<int> mark({0});
	vector<int> mark2({7});

	Marking obj(mark);
	termination obj2(mark2);

	//obj.print();
	int x = obj.retsize();
	//cout<<x;
	//cout<<"\nCalling Reachability\n";
	if(reachability(t,obj,mark2))
		cout<<"No deadlock";
	else
		cout<<"deadlock";
	
  	//system("chmod 777 a.txt");
	//system("dot -Tpng test.txt -o diag.png");
	//system("dot -Tpng a.txt -o dia.png");
	// cout<<"Process Complete !! ";
	return 0;
}
