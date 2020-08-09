# gets the size of a file


IFS= read -r filepath < "size-sh"
# clears file "cpp-sh"
rm -r  "size-sh"
# got to the filepath
FILESIZE=$(stat -c%s "$filepath")

echo $FILESIZE >> "size-sh"
