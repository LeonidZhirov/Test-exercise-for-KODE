#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include "Object.h"
#include "Sort.h"
#include "CreateGroup.h"

static void printGroups(std::set<char>& groups, std::vector<Object>& vec) {
    for (auto group : groups) {
        std::vector<Object> temp_vec;

        for (auto object : vec)
            if (object.getName().at(0) == group)
                temp_vec.push_back(object);

        std::cout << group << std::endl;
        for (auto object : temp_vec)
            object.print();
        std::cout << '\n';
    }
}

static void printGroups(std::unordered_set<std::string>& groups, std::vector<Object>& vec) {
    for (auto group : groups) {
        std::vector<Object> temp_vec;

        for (auto object : vec)
            if (object.getGroup() == group)
                temp_vec.push_back(object);

        std::cout << group << std::endl;
        for (auto object : temp_vec)
            object.print();
        std::cout << '\n';
    }
}

static void printGroups(std::set<std::string>& groups, std::vector<Object>& vec, const char& type_of_sorting) {
    for (auto group : groups) {
        std::vector<Object> temp_vec;

        for (auto object : vec)
            switch (type_of_sorting) {
            case 'b': // sort by the distance
                if (object.getGroup() == group)
                    temp_vec.push_back(object);
                break;
            case 'd':
                if (object.getType() == group)
                    temp_vec.push_back(object);
                break;
            }

        if (type_of_sorting == 'd') {
            std::set<std::string> temp_groups;
            sort(temp_vec, 0, size_t(temp_vec.size() - 1), 'c');
            createGroups(temp_groups, vec, 'c');
        }

        std::cout << group << std::endl;
        for (auto object : temp_vec)
            object.print();
        std::cout << '\n';
    }
}