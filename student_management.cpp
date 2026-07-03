#include <iostream>
#include <string>
#include<fstream>
#include<cstdio>
class student {
public:
    int roll_no ;
    std:: string name;
    std::string mobile_no;
    std::string dept;

    void addstudent() {
        std::string line;
        std::cout << "Enter roll no.:"<<std::endl;
        std::cin >> roll_no;
        std::fstream my_add;
        my_add.open("manager.txt",std::ios::in);
        if(!my_add.fail()) {
            while(std::getline(my_add,line)) { //for roll no.
                if(line==std::to_string(roll_no)) {
                    std::cout << "Student already have in record"<<std::endl;
                    return;
                }
                std::getline(my_add,line);//for name
                std::getline(my_add,line);//for mobile no.
                std::getline(my_add,line); // for department
            }
        }
        my_add.close();//Add student
        std::cin.ignore();
        std::cout << "Enter the name: " << std::endl;
        std::getline(std::cin,name);
        std::cout << "Enter the mobile no.:  " << std::endl;
        std::getline(std::cin,mobile_no);
        std::cout << "Enter the Department: " << std::endl;
        std::getline(std::cin,dept);
        my_add.open("manager.txt",std::ios::app);
        if(my_add.fail()) {
            std::cout << "File does not found " << std::endl;
            return;
        }
        my_add << roll_no << "\n"
               << name << "\n"
               << mobile_no << "\n"
               << dept << "\n";
        my_add.close();
        std::cout << "Student successfully added" << std::endl;
    }
    void displaystudent() {
        std::string line ;
        std::fstream my_add;
        my_add.open("manager.txt",std::ios::in);
        if(my_add.fail()) {
            std::cout << "File not founded" << std::endl;
            return;
        }
        while(std::getline(my_add,line)) {
            std::cout<<"•STUDENT INFORMATION•"<<std::endl;
            std::cout<<"===================="<<std::endl;
            std::cout <<"Roll no.:"<<line<<std::endl;
            std::getline(my_add,line);
            std::cout <<"Name:"<<line<<std::endl;// for name
            std::getline(my_add,line);
            std::cout <<"Mobile no.:"<<line<<std::endl; // for mobile no
            std::getline(my_add,line);
            std::cout <<"Department:"<<line<<std::endl;//for department
            std::cout<<"===================="<<std::endl;
        }
        my_add.close();
    }
    void searchstudent() {
        bool found = false;
        std::string line;
        std::cout << "Enter the roll no." <<std::endl;
        std::cin >> roll_no;
        std::fstream my_add("manager.txt",std::ios::in);
        if(my_add.fail()) {
            std::cout << "File not found" << std::endl;
            return;
        }
        while(std::getline(my_add,line)) {
            if(line==std::to_string(roll_no)) {
                found = true;
                std::cout<<"===================="<<std::endl;
                std::cout <<"Roll no.:"<<line<<std::endl;// for roll no.
                std::getline(my_add,line);
                std::cout<<"Name:"<<line<<std::endl;// for name
                std::getline(my_add,line);
                std::cout<<"Mobile no.:"<<line<<std::endl; // for mobile no
                std::getline(my_add,line);
                std::cout<<"Department:"<<line<<std::endl;//for department
                std::cout<<"===================="<<std::endl;
                break;
            }
        }
        if(!found) {
            std::cout << "Student not found !" << std::endl;
        }


    }
    void updatestudent() {
        bool found = false;
        std::string file_name;
        std:: string file_roll;
        std::string file_mobile;
        std::string file_dept;

        std::cout << "Enter the roll no.:";
        std::cin >> roll_no;
        std::fstream my_add;
        my_add.open("manager.txt",std::ios::in);
        std::fstream my_temp;
        my_temp.open("temporary.txt", std::ios::out);
        if(my_add.fail()||my_temp.fail()) {
            std::cout << "File not found!" <<std::endl;
            return;
        }
        while(std::getline(my_add,file_roll)) {
            std::getline(my_add,file_name);
            std::getline(my_add,file_mobile);
            std::getline(my_add,file_dept);
            if(file_roll==std::to_string(roll_no)) {
                found = true;
                std::cout<<"•Enter New INFORMATION•"<<std::endl;
                std::cout<<"===================="<<std::endl;
                std::cout << "Enter the New roll no.:" <<std::endl;
                std::cin >> file_roll;
                std::cin.ignore();
                std::cout << "Enter the New Name::" <<std::endl;
                std::getline(std::cin,file_name);
                std::cout << "Enter the New Mobile no.::" <<std::endl;
                std::getline(std::cin,file_mobile);
                std::cout <<"Enter the New department:" <<std::endl;
                std::getline(std::cin,file_dept);
                std::cout<<"===================="<<std::endl;
                my_temp<<file_roll<<"\n";
                my_temp<<file_name<<"\n";
                my_temp<<file_mobile<<"\n";
                my_temp<<file_dept<<"\n";
            }
            else {
                my_temp<<file_roll<<"\n";
                my_temp<<file_name<<"\n";
                my_temp<<file_mobile<<"\n";
                my_temp<<file_dept<<"\n";
            }
        }
        my_add.close();
        my_temp.close();

        if(found)
        {
            remove("manager.txt");
            rename("temporary.txt","manager.txt");
            std::cout << "Student successfully updated !" << std::endl;
        }
        else
        {
            remove("temporary.txt");
            std::cout << "Student not found !" << std::endl;
        }
    }
    void delstudent() {
        bool found = false;
        std::string file_roll;
        std::string file_name;
        std::string file_mobile;
        std::string file_dept;

        std::cout << "Enter roll no.:"<<std::endl;
        std::cin >> roll_no;
        std::fstream my_add("manager.txt",std::ios::in);
        std::fstream my_temp("temporary.txt",std::ios::out);
        if(my_add.fail()||my_temp.fail()) {
            std::cout << "File not found!" <<std::endl;
       return; }
        while(std::getline(my_add,file_roll)) {
            std::getline(my_add,file_name);
            std::getline(my_add,file_mobile);
            std::getline(my_add,file_dept);
            if(file_roll==std::to_string(roll_no)) {
                found = true;
            }
            else {
                my_temp<<file_roll<<"\n";
                my_temp<<file_name<<"\n";
                my_temp<<file_mobile<<"\n";
                my_temp<<file_dept<<"\n";
            }
        }
        my_add.close();
        my_temp.close();

        if(found) {
            remove("manager.txt");
            rename("temporary.txt","manager.txt");
            std::cout << "Successfully Deleted 🥂" << std::endl;
        }
        else {
            remove("temporary.txt");
            std::cout << "Student not found 🚫" << std::endl;
            return;
        }
    }};
int main() {
    student sm;
    int choice;

    while(true)
    {
        std::cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display Student\n";
        std::cout << "3. Search Student\n";
        std::cout << "4. Update student\n";
        std::cout << "5. Delete student\n";
        std::cout << "6.     EXIT       \n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice)
        {
        case 1:
            sm.addstudent();
            break;

        case 2:
            sm.displaystudent();
            break;

        case 3:
            sm.searchstudent();
            break;
        case 4:
            sm.updatestudent();
            break;
        case 5:
            sm.delstudent();
            break;
        case 6:
            std::cout << "Program Closed Successfully\n";
            return 0;


        default:
            std::cout << "Invalid Choice\n";
        }
    } return 0;}