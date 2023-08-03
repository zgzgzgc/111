#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "Book.h"
#include "Streamable.h"
#include "Utils.h"
#include "Date.h"

using namespace std;
namespace sdds {
	Book::Book() : Publication() {
		author = nullptr;
	}

	Book::Book(const Book& other) : Publication(other) {

		if (other.author) {
			author = new char[strlen(other.author) + 1];
			strcpy(author, other.author);
		}
		else {
			author = nullptr;
		}
	}
	Book& Book::operator=(const Book& other) {
		if (this != &other) {
				delete[] author;
			if (other.author) {
				author = new char[strlen(other.author) + 1];
				strcpy(author, other.author);
			}
			else {
				author = nullptr;
			}	
			Publication::operator=(other);
		}
		return *this;
	}

	Book::~Book() {
			delete[] author;
	}
	char Book::type() const {
		return 'B';
	}
	ostream& Book::write(ostream& os) const {
		Publication::write(os);
		if (conIO(os)) {
			os << " ";

			string authorName(author);
			if (authorName.length() >15) {
				authorName = authorName.substr(0, 15);
			}
			os.width(15);
			os << authorName;

			os << " |";
		}
		else {

			os << "\t";
			os << author;
		}

		return os;
	}
	istream& Book::read(istream& istr) {

		Publication::read(istr);

		delete[] author;
		author = nullptr;

		char tmp_author[257] = "";

		if (conIO(istr)) {
			istr.ignore(1, '\n');
			cout << "Author: ";
			istr.get(tmp_author, 257);
		}
		else {
			istr.ignore(1,'\t');
			istr.get(tmp_author, 257);
		}
		if (!istr.fail()) {
			author = new char[strlen(tmp_author) + 1];
			strcpy(author, tmp_author);
		}

		return istr;
	}
	void Book::set(int member_id) {
		Publication::set(member_id);
		resetDate();
	}
	Book::operator bool() const {
		return author && *author != '\0' && Publication::operator bool();
	}
}