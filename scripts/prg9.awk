BEGIN{print "record.\t characters \t words"}
#BODY section
{
len=length($0)
total_len =len
print(NR,":\t",len,":\t",NF,$0)
words =NF
}
END{
print("\n total")
print("characters :\t" total len)
print("lines :\t" NR)
}
