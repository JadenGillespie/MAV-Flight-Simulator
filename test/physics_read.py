import numpy as np 
import os 
import matplotlib.pyplot as plt 

DATATYPE = np.float64
PATHTRUE = "testing_true.dat" 
PATHODE = "testing_ode.dat" 
FILENAME = "test_logs"
TIME_INC = 1.0/60.0 #see physics_test.c
ITERS = 100 #see physics_test.c


def main () : 

    script_dir = os.path.dirname (os.path.abspath(__file__))
    file_dir = os.path.join (script_dir, FILENAME)

    true_path = os.path.join (file_dir, PATHTRUE)
    ode_path = os.path.join (file_dir, PATHODE)

    data_true = np.fromfile (true_path, dtype = DATATYPE, count = -1)
    data_ode = np.fromfile (ode_path, dtype = DATATYPE, count = -1)


    time = np.arange(0, ITERS * TIME_INC, TIME_INC) 

    plt.plot(time, data_true, label = "True")
    plt.plot(time, data_ode, label = "Approximation")  

    return 0

if __name__ == "__main__" : 
    main ()