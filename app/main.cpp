#include "domain/Entry.h"
#include "domain/Vault.h"

#include <iostream>
#include <string>

Entry makeEntry(const std::string &title,
                const std::string &username,
                const std::string &password,
                Category category,
                bool favorite)
{
    Entry e(title, username, password);
    e.setCategory(category);
    e.setFavorite(favorite);
    return e;
}

void printEntry(std::size_t number, const Entry &e)
{
    std::cout << number << ". " << e.title();
    if (e.isFavorite())
        std::cout << "  (favorite)";
    std::cout << "\n";
    std::cout << "   " << e.username() << "  |  " << toString(e.category()) << "\n";
}

void printVault(const Vault &vault)
{
    std::cout << "Total passwords: " << vault.size() << "\n\n";

    const std::vector<Entry> &entries = vault.entries();
    for (std::size_t i = 0; i < entries.size(); ++i)
        printEntry(i + 1, entries[i]);

    std::cout << "Banking:" << vault.countCategory(Category::Banking) << "\n";

    std::cout << "\nFavorites: " << vault.favoriteCount() << "\n";
}

void tryAdd(Vault &vault, const Entry &entry)
{
    AddResult result = vault.add(entry);
    std::cout << "\"" << entry.title() << "\": " << toString(result) << "\n";
}

void printFound(const Vault &vault, const std::string &title)
{
    std:: optional<Entry> found = vault.find(title);

    if (found)
        std::cout << title << "mila:" << found -> username() << "\n";

    else
        std:: cout << title << " nhi mila\n";
}

int main()
{
    Vault vault;

    vault.add(makeEntry("Gmail", "rajni@example.com", "test123", Category::Email, true));
    vault.add(makeEntry("Facebook", "rajni.fb", "fb@2026", Category::Social, false));
    vault.add(makeEntry("SBI Net Banking", "RAJNI1234", "Bank#9876", Category::Banking, true));
    vault.add(makeEntry("Netflix", "rajni@example.com", "Movie!42", Category::Entertainment, false));

    std::cout << "MyVault v0.1.0\n";

    printVault(vault);

    std::cout << "\n--- Galat entries jodne ki koshish ---\n";

    tryAdd(vault, makeEntry("Gmail", "doosra@example.com", "abc", Category::Email, false));
    tryAdd(vault, makeEntry("   ", "koi@example.com", "abc", Category::Other, false));
    tryAdd(vault, makeEntry("Amazon", "rajni@example.com", "   ", Category::Shopping, false));


    std::cout << "\n----Find-----\n";
    printFound(vault, "Netflix");
    printFound(vault,"Twitter");


    std::cout << "\n";

    if (vault.remove("Facebook"))
        std::cout << "Facebook hata diya\n";

    std::cout << "\nAb:\n";
    printVault(vault);



    return 0;
}