#include<bits/stdc++.h>
#include<math.h>
using namespace std;

class Time
{
    public:
    int hour, minute, second;

    Time(int h = 0, int m = 0, int s = 0) //constructor with default arguments
    {
        hour = h;
        minute = m;
        second = s;
    }

    ~Time() {} //trivial destructor

    void readTime(void);
    void displayTime(void) const;
    Time addTime(Time&);

    friend ostream& operator<<(ostream&, Time&);
    friend istream& operator>>(istream&, Time&);
    void operator++(int);
    Time operator-(Time&);
    bool operator!=(Time&);
};

void Time::readTime()
{
    cout<<"Enter hour, minute and second in order: ";
    cin>>hour>>minute>>second;
}

void Time::displayTime() const
{
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}

Time Time::addTime(Time& a)
{
    int h, m, s;
    s = second + a.second;
    m = minute + a.minute;
    h = hour + a.hour;
    
    if(s >= 60)
    {
        s -= 60;
        m += 1;
    }
    if(m >= 60)
    {
        m -= 60;
        h +=1;
    }

    Time newTime(h, m ,s);
    return newTime;
}

ostream& operator<<(ostream& output, Time& a)
{
    output<<a.hour<<":"<<a.minute<<":"<<a.second;
    return output;
}

istream& operator>>(istream& input, Time& a)
{
    input>>a.hour>>a.minute>>a.second;
    return input;
}

void Time::operator++(int dummy)
{
    second += 1;
}

Time Time::operator-(Time& a)
{
    int h, m, s, t1, t2;

    t1 = (hour * 3600) + (minute * 60) + second;
    t2 = (a.hour * 3600) + (a.minute * 60) + a.second;

    t1 = abs(t1 - t2);

    h = t1 / 3600;
    t1 = t1 % 3600;

    m = t1 / 60;
    t1 = t1 % 60;

    s = t1;

    Time newTime(h, m, s);
    return newTime;
}

bool Time::operator!=(Time& a)
{
    bool flag = true;
    if(hour == a.hour && minute == a.minute && second == a.second)
        flag = false;
    return flag;
}

int main()
{
    Time timer;
    timer.readTime();
    cout<<"The current time is: ";
    timer.displayTime();
    cout<<endl;

    Time temp;
    cout<<"Enter hour, minute and second in order: ";
    cin>>temp;
    cout<<"The current time is: "<<temp<<endl<<endl;

    bool test = timer != temp;
    cout<<"Result of comparison is: "<<test<<endl;
    cout<<endl;

    Time add = timer.addTime(temp);
    Time sub = timer - temp;

    cout<<"Time after addition is: "<<add<<endl;
    cout<<endl;

    cout<<"Time after subtraction is: "<<sub<<endl;
    cout<<endl;
    
    timer++;
    cout<<"Incremented time is: "<<timer<<endl;

    return 0;
}