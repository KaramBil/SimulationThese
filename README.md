# Thesis Simulation with ns-3

This repository contains the simulation files used for the thesis, including a specific `.cc` file for ns-3.

## Prerequisites

Make sure to install the following packages before starting: 
sudo apt update
sudo apt install g++ python3 cmake ninja-build git gir1.2-goocanvas-2.0 python3-gi python3-gi-cairo python3-pygraphviz gir1.2-gtk-3.0 ipython3 tcpdump wireshark sqlite sqlite3 libsqlite3-dev qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools openmpi-bin openmpi-common openmpi-doc libopenmpi-dev doxygen graphviz imagemagick python3-sphinx dia imagemagick texlive dvipng latexmk texlive-extra-utils texlive-latex-extra texlive-font-utils libeigen3-dev gsl-bin libgsl-dev libgslcblas0 libxml2 libxml2-dev libgtk-3-dev lxc-utils lxc-templates vtun uml-utilities ebtables bridge-utils libboost-all-dev ccache



## Installing ns-3
Download ns-3 from the official website or via a mirror.

Extract the contents of the archive to your home directory.

Navigate to the extracted folder:  cd ns-allinone-3.41
Build ns-3 with examples and tests enabled: ./build.py --enable-examples --enable-tests
Test the ns-3 installation: ./ns3 run hello-simulator


##  Running the Simulation
Copy the .cc files (in this case, lr-wpan-data-energy.cc) to the scratch folder in ns-3: cp path/to/your/lr-wpan-data-energy.cc ns-allinone-3.41/ns-3.41/scratch/
Navigate back to the main ns-3 directory: cd ns-allinone-3.41/ns-3.41/
Run the simulation script:  ./ns3 run scratch/lr-wpan-data-energy.cc


## Visualizing Results
Once the script is run, .plt files will be generated in the ns-3.41 directory. You can plot these files using gnuplot. For example:  gnuplot ART-Energy-distance.plt

## Notes
Ensure that all necessary files are correctly placed in their appropriate directories before running the simulations.
Check file and directory permissions if you encounter any issues during script execution.
## Support
For any questions or issues, feel free to open an issue in this repository or contact the thesis author @ Karam.bilami@gmail.com 
