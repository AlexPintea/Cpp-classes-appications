#include <stdio.h>
#include "readme maker files/readme_maker.c"

char readme_string[] = "# Readme of \"file\"\n\nFile does that.";


int main ()
{
	readme ( readme_string );


	return 0;
}
