BEGIN{
printf "the no of lines not contain vowels are:"
}!/[aA]|[eE]|[Ii]|[Oo]|[Uu]/{
k++
}
END{
printf "%d",k
}
