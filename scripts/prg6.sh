echo "enter directory name"
 read dir
 if [ -d $dir ]
 then
 echo "list of files in the directory"
 ls $dir
 else
 echo "enter proper directory name"
 fi
