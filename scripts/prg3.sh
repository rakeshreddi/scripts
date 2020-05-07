if [ $# -eq 0 ]
then
echo NO ARGUMENTS
else
for fname in $*
do
if [ -f $fname ]
then
echo $fname IS A REGULAR FILE
count=`wc -l $fname`
echo NUMBER OF LINES IN $fname ARE :
echo $count
else
echo $fname IS A DIRECTORY FILE
fi
done
fi
