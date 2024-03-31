#include<bits/stdc++.h>
using namespace std;

class user_data{

    private:
        string username;
        string password;

    public:
        user_data(string name, string pass){
            username = name;
            password = pass;
        }

        string get_username(){
            return username;
        }

        string get_password(){
            return password;
        }

};

class user_management{

    private:
        vector<user_data> users;

    public:
        
        void register_user(){

            string name, pass;

            cout<<"\n\tENTER USERNAME :";
            cin>>name;
            cout<<"\n\tENTER PASSWORD :";
            cin>>pass;

            user_data new_user(name,pass);
            users.push_back(new_user);

            cout<<endl;
            cout<<"\t*** REGISTER SUCCESSFULLY ***"<<endl;
        }

        void login_user(){

            string name , pass;

            cout<<"\n\tENTER USERNAME :";
            cin>>name;
            cout<<"\n\tENTER PASSWORD :";
            cin>>pass;

            for(int i=0; i<users.size(); i++){

                if(users[i].get_username() == name && users[i].get_password() == pass){
                    cout<<endl;
                    cout<<"\t*** LOGIN SUCCESSFULLY ***"<<endl;
                    return;
                }
            }
            cout<<endl;
            cout<<"\tINVALID USERNAME OR PASSWORD !"<<endl;
        }

        void show_user(){

            cout<<endl;
            cout<<"\tREGISTERED USER LIST :"<<endl;

            for(int i=0; i<users.size(); i++){

                cout<<"\t";
                cout<<i+1<<"."<<users[i].get_username();
                cout<<endl;                   
            }
        }

        void search_user(){

            string name;
            cout<<"\n\tENTER USERNAME TO SEARCH :";
            cin>>name;

            for(int i=0; i<users.size(); i++){

                if(users[i].get_username() == name){
                    cout<<endl;
                    cout<<"\t*** USER FOUND ***";
                    return;
                }
            }
            cout<<"\n\t*** USER NOT FOUND ***";
        }

        void delete_user(){
            string name;
            cout<<"\n\tENTER USERNAME TO DELETE :";
            cin>>name;

            for(int i=0; i<users.size(); i++){

                if(users[i].get_username() == name){
                    users.erase(users.begin()+i);
                    cout<<"\n\t*** USER DELETED ***";
                    return;
                }
            }
        }

};

int main(){

    user_management um;

    int op;
    char choice;
    do{

        cout<<endl;
        cout<<"\t---- LOGIN MANAGEMENT SYSTEM ----"<<endl;
        cout<<endl;
        cout<<"\t1.REGISTER USER"<<endl;
        cout<<"\t2.LOGIN USER"<<endl;
        cout<<"\t3.SHOW USER LIST"<<endl;
        cout<<"\t4.SEARCH USER"<<endl;
        cout<<"\t5.DELETE USER"<<endl;
        cout<<endl;
        
        cout<<"\tENTER YOUR CHOICE : ";
        cin>>op;

        switch(op){

              case 1:
                um.register_user();
                break;

              case 2:
                um.login_user();
                break;

              case 3:
                um.show_user();
                break;

              case 4:
                um.search_user();
                break;

              case 5:
                um.delete_user();
                break;

              default:
                cout<<"\tINVALID OPTION !"<<endl;
                break;

        }

        cout<<"\n\tDO YOU WANT TO CONTINUE (YES/NO) :";
        cin>>choice;

    }while(choice == 'Y' || choice == 'y');

    return 0;
}