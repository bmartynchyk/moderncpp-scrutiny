
#include "virtual-explore.h"
#include "virtual-classes.h"

using namespace std;

void virtual_explore() {
	cout << "Called: virtual_explore\n";

	////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Example that shows how polymorph class call virtual function in constructor. In constructor
	// all virtual functions behave itself like non-vitual
	Professor p("Nickola", 45, "lector", "Microgrids"); 
}