

#include <iostream>

using namespace std;


class Counter{
    
    public:
    int counter;
    Counter(int counter)
    {
        this->counter = counter;
    }
    int getCounter()
    {
        return this->counter;
    }
    
    void setCounter(int counter)
    {
        this->counter = counter;
    }
    void increment()
    {
        counter++;
    }
    void decreament()
    {
        counter--;
    }
    
};



int main()
{
    
    Counter c1(200);
    c1.increment();
    c1.increment();
    cout<<"Value Before Increment 200 Value Affter Increment "<<c1.counter;
    c1.decreament();
    c1.decreament();
    cout<<"\nValue Before decreament 202 Value Affter decreament "<<c1.counter;
    return 0;
}
