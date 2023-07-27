# RTSP-Opencv-Threading-Experiments
Libraries used Opencv 4.5.5,Intel Threaded Building Blocks
# Commands for running the program
g++ RTSPTest1.cpp -o RTSPTest1 `pkg-config --cflags --libs opencv4` -lpthread -ltbb
# Commands for running the program
g++ RTSPTest2.cpp -o RTSPTest2 `pkg-config --cflags --libs opencv4` -lpthread -ltbb
