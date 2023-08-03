#ifndef SDDS_LIB_H__
#define SDDS_LIB_H__
#include <iostream>
using namespace std;
namespace sdds {
    class Streamable {
    public:
        virtual ostream& write(ostream& os) const = 0; 
        virtual istream& read(istream& is) = 0; 
        virtual bool conIO(ios& io) const = 0; 
        virtual operator bool() const = 0;
        virtual ~Streamable() = default;
    };

    ostream& operator<<(ostream&, const Streamable&);
    istream& operator>>(istream&, Streamable&);
}
#endif