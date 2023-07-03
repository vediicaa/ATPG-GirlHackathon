#include<bits/stdc++.h>
using namespace std;

map<string,bool>mp;
map<string,bool>mp1;
queue<vector<int>>pq;
string Fault_at;
string Fault_Type;
int flag=0;
void fillqueue()
{
    pq.push({0,0,0,0});
    pq.push({0,0,0,1});
    pq.push({0,0,1,0});
    pq.push({0,0,1,1});
    pq.push({0,1,0,0});
    pq.push({0,1,0,1});
    pq.push({0,1,1,0});
    pq.push({0,1,1,1});
    pq.push({1,0,0,0});
    pq.push({1,0,0,1});
    pq.push({1,0,1,0});
    pq.push({1,0,1,1});
    pq.push({1,1,0,0});
    pq.push({1,1,0,1});
    pq.push({1,1,1,0});
    pq.push({1,1,1,1});
}
void combinations()
{
    vector<int>v=pq.front();
    pq.pop();
    mp["A"]=v[0];
    mp["B"]=v[1];
    mp["C"]=v[2];
    mp["D"]=v[3];
    mp1["A"]=v[0];
    mp1["B"]=v[1];
    mp1["C"]=v[2];
    mp1["D"]=v[3];
}

bool isOperator(string str)
{
   return str=="&" || str=="|" || str=="^" || str=="~";
}

char getOperator(string str)
{
    if(str=="&")
    return '&';
    if(str=="^")
    return '^';
    if(str=="|")
    return '|';
    if(str=="~")
    return '~';
}
void evaluatingCircuit(string str)
{
    // word variable to store word
    string word;
    // making a string stream
    stringstream iss(str);
    vector<string>v;
 
    // Read and pushing each token in the vector
    while (iss >> word)
    {
        v.push_back(word);
    }

    int n=v.size();
    for(int i=0;i<n;i++)
    {
        if(isOperator(v[i]))
        {
            char ch=getOperator(v[i]);
            if(ch=='&')
            {
                mp[v[i+1]]=mp[v[i-1]] & mp[v[i+1]];
            }
             if(ch=='^')
            {
                mp[v[i+1]]=mp[v[i-1]] ^ mp[v[i+1]];
            }
            if(ch=='|')
            {
                mp[v[i+1]]=mp[v[i-1]] | mp[v[i+1]];
            }
            if(ch=='~')
            {
                mp[v[i+1]]= !mp[v[i+1]];
            }  
        }
      if(flag==1)
       {
          if(Fault_Type=="SA0")
           {
            mp[Fault_at]=0;
            mp1[Fault_at]=0;
           }
          else
          {
            mp[Fault_at]=1;
            mp1[Fault_at]=1;
          }
       }
    }
      
      mp[v[0]]=mp[v[n-1]];
      mp1[v[0]]=mp[v[n-1]];

      if(flag==1)
       {
          if(Fault_Type=="SA0")
           {
            mp[Fault_at]=0;
            mp1[Fault_at]=0;
           }
          else
          {
            mp[Fault_at]=1;
            mp1[Fault_at]=1;
          }
       }


    for(int i=2;i<n;i++)
    {
      if(!isOperator(v[i]))
      {
        mp[v[i]]=mp1[v[i]];
      }
    }
    
}

void extractingLine()
{
    ifstream myfile;
   myfile.open("Input.txt");
   string myline;
     if ( myfile.is_open() )
      {
        while ( true ) 
        { 
            getline (myfile, myline);
            evaluatingCircuit(myline);
            if(myfile.eof()) break;
            //cout << myline << '\n';
        }
        myfile.close();
     }
     else
      {
          std::cout << "Couldn't open file\n";
      }
       myfile.clear();
}
int main ()
{
  cout<<"Make sure to write your circuit in INPUT.txt file\n";
    fillqueue();
      int nonfaultres=-1;
      cout<<"Enter the Fault Node location:\n";
      cin>>Fault_at;
      cout<<"Enter the Fault Type:\n ";
      cin>>Fault_Type;


  //now running the code after finding the faults
  int faultres=nonfaultres;
  while(!pq.empty() && nonfaultres==faultres)
      {
        combinations();
        flag=0;

        //finding the value of nonfaultres
       extractingLine();
       nonfaultres=mp["Z"];

       flag=1;
       if(Fault_Type=="SA0")
         mp[Fault_at]=0;
       else
         mp[Fault_at]=1;

       //finding the value of faultres
       extractingLine();
       faultres=mp["Z"];
      }
      cout<<"Check the Output.txt file for the result\n";
      vector<int>v;
        v.push_back(mp["A"]);
        v.push_back(mp["B"]);
        v.push_back(mp["C"]);
        v.push_back(mp["D"]);

      ofstream outfile("Output.txt");
      if(outfile.fail())
      {
        cout<<"File Error\n";
      }
      else
      {
        if(faultres==nonfaultres)
        {
          outfile<<"NO test vector can be generated for the given fault\n";
        }
        else{
        outfile<<"[A, B, C, D] = [";
        int i;
        for(i=0;i<v.size()-1;i++)
        {
            outfile<<v[i]<<", ";
        }
        outfile<<v[i]<<"], Z="<<faultres<<"\n";
      }
      }
   return 0;
}