printf "Name: "
read name
printf "Features: "
read n

code=""
show="printf \"$name:\\n\\n\""

for i in {1..$n}
do
	printf "Feature $i: "
	read feature
	$code=$code"if [ \$choice = $i ]\n"
	$code=$code"then\n"
	$code=$code"	\$a=\"$feature\"\n"
	$code=$code"fi\n"

	$show= "$show printf \"$i. $feature\\n\"\n"
done

printf "$show $code" >> "choices.sh"
