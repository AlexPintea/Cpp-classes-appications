#include <fstream>
#include "readme files/readme.h"

using namespace std;

string readme_string =  "# Name of application" 				"\n\n"
				        "__Name of application__ does that."	 "\n\n"
				        "Features:"	 							"\n"
				        "- "	 								 "\n"
				        "- "	 								"\n"
				        "- "	 								 "\n"
				   "\n" "Your features.";






int main () 
{
	readme( readme_string );

	return 0;
}
