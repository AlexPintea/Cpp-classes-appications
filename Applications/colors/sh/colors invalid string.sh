color ()
{
	line="\e["

	if [[ $2 == "b" ]]
	then
		$line = "$line1;"
	fi

	if [[ $2 == "d" ]]
	then
		$line = "$line2;"
	fi

	if [[ $2 == "i" ]]
	then
		$line = "$line3;"
	fi

	if [[ $2 == "u" ]]
	then
		$line = "$line4;"
	fi

	if [[ $2 == "l" ]]
	then
		$line = "$line9;"
	fi






	if [[ $3 == "bk" ]]
	then
		$line = "$line30m"
	fi

	if [[ $3 == "r" ]]
	then
		$line = "$line31m"
	fi

	if [[ $3 == "g" ]]
	then
		$line = "$line32m"
	fi

	if [[ $3 == "y" ]]
	then
		$line = "$line33m"
	fi

	if [[ $3 == "b" ]]
	then
		$line = "$line34m"
	fi

	if [[ $3 == "p" ]]
	then
		$line = "$line35m"
	fi

	if [[ $3 == "cy" ]]
	then
		$line = "$line36m"
	fi

	if [[ $3 == "gr" ]]
	then
		$line = "$line37m"
	fi

	if [[ $3 == "w" ]]
	then
		$line = "$line39m"
	fi




	if [[ $4 == "bk" ]]
	then
		$line = "$line3"
	fi

	if [[ $4 == "r" ]]
	then
		$line = "$line31m"
	fi

	if [[ $4 == "g" ]]
	then
		$line = "$line32m"
	fi

	if [[ $4 == "y" ]]
	then
		$line = "$line33m"
	fi

	if [[ $4 == "b" ]]
	then
		$line = "$line34m"
	fi

	if [[ $4 == "p" ]]
	then
		$line = "$line35m"
	fi

	if [[ $4 == "cy" ]]
	then
		$line = "$line36m"
	fi

	if [[ $4 == "gr" ]]
	then
		$line = "$line37m"
	fi

	if [[ $4 == "w" ]]
	then
		$line = "$line39m"
	fi
}

color "text" "bk"
color "text" "r"
color "text" "g"
color "text" "y"
color "text" "b"
color "text" "p"
color "text" "cy"
color "text" "gr"
color "text" "w"



 printf '\e[1;31m\e[43m%s\e[0m' "text"
