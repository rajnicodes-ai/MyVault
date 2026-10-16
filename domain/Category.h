#pragma once

#include <string>


// password kis tarh ka hai. sirf yhi options ho skte hai

enum class Category
{
    Email,
    Social,
    Banking,
    Work,
    Shopping,
    Entertainment,
    Other,
};

std::string toString(Category category);
