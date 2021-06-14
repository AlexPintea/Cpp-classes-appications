string evl ( string a )
{
	ofstream fo;
	command_linux( "mkdir evl" );
	fo.open( "evl/evl.cpp" );
	fo.close(); // clear / make file

	fo.open( "evl/evl.cpp" );

	fo << "#include <string>\n#include <fstream>\n#include <iostream>\n#include <math.h>\n#include <string.h>\n\nusing namespace std;\n\nint main ()\n{\n";

	fo << "	ofstream fo;\n";
	fo << "	fo.open( \"evl-cpp\" );\n";
	fo << "	fo.close(); // clear file\n\n";

	fo << "	fo.open( \"evl-cpp\" );\n";
	fo << "	fo << " << a << ";\n";
	fo << "	fo.close();\n\n";

	fo << "	return 0;\n}";

	fo.close();

	command_linux( "cd evl && g++ -L a.out evl.cpp && ./a.out" );
	string result = get_file( "evl/evl-cpp" );
	command_linux( "rm -R 'evl'" );

	return result;
}
