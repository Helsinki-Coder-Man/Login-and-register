#include <iostream>
#include <string>
#include<fstream>
class User
{
  std::string Username;
  std::string Password;
  std::string FullLog;
  std::string Hash = Username + Password;

public:
    
    
    void Register()
    {
        int p, u;
        bool can_register = false;
        std::cout << "\n===REGISTER===";
        std::ofstream Set_Database;

        Set_Database.open("UsrDataBase.txt",std::ios::app);
      
    u:;
        std::cout << "\nEnter your new username: "; std::cin >> Username;
        if (Username.length() > 20) { std::cout << " Username is too long, must be below 20 characters."; goto u; }
        else
        {
            can_register = true;
        }
        if (can_register == true) {
            p:
            std::cout << "\n\nEnter your new password password: "; std::cin>>Password;
            if (Password.length() > 15) { std::cout << " Password is too long, must be 15 characters or below."; goto p; } else
            {
                if (Set_Database.is_open()) 
                {
                    Set_Database << Username << Password;
                }
            }
        }
        Set_Database.close();
    }

   void Login()
   {
       int a;
       std::cout << "\n===LOGIN===\n\n";
   a:;
       std::cout << "\nEnter your username: ";  std::cin >> Username;
  
       std::cout << "\nEnter your password: "; std::cin>> Password;
       std::ifstream Read_Database;
       Read_Database.open("UsrDataBase.txt", std::ios::in);
       if(Read_Database.is_open())
       {
           while (std::getline(Read_Database, FullLog));
           if (Hash == FullLog || FullLog.find(Username+Password) != std::string::npos) { std::cout << "\nLogin successful"; }
           else {std::cout<< "\nFailed"; }
       }
       Read_Database.close();
   }

};


int main()
{
    User usr;
    char input;
    std::cout << "Do you have an account?\ny/n : ";
    std::cin >> input;
    if(input == 'y')
    {
        usr.Login();
    } else if(input == 'n')
    {
        usr.Register();
    }

    
}
