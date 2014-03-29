


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "PasswordManager.h"

using namespace std;

int main()
{
	PasswordManager pm;

	char choice;
	string newpassword;
	string origPass = "ABCabc123";

	ifstream fin;
	fin.open("Passwordfile.txt");
	if(!fin)
		pm.setNewPassword(origPass);


	do{
		cout << "Password Utilities:" << endl
			 << "a. Change Password" << endl
			 << "b. Validate Password" << endl
			 << "c. Quit" << endl
			 << "Enter your choice: ";
		cin >> choice;
	switch (choice)
	{


	  case 'a' :
		  	  cout << "New password must:" << endl
		  	  	   << " - be at least 6 characters long" << endl
		  	  	   << " - contain at least 1 uppercase letter" << endl
		  	  	   << " - contain at least 1 lowercase letter" << endl
		  	  	   << " - contain at least 1 digit" << endl
		  	  	   << "Enter new password: ";
		  	  cin >> newpassword;
		  	  if(pm.setNewPassword(newpassword) == true)
		  	  {
		  	  	  cout << "Password changed" << endl << endl;
		  	  }

		  	  else
		  		  cout << "Invalid password entered" << endl;

		  break;

	  case 'b' :
		  	  cout << "Enter your password" << endl;
		  	  cin >> newpassword;

		  	  if(pm.validatePassword(newpassword) == true)
		  		  cout << "Valid password entered" << endl;
		  	  else
		  		  cout << "Invalid password entered" << endl;

		  break;

	  case 'c' :
		  cout << "Exiting Application!" << endl << endl;
		     return 0;
	}

	}while(choice != 'c');

}

