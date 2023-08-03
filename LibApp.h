#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
namespace sdds {
	class LibApp {
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;

	private:
		bool confirm(const char* message);
		void load();  
		void save();  
		void search();  
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp();
		void run();
	};
}
#endif // !SDDS_LIBAPP_H