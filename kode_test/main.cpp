#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "Object.h"
#include "Group.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    std::fstream fs;
    std::vector<Object> list_of_objects;

    fs.open("Objects.txt", std::ios::in);
    while (!fs.eof()) {
        std::string s;

        while (std::getline(fs, s)) {
            Object object(s);
            list_of_objects.push_back(object);
        }
    }
    fs.close();

    for (auto object : list_of_objects)
        object.print();

    char type_of_input = '&';

    while (type_of_input != 'q') {
        std::cout << "\n";
        std::cout << "Выберите тип сортировки:" << std::endl;
        std::cout << "a) По времени создания \nb) По дистанции" << std::endl;
        std::cout << "c) По имени \nd) По типу" << std::endl;
        std::cin >> type_of_input;
        std::cout << "\n";

        switch (type_of_input) {
        case 'a': // Group by the time of the creation
            group(list_of_objects, 'a');
            break;
        case 'b': // Group by the distance
            group(list_of_objects, 'b');
            break;
        case 'c': // Group by the name
            group(list_of_objects, 'c');
            break;
        case 'd': // Group by the type
            group(list_of_objects, 'd');
            break;
        default:
            std::cout << "Такой вариант отсутсвует." << std::endl;
            continue;
        }

        std::cout << "Хотите ли вы сохранить изменения в файл?" << std::endl;
        std::cout << "a) Да \nb) Нет" << std::endl;
        std::cin >> type_of_input;


        switch (type_of_input) {
        case 'a':
            std::cout << "Хотите ли вы сохранить изменения в текущий файл?" << std::endl;
            std::cout << "a) Да \nb) Нет" << std::endl;

            std::cin >> type_of_input;

            switch (type_of_input) {
            case 'a':
                fs.open("Objects.txt", std::ios::out);
                if (fs.is_open())
                    for (auto object : list_of_objects)
                        fs << object.getName() << ' ' << object.getCoords().first << ' ' << object.getCoords().second << ' '
                        << object.getType() << ' ' << object.getTimeOfCreation() << std::endl;
                fs.close();

                std::cout << "Изменения были успешно сохранены." << std::endl;
                type_of_input = 'q';
                break;

            case 'b':
                std::string new_file = "";
                std::cout << "Пожалуйста, введите имя нового файла:" << std::endl;
                std::cin >> new_file;
                
                fs.open(new_file + ".txt", std::ios::out);
                if (fs.is_open())
                    for (auto object : list_of_objects)
                        fs << object.getName() << ' ' << object.getCoords().first << ' ' << object.getCoords().second << ' '
                        << object.getType() << ' ' << object.getTimeOfCreation() << std::endl;
                fs.close();

                std::cout << "Изменения были успешно сохранены в файл " << new_file + ".txt." << std::endl;
                type_of_input = 'q';
                break;
            }

            break;

        case 'b':
            std::cout << "Хотите ли вы продолжить сортировать данные?" << std::endl;
            std::cout << "a) Да \nb) Нет" << std::endl;

            std::cin >> type_of_input;

            switch (type_of_input) {
            case 'a':
                continue;
            case 'b':
                type_of_input = 'q';
                break;
            }
            break;
        }
    }

    return 0;
}
