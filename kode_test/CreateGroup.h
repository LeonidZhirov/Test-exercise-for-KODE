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
            groups.insert("�������");
            vec.at(i).setGroup("�������");
        }
        else if (vec.at(i).getTimeOfCreation() > seconds_in_day && vec.at(i).getTimeOfCreation() <= seconds_in_day * 2.f) {
            groups.insert("�����");
            vec.at(i).setGroup("�����");
        }
        else if (vec.at(i).getTimeOfCreation() > seconds_in_day * 2.f && vec.at(i).getTimeOfCreation() <= seconds_in_day * 7.f) {
            groups.insert("�� ���� ������");
            vec.at(i).setGroup("�� ���� ������");
        }
        else if (vec.at(i).getTimeOfCreation() > seconds_in_day * 7.f && vec.at(i).getTimeOfCreation() <= seconds_in_day * 30.f) {
            groups.insert("� ���� ������");
            vec.at(i).setGroup("� ���� ������");
        }
        else if (vec.at(i).getTimeOfCreation() > seconds_in_day * 30.f && vec.at(i).getTimeOfCreation() <= seconds_in_day * 365.f) {
            groups.insert("� ���� ����");
            vec.at(i).setGroup("� ���� ����");
        }
        else {
            groups.insert("�����");
            vec.at(i).setGroup("�����");
        }
    }
}

static void createGroups(std::set<std::string>& groups, std::vector<Object>& vec, const char& type_of_sorting) {
    for (size_t i = 0; i < vec.size(); i++)
        switch (type_of_sorting) {
        case 'b':
            if (vec.at(i).getDistance() <= 100.f) {
                groups.insert("�� 100 e�.");
                vec.at(i).setGroup("�� 100 e�.");
            }
            else if (vec.at(i).getDistance() > 100.f && vec.at(i).getDistance() <= 1000.f) {
                groups.insert("�� 1000 e�.");
                vec.at(i).setGroup("�� 1000 e�.");
            }
            else if (vec.at(i).getDistance() > 1000.f && vec.at(i).getDistance() <= 10000.f) {
                groups.insert("�� 10000 e�.");
                vec.at(i).setGroup("�� 10000 e�.");
            }
            else {
                groups.insert("������� ������");
                vec.at(i).setGroup("������� ������");
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