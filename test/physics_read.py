import numpy as np 
import os 

DATATYPE = np.float64
PATHTRUE = "./test_logs/testing_true.dat" #cwd is test 
PATHODE = "./test_logs/testing_ode.dat"


def main () : 

    data_true = read_doubles(PATHTRUE)
    data_ode = read_doubles(PATHODE)
    
    return 0


def read_doubles (path) : 

    data = np.fromfile (path, dtype = DATATYPE, count = -1)
    return data 



#if __name__ == "__main__" : 
    #main ()