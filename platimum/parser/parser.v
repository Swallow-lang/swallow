import tokenizer
mut a:='
import os
os.system("hi")
a=True
cons b= False
a=None
def main():
    PRINT "hi"
    PRINT 2+9
    PRINT 2-9
    PRINT 2*9
    PRINT 2.8/9
    PRINT 2^9
    PRINT 2//9
    PRINT 2%9
def print(str)
    PRINT str
k=3
if k==3 or k>3 or k<3 or k!=3 or k>=4 or k<=3:
    PRINT "fd hi"
elif k==0 and k==1:
    print("s")
else:
    print(9.0)'
k:=tokenizer.tokenize(a)
println(tokenizer.process_tokens(k))