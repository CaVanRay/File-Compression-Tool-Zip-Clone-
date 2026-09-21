#include "cronchHeaders.h"


void optionsMenu(){
  
  bool cont = true;

  do {
    clearScreen();
    std::cout << std::endl;
    std::cout << " __________________________________________________________________ " << std::endl;
    std::cout << "|******   CCCC    R        OOOO     N    N    CCCC   H    H  ******|" << std::endl;
    std::cout << "|******  C    C   RRRR    O    O    NN   N   C    C  H    H  ******|" << std::endl;
    std::cout << "|****** C         R   R  O      O   N N  N  C        HHHHHH  ******|" << std::endl;
    std::cout << "|****** C         R      O      O   N  N N  C        H    H  ******|" << std::endl;
    std::cout << "|******  C    C   R       O    O    N   NN   C    C  H    H  ******|" << std::endl;
    std::cout << "|******   CCCC    R        OOOO     N    N    CCCC   H    H  ******|" << std::endl;
    std::cout << "|__________________________________________________________________|" << std::endl;
    std::cout << std::endl;
    std::cout << "                      PLEASE SELECT AN OPTION" << std::endl;
    std::cout << "                              1) COMPILE" << std::endl;
    std::cout << "                              2) DE-COMPILE" << std::endl;
    std::cout << "                              3) EXIT PROGRAM" << std::endl << std::endl;
    std::cout << "                              ";
    int selectedAction = getInt(": ");
    while (selectedAction < 1 || selectedAction > 3) {
        std::cout <<"                            INVALID SELECTION, TRY AGAIN" << std::endl;
        std::cout << "                              ";
        selectedAction = getInt(": ");
    }
    switch (selectedAction) {
      case 1:{
        clearScreen();
        cronchCompile();
        break;
      }
      case 2:{
        clearScreen();
        cronchDeCompile();
        break;
      }
      case 3:{
        clearScreen();
        cont = false;
        break;
      }
      default:{
       std:cout << std::endl << "ERROR: INVALID MENU CHOICE" << std::endl;
        break;
      }
    }
    
  } while (cont);
  
}
