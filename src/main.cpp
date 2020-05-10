#include <iostream>
#include <bits/unique_ptr.h>
#include <IGameManager.h>
#include <GameManager.h>


int main() {
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    gameManager->getSettingsManager()->setAllowDuplicates(false);
    gameManager->getSettingsManager()->setAllowBlanks(true);

    std::string code = "124A"; //gameManager->generateCode();
    gameManager->setCode(code);
    std::cout << "CODE: " << code << std::endl;

    std::string guess = "Y*GO";
    std::cout << "GUESS: " <<  guess << std::endl;
    gameManager->setGuess(guess);
    std::cout << "FEEDBACK: " << gameManager->generateFeedback() << std::endl;
    return 0;
}
