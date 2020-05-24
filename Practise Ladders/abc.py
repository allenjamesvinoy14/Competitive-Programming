l=lis
s="BGGBG"
for _ in range(l[2]):
    for i in range(len(s)):
        if(s[i:i+2]=="BG"):
            s[i:i+2]="GB"
        
