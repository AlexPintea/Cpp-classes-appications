#include <stdio.h>
#include "files/file.c"

char file[] = "filename is in file is that is files";


int main ()
{
	set_file ( "filename", file );


	return 0;
}
