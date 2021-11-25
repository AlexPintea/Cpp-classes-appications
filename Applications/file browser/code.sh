
choice=""

# bash code.sh - compile

show()
{
	printf "[ Enter ] to continue: "
	read enter
}

get_choice() # only continous filenames ( !' ' )
{
	# show choices
	# clear
	# reset # resets, instead of clear ( really slow )  	printf "//// '$PWD' \\\\\\\\\\ \n"
	printf "\033c" # resets
	printf "$USER / 1. Home  / 2. Return / 3. Move Upwards / 4. Details / exit. Exits\n"
	printf "Path: '$PWD' \n"

	ls -p --

	printf "\n"
	printf "Enter you choice: "

	# get the choice
	# IFS= read -p "Enter description: " choice # gets choice with ' '
	read choice

	# if choice is not valid
	if [[ $choice != "1" ]] && [[ $choice != "2" ]] && [[ $choice != "3" ]] && [[ $choice != "4" ]] && [[ $choice != "exit" ]] 
	then

		FILE=$PWD/$choice

		# "\""$choice"\"" invalid
		if test -d "$FILE"
		then
			cd $choice
			return
		fi

		if test -f "$FILE"
		then
			printf "Edit file with gedit ( y / n ): "
			read gedit_choice
			if [ $gedit_choice = "y" ]
			then
				printf "gedit $choice" | bash
			fi
			return
		fi

		return
	fi


	# Home
	if  [[ $choice = "1" ]]
	then
		cd /home/$USER
		return
	fi

	# Return
	if  [[ $choice = "2" ]]
	then
		cd -
		return
	fi

	# Move
	if  [[ $choice = "3" ]]
	then
		cd ..
		return
	fi

	# Details
	if  [[ $choice = "4" ]]
	then
		ls -al
		show
		return
	fi


	# exit
	if  [[ $choice = "exit" ]]
	then
		return
	fi

}


# for value in {1..5}
# do
# 	printf $value
# done

while [[ $choice != "exit" ]]
do
	get_choice
done

printf "Exited.\n"
