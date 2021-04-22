color ()
{
	if [[ $2 == "bk" ]]
	then
		printf '\e[1;30m%-6s\e[m' "$1"	
	fi

	if [[ $2 == "r" ]]
	then
		printf '\e[1;31m%-6s\e[m' "$1"	
	fi

	if [[ $2 == "g" ]]
	then
		printf '\e[1;32m%-6s\e[m' "$1"	
	fi

	if [[ $2 == "y" ]]
	then
		printf '\e[1;33m%-6s\e[m' "$1"	
	fi

	if [[ $2 == "b" ]]
	then
		printf '\e[1;34m%-6s\e[m' "$1"	
	fi

	if [[ $2 == "p" ]]
	then
		printf '\e[1;35m%-6s\e[m' "$1"	
	fi

	if [[ $2 == "cy" ]]
	then
		printf '\e[1;36m%-6s\e[m' "$1"	
	fi

	if [[ $2 == "gr" ]]
	then
		printf '\e[1;37m%-6s\e[m' "$1"	
	fi

	if [[ $2 == "w" ]]
	then
		printf '\e[1;39m%-6s\e[m' "$1"	
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

