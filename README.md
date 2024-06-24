sudo apt update

sudo apt install g++ python3 cmake ninja-build git gir1.2-goocanvas-2.0 python3-gi python3-gi-cairo python3-pygraphviz gir1.2-gtk-3.0 ipython3 tcpdump wireshark sqlite sqlite3 libsqlite3-dev qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools openmpi-bin openmpi-common openmpi-doc libopenmpi-dev doxygen graphviz imagemagick python3-sphinx dia imagemagick texlive dvipng latexmk texlive-extra-utils texlive-latex-extra texlive-font-utils libeigen3-dev gsl-bin libgsl-dev libgslcblas0 libxml2 libxml2-dev libgtk-3-dev lxc-utils lxc-templates vtun uml-utilities ebtables bridge-utils libxml2 libxml2-dev libboost-all-dev ccache

Download NS3 
Extract NS3 to home folder 
Move into NS3 folder : cd ns-allinone-3.41
Build the NS3 by : ./build.py --enable-examples --enable-tests
 
test ns3 by :  ./ns3 run hello-simulator

Copy the .cc files ( lr-wpan-data-energy.cc in this case) to the "--/ns3.41/scratch/ "  folder, then go back to "--/ns3.41/"  and run the script using the command : "./ns3 run script.cc"

Once the script runned, it is gonna generate some ".plt" files in the ns3.41/ folder, which should be plotted using for example the command : " gnuplot ART-Energy-distance.plt " 
