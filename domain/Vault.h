#pragma once

#include "domain/Entry.h"

#include <string>
#include <optional>
#include <vector>

//all password entries ki list

enum class AddResult
{
    Ok,
    EmptyTitle,
    EmptyUsername,
    EmptyPassword,
    Duplicate,
};


std::string toString(AddResult result);

class Vault

{

public:

   AddResult add(const Entry &entry);
    bool remove(const std::string &title);
    bool contains(const std::string &title) const;

    std:: optional<Entry> find(const std::string &title) const;

    std::size_t size() const
    {
        return m_entries.size();
    }

    int favoriteCount() const;

    const std::vector<Entry> &entries() const
    {
        return m_entries;
    }

    int countCategory(Category category) const;



private:

    std::vector<Entry> m_entries;


};
