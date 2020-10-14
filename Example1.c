#include <iostream>

using namespace std;


class Student{
    int id;
    string name;
    string email;
    int contact_no;
    public:
    Student(int id, string name, string email, int contact_no)
    {
        this->id = id;
        this->name = name;
        this->email = email;
        this->contact_no = contact_no;
    }
    int getId()
    {
        return this->id;
    }
    string getName()
    {
        return this->name;
    }
    string getEmail()
    {
        return this->email;
    }
    int getContact()
    {
        return this->contact_no;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    void setContact(int contact_no)
    {
        this->contact_no = contact_no;
    }
    void dislplay()
    {
        cout <<"ID: "<<this->id<<"\nName: "<<this->name<<"\nEmail: "<<this->email<<"\nContact No:"<<this->contact_no;
    }
};



int main()
{
    
    
    Student st1(13, "Arslan","arslan@gmali.com",03001111111);
    Student st2(14, "Hassan","hassan@gmali.com",03002222222);
    Student st3(13, "Ahmad","ahmad@gmali.com",03003333333);
    st1.dislplay();
    st2.dislplay();
    st3.dislplay();

    return 0;
}
