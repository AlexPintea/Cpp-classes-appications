IFS= read -r filepath < "files-ls"

cd $filepath

ls_data=$( ls -m )

cd ../

rm -R files-ls

for value in $ls_data
do
	echo $value >> files-ls
done
