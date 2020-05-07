file1=$1
 shift 1
 exec<$file1
  while read li
 do
   echo "$li:"
   grep -c "$li" $@
 done

