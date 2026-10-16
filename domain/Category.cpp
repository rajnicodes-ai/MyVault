#include "domain/Category.h"

std::string toString(Category category)
{
    switch (category)
    {
    case Category::Email:
        return "Email";

    case Category::Social:
        return "Social";

    case Category::Banking:
        return "Banking";

    case Category::Work:
        return "Work";

    case Category::Shopping:
        return "Shopping";

    case Category::Entertainment:
        return "Entertainment";

    case Category::Other:
        return "Other";
    }

    return "Other";
}