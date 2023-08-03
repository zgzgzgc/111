#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Publication.h"
#include "Lib.h"
#include "Date.h"
using namespace std;
namespace sdds {
    Publication::Publication() {
        m_title = nullptr; 
        m_membership = 0; 
        m_libRef = -1;
        m_shelfId[0]='\0';
        
    }


    Publication::Publication(const Publication& other) {

        m_membership = other.m_membership;
        m_libRef = other.m_libRef;
        m_date = other.m_date;
        if (other.m_title) {
            m_title = new char[strlen(other.m_title) + 1];
            strcpy(m_title, other.m_title);
        }
        else {
            m_title = nullptr;
        }

        strcpy(m_shelfId, other.m_shelfId);
    }

    Publication& Publication::operator=(const Publication& other) {
        if (this != &other) {
            delete[] m_title;
            if (other.m_title) {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            }
            else {
                m_title = nullptr;
            }

            strcpy(m_shelfId, other.m_shelfId);
            m_membership = other.m_membership;
            m_libRef = other.m_libRef;
            m_date = other.m_date;
        }
        return *this;
    }

    Publication::~Publication() {
        delete[] m_title;
    }


    void Publication::set(int member_id) {
        
            m_membership = member_id;
    }

    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date = Date();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return m_membership != 0;
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char* title) const {
        return strstr(m_title, title) != nullptr;
    }

    Publication::operator const char* () const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    bool Publication::conIO(ios& io) const{
        return (&io == &cin || &io == &cout);
    }

    ostream& Publication::write(ostream& os) const {
        if (conIO(os)) {
            os << "| ";
            os.width(4);
            os.setf(ios::left);
            os << m_shelfId << " | ";
            string Title(m_title);
            if (Title.length() > 30) {
                Title = Title.substr(0, 30);
            }
            os.width(30);
            os.fill('.');
            os << Title << " | ";         
            os.width(5);
            os.fill(' ');
            if (m_membership == 0) {
                os<< " N/A";
            }
            else {
                os << to_string(m_membership);
            } 
            os << " | " << m_date << " |"; 
        }
        else {
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title
                << "\t" << m_membership << "\t" << m_date; 
        }
        return os;
    }

    istream& Publication::read(istream& istr) {
        delete[] m_title;
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;

        char tmp_title[100] = "";
        char tmp_shelfId[5] = "";
        int tmp_membership = 0;
        int tmp_libRef = -1;
        Date tmp_date;

        if (conIO(istr)) { 
            cout << "Shelf No: ";
            istr.getline(tmp_shelfId, 5);
            if (strlen(tmp_shelfId) != 4) {
                istr.setstate(ios::failbit); 
                return istr;
            }

                cout << "Title: ";
                istr.getline(tmp_title,100);
                cout << "Date: ";
                tmp_date.read(istr);

        }
        else {
            istr >> tmp_libRef;
            istr.ignore(1, '\t');
            istr.getline(tmp_shelfId, 5,'\t');
            istr.getline(tmp_title, 100,'\t');
            istr >> tmp_membership;
            istr.ignore(1, '\t');

            tmp_date.read(istr);
          
        }
        if (tmp_date.errCode() != NO_ERROR) {
            istr.setstate(ios::failbit);
        }
        else {
            m_title = new char[strlen(tmp_title) + 1];
            strcpy(m_title, tmp_title);
            strcpy(m_shelfId, tmp_shelfId);
            set(tmp_membership);
            m_date = tmp_date;
            setRef(tmp_libRef);
        }
        return istr;
    }

    Publication::operator bool() const {
        return m_title && *m_title != '\0' && m_shelfId && *m_shelfId != '\0';
    }

}