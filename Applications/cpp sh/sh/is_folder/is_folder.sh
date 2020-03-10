# checks if a folder is at a certain filepath



IFS= read -r filepath < "$PWD/sh/cpp-sh"

# variable=$( command )

# clears file "cpp-sh"
rm -r  "$PWD/sh/cpp-sh"



# got to the filepath

is_folder="$(cd $filepath && ls && rm -r file)"

echo $is_folder >> "$PWD/sh/cpp-sh"
