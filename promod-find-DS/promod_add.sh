# Browse the entire kernel source for files and add logging statements before 
# RCU list statements using 'promod_add.awk'. 
# This is done to find the most accessed RCU-list DS in the Linux Kernel. 

function enterDir {
	echo $(pwd)
	cd ./$1/
	for fileX in ./*; do
		if [[ $fileX = *.c ]]; then
			gawk -f $2/promod_add.awk $fileX > ./temp
			mv ./temp $fileX
		fi

		if [[ $fileX = *.h ]]; then
			gawk -f $2/promod_add.awk $fileX > ./temp
			mv ./temp $fileX
		fi
				
		if [ -d $fileX ]; then enterDir $fileX $2; fi
	done
	cd ./../	
}

curDir=$(pwd)
enterDir '.' $curDir
