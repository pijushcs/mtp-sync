# Read File and add printk log statement before each occurence of RCU list additions 
# to keep track of the most accessed RCU-list datastructure in the Kernel. 

BEGIN {
	FS=" "
	tmp=""
}

$0 ~ /\#define.*/ {
	print $0
	$0="PROMOD_AWK_TEMP_EXIT"
} 

$0 ~ /.*list_add_rcu\(.*\);/ {
	tmp=$0
	gsub(/^.*_rcu\(/,"",tmp)
	gsub(/\);.*/,"",tmp)
	printf "printk(\"[promod] SRCU: %s\\n\"); ", tmp
}

$0 ~ /.*hlist_add_head_rcu\(.*\);/ {
	tmp=$0
	gsub(/^.*_rcu\(/,"",tmp)
	gsub(/\);.*/,"",tmp)
	printf "printk(\"[promod] HRCU: %s\\n\"); ", tmp
}

$0 ~ /.*list_add_tail_rcu\(.*\);/ {
	tmp=$0
	gsub(/^.*_rcu\(/,"",tmp)
	gsub(/\);.*/,"",tmp)
	printf "printk(\"[promod] QRCU: %s\\n\"); ", tmp
}

$0 !~ "PROMOD_AWK_TEMP_EXIT" {
	print $0
}
 
END {

}
