# makes folders

IFS= read -r name < "deb-sh"

mkdir "$name folder"
mkdir "$name folder/DEBIAN"

mkdir "$name folder/usr"
mkdir "$name folder/usr/my_debs"

mkdir "$name folder/usr/share"
mkdir "$name folder/usr/share/applications"

cp -r "$name.desktop" "$name folder/usr/share/applications/$name.desktop"
cp -r "$name" "$name folder/usr/my_debs/$name"

# deletes file
rm -R "deb-sh"

echo "Package: $name
Version: 1.0
Architecture: all
Installed-Size: 1024
Maintainer: $name
Description: $name" >> "$name folder/DEBIAN/control"

dpkg-deb --build "$name folder"

mv "$name folder.deb" "$name.deb"

rm -R "$name folder"
rm -R "$name.desktop"

mkdir "results"

cp "$name.deb" "results/$name.deb"

rm -R "$name.deb"
rm -R "$name"

nautilus results

# printf "\033c"
