#include "LibApp.h"
using namespace std;
namespace sdds {
	bool LibApp::confirm(const char* message) {
		Menu confirmMenu(message);
		confirmMenu << "Yes";
		if (confirmMenu.run() == 1) {
			return true;
		}
		return false;		
	}
	void LibApp::load() {
		cout << "Loading Data" << endl;
	}
	void LibApp::save() {
		cout << "Saving Data" << endl;
	}
	void LibApp::search() {
		cout << "Searching for publication" << endl;
	}
	void LibApp::returnPub() {
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	}
	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;
		if (confirm("Add this publication to library?") == true) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
	}
	void LibApp::removePublication() {
		cout << "Removing publication from library" << endl;
		search();
		if (confirm("Remove this publication from the library?") == true) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}
	void LibApp::checkOutPub() {
		search();
		if (confirm("Check out publication?") == true) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}
	LibApp::LibApp()
		: m_changed(false),
		m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?")
	{
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library"; 
		m_mainMenu << "Return publication to library";
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		load();
	}
	void LibApp::run() {
		bool done = false;
		while (!done) {
			unsigned int selection = m_mainMenu.run();
			if (selection == 1) {
				newPublication();
			}
			else if (selection == 2) {
				removePublication();
			}
			else if (selection == 3) {
				checkOutPub();
			}
			else if (selection == 4) {
				returnPub();
			}
			else {
				if (m_changed) {
					unsigned int exitSelection = m_exitMenu.run();
					if (exitSelection == 1) {
						save();
						done = true;
					}
					else if (exitSelection == 2) {
						done = false;
					}
					else {
						if (confirm("This will discard all the changes are you sure?")) {
							done = true;
						}
					}					
				}
				else {
					done = true;				
				}				
			}
			cout << endl;
		}
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}
  }