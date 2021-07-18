#include "vision_thread.h"

vision_thread::vision_thread()
{

}

void vision_thread::run() {
//    for(int i = 0; i < 100; i++) {
//        std::cout << i << std::endl;
//    }
    PythonMudule *python_vision = new PythonMudule("vision");
    python_vision->run_TCP_vision();
}
