import numpy as np 
import os 
import matplotlib.pyplot as plt 

DATATYPE = np.float64
PATH_VEL_TRUE = "velocity_true.dat" 
PATH_VEL_ODE = "velocity_ode.dat" 
PATH_POS_TRUE = "position_true.dat" 
PATH_POS_ODE = "position_ode.dat" 
FILENAME = "test_logs"
TIME_INC = 1.0/60.0 #see physics_test.c


def main () : 

    velocity_true = read_test (PATH_VEL_TRUE) 
    velocity_ode = read_test (PATH_VEL_ODE) 
    position_true = read_test (PATH_POS_TRUE) 
    position_ode = read_test (PATH_POS_ODE) 

    time = np.arange(0, len(velocity_true)) * TIME_INC

    plt.plot (time, velocity_true, label = "True")
    plt.plot (time, velocity_ode, label = "Approximation")  
    plt.xlabel ("Time (s)") 
    plt.ylabel ("Velocity Y (m/s)")
    plt.legend ()
    plt.show ()

    #should add something to calulate max error of approxiamtion from true

    return 0


def read_test (test_file) :
     
    script_dir = os.path.dirname (os.path.abspath(__file__))
    file_dir = os.path.join (script_dir, FILENAME)
    path = os.path.join (file_dir, test_file)
    data = np.fromfile (path, dtype = DATATYPE, count = -1)

    return data 
    


if __name__ == "__main__" : 
    main ()