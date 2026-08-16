#include <iostream>
#include <string>
#include<fstream>
#include<cstdio>
class Shop {
public:
    int product_id;
    std:: string pd_name;
    int  pd_quantity;
    double pd_price;
    int sell_product;
    void addproduct() {
        std::string file_id;
        std::string file_name;
        std::string file_quantity;
        std::string file_price;
        std::cout << "\n====================================\n";
        std::cout << "          ADD PRODUCT\n";
        std::cout << "====================================\n";
        std::cout << "Enter Product ID: " << std::endl;
        std::cin >> product_id;
        std::fstream my_pd("product.txt",std::ios::in);
        if (!my_pd.fail()) {
            while(std::getline(my_pd,file_id)) {
                if(file_id ==std::to_string(product_id)) {
                    std::cout << "Product ID already existed" << std::endl;
                    return;
                }
                std::getline(my_pd,file_name);
                std::getline(my_pd,file_quantity);
                std::getline(my_pd,file_price);
            }

        }
        my_pd.close();
        std::cin.ignore();
        std::cout << "Enter Product name:" <<std::endl;
        std::getline(std::cin,pd_name);
        std::cout << "Enter the quantity:" <<std::endl;
        std::cin >> pd_quantity;
        std::cin.ignore();
        std::cout << "Enter the price:" << std::endl;
        std::cin >> pd_price;
        my_pd.open("product.txt",std::ios::app);
        if(my_pd.fail()) {
            std::cout << "File not found!" << std::endl;
            return;
        }
        my_pd<<product_id<<"\n";
        my_pd<<pd_name<<"\n";
        my_pd<<pd_quantity<<"\n";
        my_pd<<pd_price<<"\n";
        my_pd.close();
        std::cout << "successfully added 😉" << std::endl;
    }
    void displayproduct() {
        std:: string file_id;
        std:: string file_name;
        std:: string file_quantity;
        std:: string file_price;
        std:: fstream my_pd;
        my_pd.open("product.txt",std::ios::in);
        if(my_pd.fail()) {
            std::cout << "File not found 🚫" <<std:: endl;
            return;
        }
        std::cout << "\n====================================\n";
        std::cout << "        DISPLAY PRODUCTS\n";
        std::cout << "====================================\n";
        while(std::getline(my_pd,file_id))
        {std::cout << "Product ID: " << file_id << std::endl;
        
            std::getline(my_pd,file_name);
            std::cout << "Product Name: " << file_name << std::endl;

            std::getline(my_pd,file_quantity);
            std::cout << "Quantity: " << file_quantity << std::endl;

            std::getline(my_pd,file_price);
            std::cout << "Price: " << file_price << std::endl;

            std::cout << "------------------------" << std::endl;
        }
        my_pd.close();
    }
    void searchproduct() {
        bool found = false;
        std::string file_id;
        std:: string file_name;
        std:: string file_quantity;
        std:: string file_price;
        std::cout << "Enter product ID: " <<std:: endl;
        std::cin >> product_id;
        std::fstream my_pd;
        my_pd.open("product.txt",std::ios::in);
        if(my_pd.fail()) {
            std::cout << "file not found 😵" << std::endl;
            return;
        }
        while(std::getline(my_pd,file_id))
        {
            std::getline(my_pd,file_name);
            std::getline(my_pd,file_quantity);
            std::getline(my_pd,file_price);

            if(file_id == std::to_string(product_id))
            {
                found = true;

                std::cout << "\n====================================\n";
                std::cout << "         SEARCH PRODUCT\n";
                std::cout << "====================================\n";
                std::cout << "Product ID: " << file_id << std::endl;
                std::cout << "Name: " << file_name << std::endl;
                std::cout << "Quantity: " << file_quantity << std::endl;
                std::cout << "Price: " << file_price << std::endl;
                std::cout << "------------------------" << std::endl;
                break;
            }
        }
        if(found==false) {
            std::cout << "Product not found 🚫" << std::endl;
        }
        my_pd.close();
    }
    void updateproduct() {
        bool found = false;
        std::string file_id;
        std:: string file_name;
        std:: string file_quantity;
        std:: string file_price;
        std::cout << "Enter Product ID:" <<std:: endl;
        std::cin>>product_id;
        std::cin.ignore();
        std:: fstream my_pd;
        my_pd.open("product.txt",std::ios::in);
        std::fstream my_temp;
        my_temp.open("temporary.txt",std::ios::out);
        if(my_pd.fail()||my_temp.fail()) {
            std::cout << "File not found 😵" <<std:: endl;
            return;
        }
        while(std::getline(my_pd,file_id)) {
            std::getline(my_pd,file_name);
            std::getline(my_pd,file_quantity);
            std::getline(my_pd,file_price);
            if(file_id ==std::to_string(product_id)) {
                found = true;
                std::cout << "\n====================================\n";
                std::cout << "         UPDATE PRODUCT\n";
                std::cout << "====================================\n";
                std::cout << "Enter new ID:" <<std::endl;
                std::cin>>file_id;
                std::cin.ignore();
                std::cout << "Enter new Name:" << std::endl;
                std::getline(std::cin,file_name);
                std::cout << "Enter new Quantity:" <<std:: endl;
                std::getline(std::cin,file_quantity);
                std::cout << "Enter new Price: " << std::endl;
                std::getline(std::cin,file_price);
                std::cout << "------------------------" << std::endl;
                my_temp<<file_id<<"\n";
                my_temp<<file_name<<"\n";
                my_temp<<file_quantity<<"\n";
                my_temp<<file_price<<"\n";
            }
            else {
                my_temp<<file_id<<"\n";
                my_temp<<file_name<<"\n";
                my_temp<<file_quantity<<"\n";
                my_temp<<file_price<<"\n";
            }
        }
        my_pd.close();
        my_temp.close();
        if(found==true) {
            remove("product.txt");
            rename("temporary.txt","product.txt");
            std::cout << "Successfully Updated 🥂" << std::endl;
        }
        else {
            remove("temporary.txt");
            std::cout << "Product not found 🚫" << std::endl;
        }
    }
    void delproduct() {
        bool found = false;
        std::string file_id;
        std::string file_name;
        std::string file_quantity;
        std::string file_price;
        std::cout << "\n====================================\n";
        std::cout << "         DELETE PRODUCT\n";
        std::cout << "====================================\n";
        std::cout << "Enter Product ID:" <<std::endl;
        std::cin >> product_id;
        std:: fstream my_pd;
        my_pd.open("product.txt",std::ios::in);
        std:: fstream my_temp;
        my_temp.open("temporary.txt",std::ios::out);
        if(my_pd.fail()||my_temp.fail()) {
            std::cout << "File not found 😵" <<std::endl;
            return;
        }
        while(std::getline(my_pd,file_id)) {
            std::getline(my_pd,file_name);
            std::getline(my_pd,file_quantity);
            std::getline(my_pd,file_price);
            if(file_id==std::to_string(product_id)) {
                found = true;
            }
            else {
                my_temp<<file_id<<"\n";
                my_temp<<file_name<<"\n";
                my_temp<<file_quantity<<"\n";
                my_temp<<file_price<<"\n";
            }
        }
        my_pd.close();
        my_temp.close();
        if(found==true) {
            remove("product.txt");
            rename("temporary.txt","product.txt");
            std::cout << "Successfully Deleted 🥂" << std::endl;
        }
        else {
            remove("temporary.txt");
            std::cout << "Product not found ⛔" << std::endl;
        }
    }

