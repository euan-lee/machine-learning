import matplotlib.pyplot as plt
import numpy as np


f = open("result.txt",'r')
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
    

for i in range(len(x1)): 
   
    plt.scatter(float(x1[i]),float(x2[i]),color="red")
   
               
plt.show() 
f.close()
