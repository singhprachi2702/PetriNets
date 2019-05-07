using namespace std;
# include <vector>
# include <set>
# include <iostream>

int main()
{
	int no_of_places=0,no_of_trans=0,no_of_input=0,no_of_output=0,x;
	cout<<"Enter number of transitions : ";
	cin>>no_of_trans;
	vector< vector<int> > equations;
	cout<<"Enter number of places : ";
	cin>>no_of_places;
	vector< vector<int> > iotransitioni;
	vector< vector<int> > iotransitiono;

	for(int i=0;i<no_of_trans;i++)
	{
		cout<<"transition "<<i+1<<"\n";

		cout<<"number of input places : ";
		cin>>no_of_input;

		vector<int> input;
		for(int j=0;j<no_of_input;j++)
		{
			cin>>x;
			input.push_back(x);
		}
		iotransitioni.push_back(input);

		cout<<"number of output places : ";
		cin>>no_of_output;

		vector<int> output;
		for(int k=0;k<no_of_output;k++)
		{
			cin>>x;
			output.push_back(x);
		}

		iotransitiono.push_back(output);	
	}

    cout<<"\n First Checkpoint \n";

    for(int j=0;j<iotransitiono.size();j++)
    {
    	for(int k=0;k<iotransitiono[j].size();k++)
    	{
    		
    		vector<int> x;
    		x.push_back(-1);
    		x.push_back(iotransitiono[j][k]);
    		for(int l=0;l<iotransitioni[j].size();l++)
    		{
    			x.push_back(1);
    			x.push_back(iotransitioni[j][l]);
    		}
    		equations.push_back(x);
    	}
    }

    int num;

    cout<<"Enter the number of places having token : ";
    cin>>num;

    set<int> s;
    for(int i=0;i<num;i++)
    {
    	cin>>num;
    	s.insert(num);
    }


    for(int i=0;i<equations.size();i++)
    {
    	int sum=0;
    	for(int j=0;j<equations[i].size();j++)
    	{
    		if(!(j%2==0))
    		{
    			if(s.find(equations[i][j])!=s.end())
    			{
    				sum=sum+equations[i][j-1];
    			}
    		}
    	}
    	if(sum<0)
    	{
    		cout<<"Siphon Present";
    		return 0;
    	}
    }
    for (int i = 0; i < equations.size(); i++) { 
        for (int j = 0; j <equations[i].size(); j++) 
            cout << equations[i][j] << " "; 
        cout << endl; 
    } 

    cout<<"Siphon not Present";

   return 0;
}