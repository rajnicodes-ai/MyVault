#include <iostream>

#include "domain/Entry.h"
#include <vector>
#include <string>



void addEntry (std::vector<Entry> &entries,
              const std::string &title,
              const std::string &username,
              const std::string &password,
              const std::string &category,
              bool favorite)
{


    Entry e;
    e.title = title;
    e.username = username;
    e.password = password;
    e.category = category;
    e.favorite = favorite;
    entries.push_back(e);

}

void printEntry (std::size_t number, const Entry &e){

    std::cout << number << ". " << e.title;

    if(e.favorite)
        std::cout << "(favorite)";
    std::cout<< "\n";

    std::cout << " " << e.username << " | " << e. category << "\n";
}

void printEntries(const std::vector<Entry> &entries){

    std::cout << "Total Passwords: " << entries.size() << "\n\n";

    for (std::size_t i = 0; i < entries.size(); ++i)

        printEntry(i + 1, entries[i]);


}

int main(){

    std::vector<Entry> entries;

    addEntry(entries, "Gmail", "rajni@example.com", "test@123", "Email", true);
    addEntry(entries, "Facebook", "rajni.fb", "fb@2026","Social", false);
    addEntry(entries, "SBI net Banking", "RAJNI1234", "Bank#123", "Banking", true);
    addEntry(entries, "Netfilx", "rajni@example.com", "Movie!42", "Entertainment", false);

    std::cout << "My vault v0.1.0\n";
    printEntries(entries);

    return 0;

}