    void sellproduct() {
        bool found = false;
        bool sold = false;
        std::string file_id;
        std::string file_name;
        std:: string file_price;
        std::string file_quantity;
        std::cout << "\n====================================\n";
        std::cout << "          SELL PRODUCT\n";
        std::cout << "====================================\n";
        std::cout << "Enter the ID:" << std::endl;
        std::cin >> product_id;
        std::cin.ignore();
        std::fstream my_pd("product.txt",std::ios::in);
        std::fstream my_temp("temporary.txt",std::ios::out);
        if(my_pd.fail()||my_temp.fail()) {
            std::cout << "File not found 😵" <<std:: endl;
            return;
        }
        while(std::getline(my_pd,file_id)) {
            std::getline(my_pd,file_name);
            std::getline(my_pd,file_quantity);
            std::getline(my_pd,file_price);
            if(file_id==std::to_string(product_id)) {
                found= true;
                std::cout << "Enter Sell Quantity: " <<std:: endl;
                std::cin >> sell_product;
                std::cin.ignore();
                int pd_quantity=std::stoi(file_quantity);
                if(sell_product <= 0)
                {
                    std::cout << "Invalid Quantity 🚫" << std::endl;
                    my_temp<<file_id<<"\n";
                    my_temp<<file_name<<"\n";
                    my_temp<<file_quantity<<"\n";
                    my_temp<<file_price<<"\n";
                    continue;
                }

                else if(sell_product>pd_quantity) {
                    std::cout << "Insufficient Stock 😵‍💫" << std::endl;
                    my_temp<<file_id<<"\n";
                    my_temp<<file_name<<"\n";
                    my_temp<<file_quantity<<"\n";
                    my_temp<<file_price<<"\n";
                }
                else {

                    pd_quantity = (pd_quantity - sell_product);
                    double pd_price=std::stod(file_price);
                    double sale_amount;
                    sale_amount=(sell_product * pd_price);
                    sold = true;
                    std::fstream sales_file;
                    sales_file.open("total_sales.txt", std::ios::app);

                    sales_file << sale_amount << "\n";

                    sales_file.close();
                    my_temp<<file_id<<"\n";
                    my_temp<<file_name<<"\n";
                    my_temp<<pd_quantity<<"\n";
                    my_temp<<pd_price<<"\n";
                }
            }
            else {
                my_temp<<file_id<<"\n";
                my_temp<<file_name<<"\n";
                my_temp<<file_quantity<<"\n";
                my_temp<<file_price<<"\n";
            }
        }
        my_pd.close();
        my_temp.close();
        if(found == true && sold == true)
        {
            remove("product.txt");
            rename("temporary.txt","product.txt");
            std::cout << "Product Successfully Sold🥂" << std::endl;
        }
        else if(found == false)
        {
            remove("temporary.txt");
            std::cout << "Product not found 🚫" << std::endl;
        }
        else
        {
            remove("temporary.txt");
        }
    }
    void totalsale() {
        double total_sale = 0;
        double sale_amount;
        std::fstream sales_file;
        sales_file.open("total_sales.txt", std::ios::in);
        if(sales_file.fail()) {
            std::cout << "File not found 😵" << std::endl;
            return;
        }
        while(sales_file>>sale_amount) {
            total_sale += sale_amount;
        }
        sales_file.close();
        std::cout << "\n====================================\n";
        std::cout << "         TOTAL SALES\n";
        std::cout << "====================================\n";
        std::cout << "Total Sales:"<< total_sale << std::endl;
    }
    void lowstock() {
        bool found = false;
        std::string file_id;
        std::string file_name;
        std::string file_quantity;
        std::string file_price;
        std::fstream my_pd;
        my_pd.open("product.txt", std::ios::in);
        if(my_pd.fail()) {
            std::cout << "File not found 😵" << std::endl;
            return;
        }
        std::cout << "\n====================================\n";
            std::cout << "       LOW STOCK PRODUCTS\n";
            std::cout << "====================================\n";
        while(std::getline(my_pd,file_id)) {
            std::getline(my_pd,file_name);
            std::getline(my_pd,file_quantity);
            std::getline(my_pd,file_price);
            int pd_quantity= std::stoi(file_quantity);
            if(pd_quantity<5) {
                found = true;
                std::cout<< "Product ID:"<<file_id<<std::endl;
                std::cout << " Name:"<<file_name<<std::endl;
                std::cout << "Quantity:"<<pd_quantity<<std::endl;
                std::cout << "Price:"<<file_price<<std::endl;
                std::cout << "------------------------" << std::endl;
            }
        }
        my_pd.close();
        if(found==false) {
            std::cout << "No Low Stock 🚫" <<std:: endl;
        }
    }

};

