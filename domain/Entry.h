
#pragma once

#include <string>

//Ek password entry : ek website ka login.

class Entry {

public:

    Entry(const std::string &title, const std::string &username, const std::string &password);

    // Getter: only read

    const std::string &title() const {return m_title;}

    const std::string &username() const {return m_username;}

    const std::string &password() const {return m_password;}

    const std::string &website() const {return m_website;}

    const std::string &category() const {return m_category;}

    const std::string &notes() const {return m_notes;}

    bool isFavorite() const {return m_favorite;}


    //setters: badalne ke rules

    bool setPassword (const std::string &password);

    void setWebsite(const std::string &website);
    void setCategory(const std::string &category);
    void setNotes(const std::string &notes);
    void setFavorite(bool favorite);

private:

    std::string m_title;
    std::string m_username;
    std::string m_password;
    std::string m_website;
    std::string m_category;
    std::string m_notes;
    bool m_favorite = false;

};
