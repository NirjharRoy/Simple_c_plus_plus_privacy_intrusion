#include <iostream>
using namespace std;


 class Private_Member
{


	       int num_private;




	public:
	       void incrVal()
	       {
	       	if (num_private<10)
	       	    num_private++;
	       	else
	       	    cout<<"Can't increment beyond 10. Sorry!!!!";
	       }
			Private_Member(){num_private=0;}
			int getVal(){return num_private;}
};


class Intruder
{
	public:
	    int num_public;


	    void incrVal()
	    {


	       	num_public++;
	       	cout <<"value incremented ";


	    }
	    Intruder(){num_public=0;}
		int getVal(){return num_public;}

};







int main() {
	// your code goes here
	//Private_Member *pm= new Private_Member;
	//Private_Member2 *pm2= reinterpret_cast<Private_Member*>(pm);

	Private_Member *private_Member= new  Private_Member ;
	for(int i=0; i<15;i++)
	{
		private_Member->incrVal();
	    cout <<"Current value from private_Member.getVal() "<<private_Member->getVal()<<"\n";
	}

	//reinterpret_cast<Intruder*>(private_Member)->incrVal();
	reinterpret_cast<Intruder*>(private_Member)->num_public=25;
	cout <<"Current value from private_Member.getVal() after suspicious_activity "<<private_Member->getVal()<<"\n";


	return 0;
}
