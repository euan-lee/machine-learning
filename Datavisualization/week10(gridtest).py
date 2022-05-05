import matplotlib.pyplot as plt
import numpy as np


f = open("gird.txt",'r')
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
    y.append(haha[2])
    


for i in range(len(y)): 
    if y[i]=="1":
        plt.scatter(float(x1[i]),float(x2[i]),color="red")
   
    else:
        plt.scatter(float(x1[i]),float(x2[i]),color="blue")       
      
               
plt.show() 
f.close()
