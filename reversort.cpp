#include <iostream>
#include <math.h>

using namespace std;

int reversort(int length, int list[])
{
    int cost;
    for(int i=0; i<length-1; i++)
    {
        int minimum = length+1;
        int position;
        for(int j=i; j<length; j++)
        {
            if(minimum > list[j])
            {
                minimum = list[j];
                position = j;
            }
        }
        
        for(int a=i; a<ceil((position+i+1)/2.f); a++)
        {
            int aux = list[a];
            list[a] = list[position-a+i];
            list[position-a+i] = aux;
        }
        
        cost += position - i + 1;
    }
    return cost;
}

int main()
{
    int cases;
    cin>>cases;
    
    for(int c=0; c<cases; c++)
    {
        int length;
        cin>>length;
        
        int list[length];
        for(int l=0; l<length; l++)
        {
            cin>>list[l];
        }
        
        int cost = reversort(length, list);
        
        cout<<"Case #"<<c+1<<": "<<cost;
        if(c<cases-1) cout<<endl;
    }
}
