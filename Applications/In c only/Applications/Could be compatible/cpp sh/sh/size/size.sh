# gets the size of a file


IFS= read -r filepath < "$PWD/sh/cpp-sh"


# clears file "cpp-sh"
rm -r  "$PWD/sh/cpp-sh"



# got to the filepath

FILESIZE=$(stat -c%s "$filepath")

echo $FILESIZE >> "$PWD/sh/cpp-sh"
