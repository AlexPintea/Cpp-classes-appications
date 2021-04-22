printf "Name: "
read name
printf "Features: "
read n

show="printf \"$name:\\n\\n\"\n\n"

for i in {1..$n}
do
	printf "Feature $i: "
	read feature
	printf "if [ \$choice = $i ]\n" >> "choices.sh"
	printf "then\n" >> "choices.sh"
	printf "	\$a=\"$feature\"\n" >> "choices.sh"
	printf "fi\n" >> "choices.sh"

	$show= "$show printf \"$i. $feature\\n\"\n"
done


