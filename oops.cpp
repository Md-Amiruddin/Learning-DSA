#include<bits/stdc++.h>
using namespace std;

class student{
    
    string mName;  //private member variables
    int mRoll;
    
    public:

    /**
     * copy constructor, a default copy constructor is always provided if not defined but can also be defined explicitly like here.
     * A copy constructor copies the values of the member variables to a newly defined object of the same class if called.
    */
    student(student &a){    
        cout<<"Copy Constructor Called"<<endl; 
        mName = a.mName;
        mRoll = a.mRoll;
    }

    student(){    //public default constructor
        cout<<"Default Constructor"<<endl;
    }

    student(string s){   //public parameterized constructor
        mName=s;
    }

    void setName(string s){   //public member methods
        mName = s;
    }

    string getName(){
        return mName;
    }

    void setRoll(int roll){
        mRoll = roll;
    }

    int getRoll(){
        return mRoll;
    }

    bool operator == (student &a){                     //operator overloading
        if(mName==a.mName && mRoll==a.mRoll)
        return true;
        else
        return false;
    }

    ~student(){            //Destructor
        cout<<"Destructor called"<<endl;
    }

};

int main()
{
    student a("Urvi");
    a.setRoll(5);
    cout<<a.getName()<<endl;
    cout<<"Roll no.: "<<a.getRoll()<<endl;
    
    student b = a;   // or we can also write student b(a);

    if(b==a)                 //comparison using operator overloading
    cout<<"Same"<<endl;
    else
    cout<<"not same"<<endl;

    return 0;
}