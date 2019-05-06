# include <iostream>
# include <stack>
# include <string>
# include <vector>

using namespace std;

void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 

int main()
{
    string s;
    stack <int> st;
    stack <int> st1;
    int number_of_places=0,number_of_transitions=0;
    int temp=0;
    int i=0;
    vector <int> values;
    vector <char> node;
    cout<<"Input String: ";
    getline(cin,s);
    int len = s.length();
    // cout<<"\nLength of Input is : "<<len<<"\n";
    for(i=0;i<len;)
    {
        temp = 0;  
        // cout<<"\nCurrent value of s[i] is : "<<s[i]; 
        

        if(s[i]=='t'||s[i]=='T'||s[i]=='p'||s[i]=='P')
        {
            // cout<<"inside if ";
            node.push_back(s[i]);
            // cout<<" when node "<<i<<" present :"<<s[i]<<"\n";
            i++;
        }
        else if(s[i]=='(')
        {
            // cout<<"inside bracket";
            st1.push(node.size());
            st.push(node.size());
            node.push_back(s[i]);
            values.push_back(-1);
            // cout<<"currently size of node is "<<node.size()<<"\n";
            
            i++;
            // cout<<"\nStack is: ";
            // showstack(st);
        }
        else if(s[i]==')')
        {
            // cout<<"inside bracket";
            node.push_back(s[i]);
            // values.push_back(-2);
            int a = st.top();
            int b = st1.top();
            st1.pop();
            // cout<<"value f a is : "<<a<<"\n";
            st.pop();
            values[a]= node.size()-1 ;
            values.push_back(b);
            i++;
        }
        else
        {
            temp=0;
            // cout<<"inside else ";
            while(s[i]!='t'&&s[i]!='T'&&s[i]!='p'&&s[i]!='P'&&i<len&&s[i]!='('&&s[i]!=')')
            {
                // cout<<"inside while value of s[i] is"<<s[i]<<" value of i is "<<i<<"\n";
                temp = temp*10 +(s[i]-48);
                // cout<<"temp : "<<temp<<"\n";
                i++;
            }
            values.push_back(temp);
            // cout<<" when value "<<i<<" is present :"<<temp<<"\n";
        }
        
    }
    /*cout<<"Values: ";
    for(int j=0;j<values.size();j++)
        cout<<values[j]<<" "<<node[j]<<"\n";
    cout<<"\nNodes :";
    for(int j=0;j<node.size();j++)
    {
        cout<<node[j]<<" ";
    }*/

    for(int i = 0 ; i< node.size();i++)
    {
        if(node[i]=='t')
        {
            number_of_transitions++;
        }
        if(node[i]=='p')
        {
            number_of_places++;
        }
    }

    // cout<<"\nNumber of Places : "<<number_of_places;
    // cout<<"\nNumber of Transitions : "<<number_of_transitions;
    int input[number_of_transitions][number_of_places];

    for(int i = 0; i<number_of_transitions;i++)
    {
        for(int j=0;j<number_of_places;j++)
        {
            input[i][j]=0;
        }
    }
    // cout<<"\nNow Entering the Loop \n";
    for(int i = 0; i< node.size();i++)
    {
        if(node[i]=='t')
        {
            if(node[i-1]=='p')
            {
                input[values[i]][values[i-1]]=-1;
            }
            else
            {
                input[values[i]][values[i-2]]=-1;
                int x= values[i-1];
                input[values[i]][values[x-2]]=-1;
            }
            
            if(node[i+1]=='p') {
                input[values[i]][values[i+1]]=1;
            }
            else
            {
                input[values[i]][values[i+2]]=1;
                // cout<<"\ninput["<<values[i]<<"]["<<values[i+2]<<"]";
                int x= values[i+1];
                input[values[i]][values[x+2]]=1;
                // cout<<"\ninput["<<values[i]<<"]["<<values[x+2]<<"]";
            }
        }
    }

    for(int i = 0; i<number_of_transitions;i++)
    {
        cout<<"\n";
        for(int j=0;j<number_of_places;j++)
        {
            cout<<input[i][j]<<" ";
        }
    }
    
    return 0;
}

