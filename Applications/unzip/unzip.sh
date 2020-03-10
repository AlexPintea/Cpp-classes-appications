# unzips / unrars in a filepath

IFS= read -r filepath < "$PWD/unzip-ls"


# clears file "unzip-ls"
rm -r  "$PWD/unzip-ls"

cd $filepath


for d in *.zip
do
	unzip $d
done

for d in *.7z
do
	7z x $d
done

for d in *.xz
do
	tar xf $d
done

for d in *.rar
do
	unrar $d
done

printf "\033c"
