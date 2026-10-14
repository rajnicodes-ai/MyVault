
#pragma once

#include <string>

//Ek password entry : ek website ka login.

struct Entry {

    std::string title;
    std::string username;
    std::string password;
    std::string website;
    std::string category;
    std::string notes;
    bool favorite = false;
};
