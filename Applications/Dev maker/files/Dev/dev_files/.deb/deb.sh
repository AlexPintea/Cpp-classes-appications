# makes folders

IFS= read -r name < "deb-sh"

mkdir "$name folder"
mkdir "$name folder/DEBIAN"

mkdir "$name folder/usr"
mkdir "$name folder/usr/my_debs"

mkdir "$name folder/usr/share"
mkdir "$name folder/usr/share/applications"

cp -r "$name.desktop" "$name folder/usr/share/applications/$name.desktop"
if test -f "$name"
then
	cp -r "$name" "$name folder/usr/my_debs/$name"
else
	cp -r "a.out" "$name folder/usr/my_debs/$name"
fi

# deletes file
rm -R "deb-sh"

echo "Package: $name
Version: 1.0
Architecture: all
Installed-Size: 1024
Maintainer: $name
Description: $name" >> "$name folder/DEBIAN/control"

b=$( dpkg-deb --build "$name folder" )

mv "$name folder.deb" "$name.deb"

rm -R "$name folder"
rm -R "$name.desktop"
