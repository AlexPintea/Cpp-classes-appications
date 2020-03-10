# gives files in folder

ls_data=$( ls )

rm -R unzip-ls

echo $ls_data >> unzip-ls
