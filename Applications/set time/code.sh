set_time ()
{
	l=$1
	len=`expr length "$l"`
	for (( i = 0; i < len; i = i + 1 ));
	do
		printf "${l:i:1}"
		sleep $2
	done
}

given=$( less -FX "$PWD/sh" )
rm -R "sh"
time=$( less -FX "$PWD/time" )
rm -R "time"
set_time "$given" $time
