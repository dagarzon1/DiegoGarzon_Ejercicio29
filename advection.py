import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import glob
import os

k = sorted(glob.glob("*.txt"))
j=0
for i in k:
    d = np.loadtxt(i, delimiter=',')
    plt.plot(d[:,0],d[:,1], label=str(j)+"")
    j+=1
    
plt.legend()
plt.savefig("advection.pdf")
