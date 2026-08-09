# include<iostream>
# include<fstream>
# include<string>
# include <map>
# include<limits>
class book {
public:
    int book_id;
    std::string book_name;
    std::string author_name;
    int quantity;
    
};
class issuebook {
public:
    int book_id;
    int student_id;
    std::string student_name;
};

class library {
private:
    std::map<int,book>books;
    std::map<int,issuebook>issuedbook;
public:
    void addbooks() {
        int id;
        std:: string name;
        std:: string author;
        int qty;
        std::cout << "\n========== ADD NEW BOOK ==========\n";
        std::cout<<"Enter the book ID:"<<std::endl;
        std::cin>>id;
        std::cin.ignore();
        if(books.find(id)!=books.end()) {
            std::cout<<"book id is already existed"<<std::endl;
            return;
        }
        std::cout<<"Enter the book name:"<<std::endl;
        std::getline(std::cin,name);
        std::cout<<"Enter the author:"<<std::endl;
        std::getline(std::cin,author);
        std::cout<<"Enter the Quantity:"<<std::endl;
        std::cin>>qty;
        if(qty<=0) {
            std::cout<<"invalid Quantity"<<std::endl;
            return;
        }
        std::cout<<"-------------------"<<std::endl;
        std::cin.ignore();
        book b;
        b.book_id=id;
        b.book_name= name;
        b.author_name=author;
        b.quantity=qty;
        books[id] = b;
        savefile();
        std::cout<<"\nBook  Added Successfully!\n"<<std::endl;
    }
    // DISPLAY FUNCTION
    void displaybooks() {
        if(books.empty( )) {
            std::cout<<" Book not found"<<std::endl;
            return;
        }


        for(auto it=books.begin(); it!=books.end(); it++) {
            std::cout<<"Book ID:"<<it->second.book_id<<std::endl;
            std::cout<<"Name:"<<it->second.book_name<<std::endl;
            std::cout<<"Author:"<<it->second.author_name<<std::endl;
            std::cout<<"Quantity:"<<it->second.quantity<<std::endl;
            std::cout<<"-------------------"<<std::endl;
        }
    }
    void searchbook() {
        int id;
        std::cout<<"Enter the ID:"<<std::endl;
        std::cin>>id;
        auto it= books.find(id);
        if (it==books.end())
        {
            std::cout<<" Book not found"<<std::endl;
            return;
        }
        std::cout << "\n========== BOOK DETAILS ==========\n";
        std::cout<<"Book ID:"<<it->second.book_id<<std::endl;
        std::cout<<"Name:"<<it->second.book_name<<std::endl;
        std::cout<<"Author:"<<it->second.author_name<<std::endl;
        std::cout<<"Quantity:"<<it->second.quantity<<std::endl;
        std::cout<<"-------------------"<<std::endl;
    }
    void updatebook() {
        int id;
        std::string name;
        std::string author;
        int qty;

        std::cout<<"Enter the ID:"<<std::endl;
        std::cin>>id;
        std::cin.ignore();
        auto it=books.find(id);
        if (it==books.end())
        {
            std::cout<<"Book not found"<<std::endl;
            return;
        }

        std::cout<<"Book ID:"<<it->second.book_id<<std::endl;
        std::cout<<"Name:"<<it->second.book_name<<std::endl;
        std::cout<<"Author:"<<it->second.author_name<<std::endl;
        std::cout<<"Quantity:"<<it->second.quantity<<std::endl;

        std::cout<<"Enter New Details:"<<std::endl;// new details

        std::cout<<"Enter New Name:"<<std::endl;
        std::getline(std::cin,name);
        std::cout<<"Enter Author Name:"<<std::endl;
        std::getline(std::cin,author);
        std::cout<<"Enter Quantity:"<<std::endl;
        std::cin>>qty;
        std::cin.ignore();
        std::cout<<"-------------------"<<std::endl;
        while (qty<=0)
        {
            std::cout<<"Enter a valid number. Try again."<<std::endl;
            std::cout<<"Enter Quantity:"<<std::endl;
            std::cin>>qty;
        }
        it->second.book_name=name;
        it->second.author_name=author;
        it->second.quantity= qty;
        savefile();
        std::cout<<"\nBook Updated Successfully!\n"<<std::endl;
    }
    void delbook() {
        int id;
        std::cout<<"Enter ID:"<<std::endl;
        std::cin>>id;
        auto it=books.find(id);
        if(it== books.end()) {
            std::cout<<"Book not found"<<std::endl;
            return;
        }
        books.erase(id);
        savefile();
        std::cout<<"\nBook Deleted Successfully\n"<<std::endl;
    }
    void issubook() {
        int id;
        int stuid;
        std:: string name;
        std::cout<<"Enter ID:"<<std::endl;
        std::cin>>id;
        std::cin.ignore();
        auto it= books.find(id);
        if(it==books.end()) {
            std::cout<<"Book not found"<<std::endl;
            return;
        }
        if(it->second.quantity<=0){
            std::cout<<" Book Out Of Stock"<<std::endl;
            return;
        }
        std::cout<<"Enter Details:"<<std::endl;
        std::cout<<"Enter Student ID;"<<std::endl;
        std::cin>>stuid;
        std::cin.ignore();
        std::cout<<"Enter Student name:"<<std::endl;
        std::getline(std::cin,name);
        std::cout<<"-------------------"<<std::endl;
        /*In this part firstly make a object of a class (issue) and asign the values in the class after asign the values,
        asign values in t map(issuedbook) through the issue object*/
        issuebook issue;
        issue.book_id = id;
        issue.student_id = stuid;
        issue.student_name = name;
        issuedbook[id] = issue;
        // Decrease the quantity of the books
        it->second.quantity--;
        savefile();
        std::cout<<"\nBook Issued Successfully!\n"<<std::endl;
    }
    void returnbook() {
        int id;
        std::cout<<"Enter ID"<<std::endl;
        std::cin>>id;
        /* In this find book details in map(books)*/
    
        auto  bookit= books.find(id);
        if(bookit==books.end()) {
            std::cout<<"Book not found"<<std::endl;
            return;
        }
        // In this find details in map (issuedbook)
        auto issueit= issuedbook.find(id);
        if(issueit== issuedbook.end()) {
            std::cout<<"Book not Issued"<<std::endl;
            return;
        }
        // increase the Quantity after returned the book
        bookit->second.quantity++;

        issuedbook.erase(id);// erase the details in map(issuedbook)
        savefile();
        std::cout<<"\nBook Returned Successfully!\n"<<std::endl;

    }
    void displayissuebook() {
        if (issuedbook.empty())
        {
            std::cout<<"Library is empty"<<std::endl;
            return;
        }
        for ( auto it=issuedbook.begin(); it!=issuedbook.end(); it++) // Take details and data from map
        {
            std::cout<<"Book ID:"<<it->second.book_id<<std::endl;
            std::cout<<"Student ID:"<<it->second.student_id<<std::endl;
            std::cout<<"Student Name:"<<it->second.student_name<<std::endl;
            std::cout<<"-------------------"<<std::endl;
        }
    }
    void totalbooks() {
        if(books.empty()) {
            std::cout<<"Library is empty"<<std::endl;
            return;
        }
        int totalquantity=0;
        std::cout << "\n========== LIBRARY REPORT ==========\n";

        for(auto it=books.begin(); it!=books.end(); it++) {
            totalquantity+=it->second.quantity;
        }


        std::cout << "Total Titles : " << books.size() << std::endl;
        std::cout << "Total Books  : " << totalquantity << std::endl;
        std::cout<<"-------------------"<<std::endl;

    }

