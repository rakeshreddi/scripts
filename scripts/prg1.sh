if [ $# -eq 0 ]
then
echo no arguements

elif [ $# -eq 1 ]
then
echo one arguement

elif [ $# -eq 2 ]
then
echo two arguements
else
if [ ! -e $1 ]
then
echo file does not exist
else

sed -ne ''$2','$3' p' $1
fi
fi
