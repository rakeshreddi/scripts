echo ENTER A NUMBER :
read n
echo THE FACTORIAL OF A GIVEN $n IS :
fact=1
i=1
while [ $i -le $n ]
do
fact=`expr $fact \* $i`
i=`expr $i + 1`
done
echo $fact
