import matplotlib.pyplot as plt
import numpy as np


f = open("data.txt",'r')
x1=[]
x2=[]
y=[]

plt.xlabel('X1-Axis')
plt.ylabel('X2-Axis')
plt.grid(True)

while True:
    line = f.readline()
    if not line: break
    haha=line.split()
    x1.append(haha[0])
    x2.append(haha[1])
    
f2= open("result.txt",'r')    
while True:
    line2 = f2.readline()
    if not line2: break
    x=line2.split()
    y.append(x[0])


for i in range(len(y)): 
    if y[i]=="1":
        plt.scatter(float(x1[i]),float(x2[i]),color="red")
        print("it is 1")
    else:
        plt.scatter(float(x1[i]),float(x2[i]),color="blue")       
        print("it is 0")
               
plt.show() 
f2.close()
f.close()
