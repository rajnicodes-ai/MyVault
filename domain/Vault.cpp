#include "domain/Vault.h"
#include "domain/TextUtils.h"

#include <optional>
#include <string>
#include <vector>

std::string toString(AddResult result)
{
    switch (result)
    {
    case AddResult::Ok:
        return "Jud gaya";
    case AddResult::EmptyTitle:
        return "Naam khaali hai";
    case AddResult::EmptyUsername:
        return "Username khaali hai";
    case AddResult::EmptyPassword:
        return "Password khaali hai";
    case AddResult::Duplicate:
        return "Is naam ki entry pehle se hai";
    }

    return "Pata nahi kya hua";

}

AddResult Vault::add(const Entry &entry)
{
    if (isBlank(entry.title()))
        return AddResult::EmptyTitle;

    if (isBlank(entry.username()))
        return AddResult::EmptyUsername;

    if (isBlank(entry.password()))
        return AddResult::EmptyPassword;

    if (contains(entry.title()))
        return AddResult::Duplicate;

    m_entries.push_back(entry);
    return AddResult::Ok;
}

bool Vault::remove(const std::string &title)
{
    for (std::size_t i = 0; i < m_entries.size(); ++i)
    {
        if (m_entries[i].title() == title)
        {
            m_entries.erase(m_entries.begin() + i);
            return true;
        }
    }

    return false;

}

bool Vault::contains(const std::string &title) const
{
    for (const Entry &e : m_entries)
    {
        if (e.title() == title)
            return true;
    }

    return false;
}

std:: optional<Entry> Vault::find(const std::string &title) const

{
    for (const Entry &e : m_entries)
    {
        if (e.title() == title)
            return e;
    }

    return std:: nullopt;
}



int Vault::favoriteCount() const
{

    int count = 0;

    for (const Entry &e : m_entries)
    {
        if (e.isFavorite())
            ++count;
    }
    return count;
}

int Vault::countCategory(Category category) const
{

    int count = 0;

    for (const Entry &e : m_entries)
    {
        if (e.category() == category)
        {
            ++count;
        }
    }
    return count;
}
