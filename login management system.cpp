#include<iostream>
#include <string>
#include <vector>
using namespace std;
class user{
      private:
      string username,password;
      public:
      user(string name,string pass){
            username=name;
            password=pass;
      }string getusername(){
            return username;
      }
      string getpassword(){
            return password;
      }
};
class usermanager{
      public:
            vector <user> users;//create object of vector
            public:
      void registeruser(){
            string username,password;
            cout<<"Enter username: ";
            cin>>username;
            cout<<"Enter the password: ";
            cin>>password;
            user newuser(username,password);
            users.push_back(newuser);
            cout<<"\tUser Registered Successfully..."<<endl;}
      bool login(string name,string pass){
            for(int i=0;i<users.size();i++){
                  if(users[i].getusername()==name && (users[i].getpassword()==pass)){
                  cout<<"\tLogin Successfully"<<endl;
                  return true;}
                  else {
                  cout<<"Invalid username and password"<<endl;
                  return false;
                  }
            }
            }
           void usershow(){
            cout<<"\t\tUser List..."<<endl;
            for(int i=0;i<users.size();i++){
                  cout<<"\t\t"<<users[i].getusername()<<endl;
            }
           }
           int searchuser(string username){
            for(int i=0;i<users.size();i++){
                  if(users[i].getusername()==username){
                        cout<<"\t\tUser name found"<<endl;
                        return 0;}
                  }
                  cout<<"\t\tUser not found "<<endl;
           }
           int deleteuser(string username){
            for(int i=0;i<users.size();i++){
                  if(users[i].getusername()==username){
                        users.erase(users.begin()+i);
                        cout<<"\t\tUser removed sucessfully "<<endl;
                        return 0;
                  }
            }
            cout<<"User not available to be removed \n";
      }
};
int main() {
      // your code here
      usermanager usermanage;
      int op;
      char ch;
      do{
            system("cls");
      cout<<"\n1.Register user "<<endl;
      cout<<"2.Login"<<endl;
      cout<<"3.Show user list "<<endl;
      cout<<"4.Search user "<<endl;
      cout<<"5.Delete user "<<endl;
      cout<<"6.Exit"<<endl;
      cout<<"Enter your choice"<<endl;
      cin>>op;
      switch(op){
            case 1:{
            usermanage.registeruser();
            break;}
      
            case 2:{
            string username,password;
            cout<<"Enter username :";
            cin>>username;
            cout<<"Enter the password :";
            cin>>password;
            usermanage.login(username,password);
            break;}
            case 3:
            {
                  usermanage.usershow();
                  break;
            }
            case 4:
            {
                  string username;
                  cout<<"Enter the user to search: ";
                  cin>>username;
                  usermanage.searchuser(username);
                  break;
            }
            case 5:{
                  string username;
                  cout<<"Enter the user to delete :";
                  cin>>username;
                  usermanage.deleteuser(username);
                  break;
            }
            case 6:
            {
                  exit(0);
            }
      }
            cout<<"Do you want to continue [yes/no]";
            cin>>ch;
      }while(ch=='y'||ch=='Y');
       return 0;
}