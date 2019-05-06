#include <iostream>
#include <vector>
#include <stack>
#include <ctype.h>
#include <string>
using namespace std;

int main()
{
	string s;
	vector <int> v;
	vector<char> c;
	int pos=-1;
	int countP=0,countT=0;
	cin>>s;
	int i=1;
	int j=1;
	string x;
	int res;
	int len = s.length();
	c.push_back(s[0]);
	bool f =false;
	while(j<=len)
	{
		if(s[j]=='T'||s[j]=='P'||s[j]=='t'||s[j]=='p'||(f&&(s[j]==')'))||(f&&(s[j]=='(')))
		{
			c.push_back(s[j]);
			//cout<<"i "<<i<<" j "<<j<<"\n";
			x=s.substr(i,j-1);
			//cout<<x<<"\n";
			res = stoi(x);
			v.push_back(res);
			if(f)
			{
				v.push_back(-11);
				f = false;
			}
			i=j+1;
			if(s[j]=='('||s[j]==')')
				f = false;
		}
		if(f)
		{
			v.push_back(-11);
			f = false;
		}
		if(s[j]=='(')
		{
			c.push_back(s[j]);
			//v.push_back(-11);
			f = true;
		}
		if(s[j]==')')
		{
			c.push_back(s[j]);
			//v.push_back(-11);
			f = true;
		}
		j++;

	}
	//cout<<"i :"<<i<<" j : "<<j;
  	x=s.substr(i,j-1);
	res = stoi(x);
	v.push_back(res);

	cout<<"values :";
	for (auto i = v.begin(); i != v.end(); ++i) 
        cout << *i << " "; 
	
	cout<<"names : ";
	for (auto i = c.begin(); i != c.end(); ++i)
	{ 
        cout << *i << " "; 
		if(*i=='p'||*i=='P')
			countP++;	
		if(*i=='t'||*i=='T')
			countT++;
	}
	cout<<"Places: "<<countP<<"\n";
	cout<<"Transitions :"<<countT<<"\n";
	return 0;
}

