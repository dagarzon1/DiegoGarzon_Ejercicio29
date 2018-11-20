import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import glob
import os

k = sorted(glob.glob("*.txt"))

for i in k:
    d = np.loadtxt(i, delimiter=',')
    plt.plot(d[:,0],d[:,1])
    
plt.savefig("advection.pdf")
