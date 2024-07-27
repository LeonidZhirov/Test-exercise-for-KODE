#pragma once
#include <iostream>
#include <vector>
#include "Object.h"

static void sort(std::vector<Object>& vec, size_t start, size_t end, const char& type_of_sorting) {

    if (start > end)
        return;

    size_t current = start;
    for (size_t i{ current + 1 }; i < vec.size(); i++)
        switch (type_of_sorting) {
        case 'a': // Sorts by the time of the creation
            if (vec.at(i).getTimeOfCreation() < vec.at(start).getTimeOfCreation())
                std::swap(vec.at(++current), vec.at(i));
            break;
        case 'b': // Sorts by the distance
            if (vec.at(i).getDistance() < vec.at(start).getDistance())
                std::swap(vec.at(++current), vec.at(i));
            break;
        case 'c': // Sorts by the name
            if (vec.at(i).getName() < vec.at(start).getName())
                std::swap(vec.at(++current), vec.at(i));
            break;
        case 'd': // Sorts by the type
            if (vec.at(i).getType() < vec.at(start).getType())
                std::swap(vec.at(++current), vec.at(i));
            break;
        }

    std::swap(vec.at(start), vec.at(current));

    if (current > start)
        sort(vec, start, current - 1, type_of_sorting);

    if (end > current + 1)
        sort(vec, current + 1, end, type_of_sorting);
}