#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include "Object.h"

static void createGroups(std::set<char>& groups, std::vector<Object>& vec) {
    for (size_t i = 0; i < vec.size(); i++)
        groups.insert(vec.at(i).getName().at(0));
}

static void createGroups(std::unordered_set<std::string>& groups, std::vector<Object>& vec) {
    double seconds_in_day = 86400.f;

    for (size_t i = 0; i < vec.size(); i++) {
        if (vec.at(i).getTimeOfCreation() <= seconds_in_day) {
            groups.insert("Сегодня");
            vec.at(i).setGroup("Сегодня");
        }
        else if (vec.at(i).getTimeOfCreation() > seconds_in_day && vec.at(i).getTimeOfCreation() <= seconds_in_day * 2.f) {
            groups.insert("Вчера");
            vec.at(i).setGroup("Вчера");
        }
        else if (vec.at(i).getTimeOfCreation() > seconds_in_day * 2.f && vec.at(i).getTimeOfCreation() <= seconds_in_day * 7.f) {
            groups.insert("На этой неделе");
            vec.at(i).setGroup("На этой неделе");
        }
        else if (vec.at(i).getTimeOfCreation() > seconds_in_day * 7.f && vec.at(i).getTimeOfCreation() <= seconds_in_day * 30.f) {
            groups.insert("В этом месяце");
            vec.at(i).setGroup("В этом месяце");
        }
        else if (vec.at(i).getTimeOfCreation() > seconds_in_day * 30.f && vec.at(i).getTimeOfCreation() <= seconds_in_day * 365.f) {
            groups.insert("В этом году");
            vec.at(i).setGroup("В этом году");
        }
        else {
            groups.insert("Ранее");
            vec.at(i).setGroup("Ранее");
        }
    }
}

static void createGroups(std::set<std::string>& groups, std::vector<Object>& vec, const char& type_of_sorting) {
    for (size_t i = 0; i < vec.size(); i++)
        switch (type_of_sorting) {
        case 'b':
            if (vec.at(i).getDistance() <= 100.f) {
                groups.insert("До 100 eд.");
                vec.at(i).setGroup("До 100 eд.");
            }
            else if (vec.at(i).getDistance() > 100.f && vec.at(i).getDistance() <= 1000.f) {
                groups.insert("До 1000 eд.");
                vec.at(i).setGroup("До 1000 eд.");
            }
            else if (vec.at(i).getDistance() > 1000.f && vec.at(i).getDistance() <= 10000.f) {
                groups.insert("До 10000 eд.");
                vec.at(i).setGroup("До 10000 eд.");
            }
            else {
                groups.insert("Слишком далеко");
                vec.at(i).setGroup("Слишком далеко");
            }
            break;

        case 'c':
            groups.insert(vec.at(i).getName());
            break;

        case 'd':
            groups.insert(vec.at(i).getType());
            break;
        }
}