#include <iostream>

#include "domain/Entry.h"

int main(){

    std::vector<Entry> entries;

    Entry gmail;
    gmail.title = "Gmail";
    gmail.username = "rajni@example.com";
    gmail.password = "text123";
    gmail.category = "Email";
    gmail.favorite = true;
    entries.push_back(gmail);



    Entry facebook;
    facebook.title = "Facebook";
    facebook.username = "rajni.fb";
    facebook.password = "fb@123";
    facebook.category = "Social";
    facebook.favorite = true;
    entries.push_back(facebook);



    Entry bank;
    bank.title = "SBI Net Banking";
    bank.username = "RAJNI1234";
    bank.password = "Bank#9876";
    bank.category = "Banking";
    bank.favorite = true;
    entries.push_back(bank);


    std::cout << "MyVault v0.1.0\n\n";
    std::cout << "Total passwords:" << entries.size() << "\n\n";

    for (std::size_t  i = 0; i < entries.size(); ++i){

        const Entry &e = entries[i];

        std::cout << (i + 1) << ". " << e.title;
        if (e.favorite) std:: cout << " (favorite)";

        std::cout << "\n";
        std::cout << " " << e.username << " | " << e.category << "\n";
    }

    return 0;

}
