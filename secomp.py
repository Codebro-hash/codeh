Secomp = []
CktList = []
Bdmli = []
Ftblist = []

#Creating a function to accept the lists for all the games

def getData(n, list):
    for i in range(0,n):
        a = int(input("Enter the roll no:"))
        list.append(a)

#Accepting the dats by calling the function created above 
n = int(input("How many Students are there in SeComp?"))
getData(n, Secomp)

m = int(input("How many Students are there in cricket ?")) 
getData(m, CktList)

l = int(input("How many Students are there in Football ?")) 
getData(l, Ftblist)

p=int(input("How many students are there in Badminton ?")) 
getData(p,Bdmli)

#Que-01] List of students who play both Cricket and Badminton:
cbl = []
for i in CktList:
      if i in Bdmli:
        cbl.append(i)

print("\nAns 1", cbl, "\n")

#Que-02) List of students who play either Cricket or Badminton but not both
corbl= []
for i in CktList:
    if i not in Bdmli:
        corbl.append(i)

for j in Bdmli:
    if j not in CktList: 
        corbl.append(j)

print("Ans 2]", corbl, "\n")

#Que-03) List of students who play neither Cricket nor Badminton:

ftb = [] 
for i in Ftblist:
    if ((i not in CktList) and (i not in Bdmli)):
        ftb.append(i)

print("Ans 3", ftb, "\n")


# Que-04] Number of students who play Cricket and Football but not Badminton:
count = 0

for i in Secomp:
    if (i in CktList and i in Ftblist and i not in Bdmli):
        count += 1

print("Ans 4:", count)
