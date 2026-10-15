#pragma once

#include "domain/Entry.h"

#include <string>
#include <vector>

//all password entries ki list
class Vault

{

public:

    bool add(const Entry &entry);
    bool remove(const std::string &title);
    bool contains(const std::string &title) const;

    std::size_t size() const
    {
        return m_entries.size();
    }

    int favoriteCount() const;

    const std::vector<Entry> &entries() const
    {
        return m_entries;
    }



private:

    std::vector<Entry> m_entries;


};
