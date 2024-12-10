#include<iostream>
#include<string.h>
using namespace std; 

class Graph
{
    char Vnames[10][10];
    int cost[10][10],n;
public:
    Graph();
    void creat_graph();
    void display();
    int Position(char[]);
    void kru();
    void prims();
};
Graph::Graph()
{
for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
     {
         cost[i][j]=999;
     }
}
void Graph::creat_graph()
{
    char ans,Start[10],End[10];
    int wt,i,j;
    cout<<"Enter number of nodes";
    cin>>n;
    cout<<"\n Enter vertex name:";
    for(i=0;i<n;i++)
              cin>>Vnames[i];
    do
    {
            cout<<"\nEnter Start and end point of edge";
            cin>>Start>>End;
            cout<<"Enter weight";
            cin>>wt;
            i=Position(Start);
            j=Position(End);
            cost[j][i]=cost[i][j]=wt;
            cout<<"\nMore Edges ";
            cin>>ans;
    }while(ans=='y' || ans=='Y');
}

void Graph::display()
{
    int i,j;
    for(i=0;i<n;i++)
    {
         cout<<"\n";
         for(j=0;j<n;j++)
             cout<<cost[i][j]<<"\t";
    }
}

int Graph::Position(char key[10])
{
        int i;
        for(i=0;i<n;i++)
            if(strcmp(Vnames[i],key)==0)
                break;
        return i;
}

void Graph::kru()
{
int i,j,v[10],x,y,Total_cost=0,min,gr=1,flag=0,temp,d;

for(i=0;i<n;i++)
     v[i]=0;

cout<<"\nnode1\tnode2\tWeight";

while(flag==0)
{
         min=999;
         for(i=0;i<n;i++)
         {
             for(j=0;j<n;j++)
             {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    x=i;
                    y=j;
                }
            }
         }
        if(v[x]==0 && v[y]==0)
        {
            v[x]=gr;
            v[y]=gr;
            gr++;
            cost[x][y]=cost[y][x]=999;
            Total_cost=Total_cost+min;
            cout<<"\n"<<x<<"\t"<<y<<"\t"<<min;
        }
        else if(v[x]!=0 && v[y]==0)
        {
            v[y]=v[x];
            cost[x][y]=cost[y][x]=999;
            Total_cost=Total_cost+min;
            cout<<"\n"<<x<<"\t"<<y<<"\t"<<min;
        }//end else
        else if(v[x]==0 && v[y]!=0)
        {
            v[x]=v[y];
            cost[x][y]=cost[y][x]=999;
            Total_cost=Total_cost+min;
            cout<<"\n"<<x<<"\t"<<y<<"\t"<<min;
        }//end else
        else
        {
            if(v[x]!=v[y])
            {
                d=v[x];
                for(i=0;i<n;i++)
                {
                    if(v[i]==d)
                    v[i]=v[y];
                }//end for

            cost[x][y]=cost[y][x]=999;
            Total_cost=Total_cost+min;
            cout<<"\n"<<x<<"\t"<<y<<"\t"<<min;
            }
            else
            cost[x][y]=cost[y][x]=999;
        }
       temp=v[0];
       flag=1;
       for(i=0;i<n;i++)
       {
           if(temp!=v[i])
          {
            flag=0;
            break;
          }
           else
              continue;
      }
}
cout<<"\nTotal cost of tree="<<Total_cost;
}

void Graph::prims()
{
int cnt=1,i,j,x,y,Total_cost=0,min,v[10]={0};
char start[10];
cout<<"\nStarting node=";
cin>>start;
x=Position(start);
v[x]=1;
while(cnt<n)
{
min=999;
for(i=0;i<n;i++)
{
     if(v[i]==1)
     {
         for(j=0;j<n;j++)
         {
              if(cost[i][j]<min && v[j]==0)
              {
                 min=cost[i][j];
                 x=i;
                 y=j;
              }
         }
     }
}
cout<<"\n"<<Vnames[x]<<"\t"<<Vnames[y]<<"\t"<<min;
Total_cost=Total_cost+min;
cost[x][y]=cost[y][x]=999;
v[y]=1;
cnt++;
}
cout<<"\nTotal cost=>"<<Total_cost;
}


int main()
{
Graph ob;

int ch;
    while(1)
    {
        cout<<"\n***************MENU****************\n";
        cout<<"1.Kruskal algorithm\n2.Prims algorithm\n3.Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:ob.creat_graph();
                    ob.display();
                    ob.kru();

                    break;
            case 2: ob.creat_graph();
                    ob.display();
                    ob.prims();
                    break;
            case 3: exit(0);
        }
    }
return 0;


}









