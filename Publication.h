#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__
#include <iostream>
#include <cstring>
#include "Streamable.h"
#include "Date.h"
#include "Lib.h"
using namespace std;
namespace sdds {
    class Publication : public Streamable {
        char* m_title;
        char m_shelfId[5];
        int m_membership;
        int m_libRef;
        Date m_date;
    public:
        Publication();

        Publication(const Publication& other); 
        Publication& operator=(const Publication& other);
        virtual ~Publication();

        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();

        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char* () const;
        int getRef() const;

        bool conIO(ios& io) const override;
        ostream& write(ostream& os) const;
        istream& read(istream& istr);
        operator bool() const override;
    };
}
#endif