    void totalissuedbook() {
        if(issuedbook.empty()) {
            std::cout<<"No Book Issued"<<std::endl;
            return;
        }
        int totalissued= issuedbook.size();
        std::cout << "\n========== ISSUED BOOK REPORT ==========\n";

        std::cout << "Issued Books : " << totalissued << std::endl;
        std::cout<<"-------------------"<<std::endl;
    }

    void savefile() {
        // In this function save data in file
        std::fstream my_book;
        my_book.open("books.txt",std::ios::out);
        if(my_book.fail()) {
            std::cout<<"File not found"<<std::endl;
            return;
            }// Write data in file
        for( auto it= books.begin(); it!=books.end(); it ++) {
            my_book<<it->second.book_id<<"\n";
            my_book<<it->second.book_name<<"\n";
            my_book<<it->second.author_name<<"\n";
            my_book<<it->second.quantity<<"\n";
        }
        my_book.close();
        std::ofstream my_issue("issuedbook.txt");
        if(my_issue.fail()) {
            std::cout<<" File not found"<<std::endl;
            my_issue.close();
        }// write data in issuebook class
        for( auto it= issuedbook.begin(); it!=issuedbook.end(); it++) {
            my_issue<<it->second.book_id<<"\n";
            my_issue<<it->second.student_id<<"\n";
            my_issue<<it->second.student_name<<"\n";
        }
        my_issue.close();
    }
    // Load data from the map (books&isuedbook)
    void loadfile() {
        std::ifstream my_book("books.txt");
        if(my_book.fail()) {
            std::cout<<"No previous data found. Starting with empty library"<<std::endl;
            return;
        }
        books.clear();
        issuedbook.clear();
        book b;// make object of class and read the data from the file
        while(my_book>>b.book_id>>b.book_name
                >>b.author_name>>b.quantity)
        {
            books[b.book_id]=b;
        }
        my_book.close();
        std:: ifstream my_issue("issuedbook.txt");
        if(my_issue.fail()) {
            std::cout<<"File not found"<<std::endl;
            return;
        }
        issuebook issue;// make object of class& read data from the file
        while(my_issue>>issue.book_id>>issue.student_id
                >>issue.student_name)
        {
            issuedbook[issue.book_id]= issue;
        }
        my_issue.close();
        std::cout<<" Data Loaded successfully"<<std::endl;
    }

