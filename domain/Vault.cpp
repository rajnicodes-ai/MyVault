#include "domain/Vault.h"


bool Vault::add(const Entry &entry)
{

    if (contains(entry.title()))
        return false;

    m_entries.push_back(entry);
    return true;
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
