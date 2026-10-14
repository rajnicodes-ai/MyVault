#include <iostream>

#include "domain/Entry.h"

int main(){

    Entry gmail;
    gmail.title = "Gmail";
    gmail.username = "rajni@example.com";
    gmail.password = "text123";
    gmail.website = "mail.google.com";
    gmail.category = "Email";
    gmail.favorite = true;


    std::cout << "MyVault v0.1.0\n\n";
    std::cout <<"Title    : " << gmail.title << "\n";
    std::cout <<"Username : " << gmail.username << "\n";
    std::cout <<"Password : " << std:: string(gmail.password.size(), '*') << "\n";
    std::cout <<"Website  : " << gmail.website << "\n";
    std::cout <<"Category : " << gmail.category << "\n";
    std::cout <<"Favorite : " << (gmail.favorite ? "Yes" : "No") << "\n";

    return 0;

}
