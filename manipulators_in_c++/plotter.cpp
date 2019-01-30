#include<iostream>
#include<iomanip>
using namespace std;
#include<math.h>

const float pi = (355/113); //most accurate value of pi in fraction form

float map_axis(int x)
{
    return ((pi / 20.5) * x); //mapping on x-axis i.e vertical line in this program
}

int map_graph(float y)
{
    return 30 * y; //mapping on y-axis i.e graph of sin(x) in this program
}

int main()
{
    int i;
    cout<<endl<<endl; //inital spacing for nice ui
    for(i = 0; i < 22; i++) //positive half of sine curve
    {
        cout<<setw(50)<<setfill(' ')<<'|';
        cout<<setw(map_graph(sin(map_axis(i))))<<setfill('*')<<'*';
        cout<<endl;
    }

    for(i; i < 44; i++) //negative half of sine curve
    {
        if(i != 43)
        {
            cout<<setw(50 - abs(map_graph(sin(map_axis(i)))))<<setfill(' ')<<'*';
            cout<<setw(abs(map_graph(sin(map_axis(i)))))<<setfill('*')<<'|';
            cout<<endl;
        }
        else
        {
            cout<<setw(49 - abs(map_graph(sin(map_axis(i)))))<<setfill(' ')<<'*'; //49 instead of 50 to compensate for mapping decimal
            cout<<setw(abs(map_graph(sin(map_axis(i)))))<<setfill('*')<<'|';
            cout<<endl;
        }
        
    }
    cout<<endl;
    return 0;
}