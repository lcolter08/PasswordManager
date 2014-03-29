#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "PasswordManager.h"

using namespace std;

string PasswordManager::encrypt(string password)
{
       string encryptPass;
       for(int i = 0; i < password.length(); i++)
             encryptPass.append(1,password[i] ^ '2'); //a = password[i] ^ '2';
       return encryptPass;
}

bool PasswordManager::verifyPassword(string password)
{
     int passSize = 0;
     int passUpper = 0;
     int passLower = 0;
     int passDigit = 0;

	 bool passFail = false;

           if( password.size() >= 6)
           {
        	   passSize++;
           }

     for(int i = 0; i < password.length(); i++)
     {

           if(isupper(password[i]))
           {
        	   passUpper++;
           }
           if(islower(password[i]))
           {
        	   passLower++;
           }
           if(isdigit(password[i]))
           {
        	   passDigit++;
           }
     }

     if(passSize >= 1 && passUpper >= 1  && passLower >= 1  && passDigit >= 1)
           {
               passFail = true;
           }

     return passFail;
}

void PasswordManager::setEncryptedPassword(string encryptedPass)
{
     ofstream fout;
     fout.open("Passwordfile.txt");
     fout << encryptedPass;
     fout.close();
}

string PasswordManager::getEncryptedPassword()
{
       string encryptedPass;
       ifstream fin;
       fin.open("Passwordfile.txt");
       fin >> encryptedPass;
       
       fin.close();
       return encryptedPass;
}

bool PasswordManager::setNewPassword(string password)
{
     bool passFail = false;

     if(verifyPassword(password) == true)
     {
         setEncryptedPassword(encrypt(password));
         passFail = true;
     }

     return passFail;
}

bool PasswordManager::validatePassword(string password)
{
     bool passFail= false;
     int count = 0;
     string newpass;
     string oldpass;
     
     oldpass = getEncryptedPassword();
     
     newpass = encrypt(password);

     for(int i = 0;i < newpass.length(); i++)
           if( newpass[i] == oldpass[i])
               count++;
     if(count >= newpass.length())
        	   passFail = true;
               
     return passFail;
}
