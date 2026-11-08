import numpy as np 
import os 

DATATYPE = np.float64
PATHTRUE = "testing_true.dat" 
PATHODE = "testing_ode.dat"
FILENAME = "test_logs"


def main () : 

    script_dir = os.path.dirname (os.path.abspath(__file__))
    file_dir = os.path.join (script_dir, FILENAME)

    true_path = os.path.join (file_dir, PATHTRUE)
    ode_path = os.path.join (file_dir, PATHODE)

    data_true = np.fromfile (true_path, dtype = DATATYPE, count = -1)
    data_ode = np.fromfile (ode_path, dtype = DATATYPE, count = -1)


    return 0


if __name__ == "__main__" : 
    main ()