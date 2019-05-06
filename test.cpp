# include<iostream>
# include <string>
using namespace std;

int main()
{
    string s ="t1t2";
    string x= s.substr(1,1);
    int re;
    re = stoi(x);
    cout<<re;
    return 0;
}
