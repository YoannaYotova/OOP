#include<iostream>
#include"Guest.h"
#include"User.h"
#include"PowerUser.h"
#include"VIP.h"
#include"Admin.h"
using namespace std;


int main()
{
	User a("23.232345.3","ponny","123456","facebook");
	PowerUser b("23.113498.4", "yonny", "135775", "instagram", 5);
	VIP c("23.112345.3", "bonny", "123321", "facebook");
	Admin d;

	a.print(); //Print User a with old password
	cout << endl;
	a.changePassword("123456", "654321");
	a.print(); //Print User a with new password
	cout << endl << endl;


	b.print();
	//Username of User a is not the same as the username of PowerUser b
	//so the reputation is plus one
	b.reputationPlusOne(a);
	b.print(); 
	cout << endl;

	c.print();
	cout << endl;
	c.setTitle("instagram");
	c.print();
	cout << endl<<endl;
    
	d.changeAnotherUsername(a, "lady"); //Changing the username of User a
	a.print();
	cout << endl;

	system("pause");
}