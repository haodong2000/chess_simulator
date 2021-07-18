#include "vision_thread.h"

vision_thread::vision_thread()
{
    __isHumanReady = false;
}

void vision_thread::run() {
//    for(int i = 0; i < 100; i++) {
//        std::cout << i << std::endl;
//    }
    python_vision = new PythonMudule("vision");
    python_vision->run_TCP_vision();
}

//int vision_thread::get_human_step_from_vision(const QVector<chessStep> &curStepList) {
//    std::cout << "LLLLLLLLLLLLLLLL" << std::endl;
//    return python_vision->__generateHumanStep(curStepList);
//}
