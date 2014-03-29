#include <string>
using namespace std;
class PasswordManager
{
private:
        string encrypt(string);
        bool verifyPassword(string);
        
public:
       bool setNewPassword(string);
       bool validatePassword(string);
       string getEncryptedPassword();
       void setEncryptedPassword(string);
};
