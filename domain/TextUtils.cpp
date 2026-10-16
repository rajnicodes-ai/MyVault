#include "domain/TextUtils.h"
#include <cctype>


bool isBlank(const std::string &text)
{
    for (char c : text)
    {
        if(!std::isspace(static_cast<unsigned char>(c)))
            return false;
    }
    return true;
}
