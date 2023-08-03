#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include "Publication.h"
#include "Streamable.h"
#include "Utils.h"
#include "Date.h"

using namespace std;
namespace sdds {
    class Book : public Publication {
        char* author;
    public:
        Book();
        ~Book();
        Book(const Book& source);
        Book& operator=(const Book& source);
        char type() const override;
        ostream& write(ostream& os) const override;
        istream& read(istream& is) override;
        void set(int member_id) override;
        operator bool() const override;
    };
}
#endif