    void menu() {
        int choice;
        do
        {   std::cout << "\n=========================================\n";
            std::cout << "          LIBRARY MANAGEMENT\n";
            std::cout << "=========================================\n";

            std::cout << "1.  Add Book\n";
            std::cout << "2.  Display Books\n";
            std::cout << "3.  Search Book\n";
            std::cout << "4.  Update Book\n";
            std::cout << "5.  Delete Book\n";
            std::cout << "6.  Issue Book\n";
            std::cout << "7.  Return Book\n";
            std::cout << "8.  Display Issued Books\n";
            std::cout << "9.  Total Books\n";
            std::cout << "10. Total Issued Books\n";
            std::cout << "11. Exit\n";

            std::cout << "-----------------------------------------\n";
            std::cout << "Enter Choice : ";
            std::cin>> choice;

            switch (choice)
            {
            case 1:
                addbooks();
                break;
            case 2:
                displaybooks();
                break;
            case 3:
                searchbook();
                break;
            case 4:
                updatebook();
                break;
            case 5:
                delbook();
                break;
            case 6:
                issubook();
                break;
            case 7:
                returnbook();
                break;
            case 8:
                displayissuebook();
                break;
            case 9:
                totalbooks();
                break;
            case 10:
                totalissuedbook();
                break;
            case 11:
                savefile();
                  std::cout << "\n=========================================\n";
        std::cout << " Thank You For Using Library Management\n";
        std::cout << "      Program Closed Successfully\n";
        std::cout << "=========================================\n";

                break;
            default:
                std::cout<<"Enter valid choice"<<std::endl;
                break;
            }
        } while (choice!=11);
        return ;

    }
    void adminlogin() {
        const int MAX_ATTEMPTS=3;
        int attempt = MAX_ATTEMPTS;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        while (attempt>0)
        {
            std:: string name;
            int pass;
            std::cout << "\n========== ADMIN LOGIN ==========\n";

            std::cout << "Username : ";
            std::getline(std::cin, name);

            std::cout << "Password : ";
            std::cin >> pass;
            if(name=="sharma"&& pass==191208) {
                std::cout << "\nLogin Successful!\n";
                menu();
                return;
            }
            attempt--;
            std::cout<<"Invalid username or password!"<<std::endl;
            if (attempt >0)
            {
                std::cout<<"Remaining Attempts:"<<attempt<<std::endl;
            }

        }
        std::cout<<"Maximum Attempts Reached!"<<std::endl;
        std::cout << "\n=========================================\n";
        std::cout << " Thank You For Using Library Management\n";
        std::cout << "      Program Closed Successfully\n";
        std::cout << "=========================================\n";


    }
};
int main() {
    std::cout << "=========================================\n";
    std::cout << "      LIBRARY MANAGEMENT SYSTEM\n";
    std::cout << "=========================================\n";
    library lb;
    lb.loadfile();
    std::cout<<"Press Enter.."<<std::endl;
    lb.adminlogin();
    return 0;
}
 
 

