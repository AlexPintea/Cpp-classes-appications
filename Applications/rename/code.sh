IFS= read -r filepath < "files-ls"

cd $filepath

ls_data=$( ls -m )

cd ../

rm -R files-ls

echo $ls_data >> files-ls
