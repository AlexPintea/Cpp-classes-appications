# makes folders

IFS= read -r name < "$PWD/deb-sh"

rm -R "$name"

mkdir "$name"
mkdir "$name/DEBIAN"

mkdir "$name/usr"
mkdir "$name/usr/my_debs"

mkdir "$name/usr/share"
mkdir "$name/usr/share/applications"

# deletes file
rm -R "$PWD/deb-sh"




echo "Package: $name
Version: 1.0
Architecture: all
Installed-Size: 1024
Maintainer: $name
Description: $name" >> "$PWD/$name/DEBIAN/control"
printf "\033c"
