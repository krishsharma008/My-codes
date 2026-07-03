# include <iostream>
# include<fstream>
# include<string>
# include <map>
class phonebook{
    public:
    std::map<std::string,std::string>contacts;

 void addcontacts(){
    std::string name;
    std::string number;
    std::cout<<"Enter the name:";     
    std::getline(std::cin,name);
    std::cout<<"Enter the number:";
    std::cin>>number;
    contacts[name]=number;
    std::fstream my_add;
    my_add.open("phonebook.txt", std::ios::app);
    if (my_add.fail()){
        std::cout<<"file not found"<<std::endl;
        return;
    }
    my_add<<name<<" "<<number<<" "<<std::endl;
    my_add.close();    }


        /* code */

    

           };
int main(){
    phonebook ph;
    ph.addcontacts();
    return 0;
}