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

int main()
{
    Vault vault;

    vault.add(makeEntry("Gmail", "rajni@example.com", "test123", Category::Email, true));
    vault.add(makeEntry("Facebook", "rajni.fb", "fb@2026", Category::Social, false));
    vault.add(makeEntry("SBI Net Banking", "RAJNI1234", "Bank#9876", Category::Banking, true));
    vault.add(makeEntry("Netflix", "rajni@example.com", "Movie!42", Category::Entertainment, false));

    std::cout << "MyVault v0.1.0\n";
    printVault(vault);

    if (!vault.add(makeEntry("Gmail", "doosra@example.com", "abc", Category::Email, false)))
        std::cout << "\nGmail pehle se hai, dobara nahi juda!\n";

    if (vault.remove("Facebook"))
        std::cout << "Facebook hata diya\n";

    std::cout << "\nAb:\n";
    printVault(vault);



    return 0;
}