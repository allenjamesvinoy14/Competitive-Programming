#include<bits/stdc++.h>
using namespace std;

class husband;

class wife{
    private:
        long salary = 100;

    public:
        void display(husband &h);
};

class husband
{
	private:
  	    long salary = 100;
    public: 
  	    friend void wife::display(husband &h);
};

void wife::display(husband &h){
    cout<<"Total Salary of Family is: "<<h.salary+salary<<endl;
}
int main(){
    wife wifey;
    husband hubby;
    wifey.display(hubby);
    return 0;
}