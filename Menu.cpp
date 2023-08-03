#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"

using namespace std;
namespace sdds {
    MenuItem::MenuItem(const char* input) {
        if (input != nullptr) {
            content = new char[strlen(input) + 1];
            strcpy(content, input);
        }
        else {
            this->content = nullptr;
        }
    }

    MenuItem::~MenuItem() {
        delete[] content;
    }

    MenuItem::operator bool() const {
        return content != nullptr && strlen(content) > 0;
    }

    MenuItem::operator const char* () const {
        return content;
    }
    void MenuItem::display(std::ostream& os) const {
        if (content != nullptr) {
            os << content;
        }
    }

    Menu::Menu(const char* input) {
        if (input != nullptr) {
            title = new MenuItem(input);
        }
        else {
            title = nullptr;
        }

        for (int i = 0; unsigned(i) < MAX_MENU_ITEMS; ++i) {
            menuItems[i] = nullptr;
        }

        menuItemCount = 0;
    }
    std::ostream& operator<<(std::ostream& os, const MenuItem& item) {
        if (item.content != nullptr) {
            os << item.content;
        }
        return os;
    }

    Menu::~Menu() {
        delete title;
        for (int i = 0; i < menuItemCount; ++i) {
            delete menuItems[i];
        }
    }

    void Menu::displayMenu() const {
        if (title != nullptr) {
            cout << *title  << endl;
        }

        for (int i = 0; i < menuItemCount; ++i) {
            cout << " " << (i + 1) << "- " << *menuItems[i] << endl;
        }

        cout << " 0- Exit" << endl << "> ";
    }

    unsigned int Menu::run() const {
        unsigned int selection;
        bool valid;
        displayMenu();
        cin >> selection;
        do {             
            valid = cin.good() && selection >= 0 && selection <= unsigned(menuItemCount);
            if (!valid) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid Selection, try again: ";
                cin >> selection;
            } 
        } while (!valid);
        return selection;
    }
    unsigned int Menu::operator~() const {
        return run();
    }
    Menu& Menu::operator<<(const char* menuItemContent) {
        if (unsigned(menuItemCount) < MAX_MENU_ITEMS) {
            menuItems[menuItemCount] = new MenuItem(menuItemContent);
            ++menuItemCount;
        }

        return *this;
    }

    Menu::operator bool() const {
        return menuItemCount > 0;
    }

    Menu::operator int() const {
        return menuItemCount;
    }

    Menu::operator unsigned int() const {
        return static_cast<unsigned int>(menuItemCount);
    }

    std::ostream& operator <<(std::ostream& os, const Menu& menu) {
        if (menu.title) {
            os << *menu.title;
        }
        return os;
    }

    const char* Menu::operator[](int index) const {
        if (menuItemCount > 0) {
            int loopedIndex = index % menuItemCount;
            return *menuItems[loopedIndex];
        }
        return nullptr;
    }
}