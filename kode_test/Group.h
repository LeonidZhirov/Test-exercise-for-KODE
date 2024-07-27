#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include "Object.h"
#include "Sort.h"
#include "CreateGroup.h"
#include "PrintGroup.h"

static void group(std::vector<Object>& vec, const char& type_of_sorting) {
    sort(vec, 0, size_t(vec.size() - 1), type_of_sorting);

    switch (type_of_sorting) {
    case 'a': { // Sorts by the time of the creation
        std::unordered_set<std::string> groups;
        createGroups(groups, vec);
        printGroups(groups, vec);
        break;
    }
    case 'b': // Sorts by the distance
    case 'd': { // Sorts by the type
        std::set<std::string> groups;
        createGroups(groups, vec, type_of_sorting);
        printGroups(groups, vec, type_of_sorting);
        break;
    }
    case 'c': // Sorts by the name
    {
        std::set<char> groups;
        createGroups(groups, vec);
        printGroups(groups, vec);
        break;
    }

    }
}