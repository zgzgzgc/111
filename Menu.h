#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

using namespace std;
namespace sdds {
    const unsigned int MAX_MENU_ITEMS = 20;
    class MenuItem
    {
    private:
        char* content;
        friend class Menu;
        MenuItem(const char* input = nullptr);
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        ~MenuItem();
        friend std::ostream& operator<<(std::ostream& os, const MenuItem& item);
        operator bool() const;
        operator const char* () const;
        void display(std::ostream& os) const;

        
    };
    class Menu
    {
    private:
        MenuItem* title;
        MenuItem* menuItems[MAX_MENU_ITEMS];
        int menuItemCount;



    public:
        Menu(const char* input = nullptr);
        ~Menu();

        void displayMenu() const;
        unsigned int run() const;
        unsigned int operator~() const;

        Menu& operator<<(const char* menuItemContent);
        operator bool() const;
        operator int() const;
        operator unsigned int() const;
        friend std::ostream& operator<<(std::ostream& os, const Menu& menu);
        const char* operator[](int index) const;
    };
}
#endif