int main()
{
    Shop Inv;
    int choice;

    do
    {
        std::cout << "\n========================================\n";
        std::cout << "      SHOP MANAGEMENT SYSTEM\n";
        std::cout << "========================================\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. Display Products\n";
        std::cout << "3. Search Product\n";
        std::cout << "4. Update Product\n";
        std::cout << "5. Delete Product\n";
        std::cout << "6. Sell Product\n";
        std::cout << "7. Total Sales\n";
        std::cout << "8. Low Stock Products\n";
        std::cout << "9. Exit\n";
        std::cout << "----------------------------------------\n";
        std::cout << "Enter Choice : ";
        std::cin >> choice;

        switch(choice)
        {
        case 1:
            Inv.addproduct();
            break;

        case 2:
            Inv.displayproduct();
            break;

        case 3:
            Inv.searchproduct();
            break;

        case 4:
            Inv.updateproduct();
            break;

        case 5:
            Inv.delproduct();
            break;

        case 6:
            Inv.sellproduct();
            break;

        case 7:
            Inv.totalsale();
            break;

        case 8:
            Inv.lowstock();
            break;

        case 9:
            std::cout << "Thank You! Program Closed.\n";
            break;

        default:
            std::cout << "Invalid Choice!\n";
        }

    } while(choice != 9);

    return 0;
}














































































