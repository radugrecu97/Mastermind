#include <iostream>
#include <bits/unique_ptr.h>
#include <Controller.h>
#include <menu_ids.h>
#include <status_codes.h>

int main() {
//    std::unique_ptr<IGameManager> gameManager(new GameManager());
//    gameManager->getSettingsManager()->setAllowDuplicates(false);
//    gameManager->getSettingsManager()->setAllowBlanks(true);
//
//    std::string code = "124A"; //gameManager->generateCode();
//    gameManager->setCode(code);
//    std::cout << "CODE: " << code << std::endl;
//
//    std::string guess = "Y*GO";
//    std::cout << "GUESS: " <<  guess << std::endl;
//    gameManager->setGuess(guess);
//    std::cout << "FEEDBACK: " << gameManager->generateFeedback() << std::endl;

    std::unique_ptr<IController> controller = std::make_unique<Controller>();
    controller->setMenu(menu_ids::MAIN_MENU, 0);
    system("clear");
    controller->updateView();
    while (1) {
        std::string input;
        std::cin >> input;
        controller->handleInput(input);
    }

    return 0;
}
