#include "domain/Entry.h"
#include "domain/TextUtils.h"


Entry::Entry(const std::string &title, const std::string &username, const std::string &password)
    : m_title(title)
    ,m_username(username)
    ,m_password(password)
{
}

bool Entry::setPassword(const std::string &password)
{
    if (isBlank(password))
        return false;

    m_password = password;

    return true;
}

void Entry::setWebsite(const std::string &website)
{
    m_website = website;
}

void Entry::setCategory(Category category)
{
    m_category = category;
}

void Entry::setNotes(const std::string &notes)
{
    m_notes = notes;
}

void Entry::setFavorite(bool favorite)
{
    m_favorite = favorite;
}
