#include <iostream>

class GameView {
public:
    static void showGameState(int playerCards, int computerCards) {
        std::cout << "\n=== Игра Пьяница ===" << std::endl;
        std::cout << "Ваши карты: " << playerCards << std::endl;
        std::cout << "Карты компьютера: " << computerCards << std::endl;
    }

    static void showCards(int playerCard, int computerCard) {
        std::cout << "Ваша карта: " << playerCard << std::endl;
        std::cout << "Карта компьютера: " << computerCard << std::endl;
    }

    static void showRoundResult(bool playerWon) {
        std::cout << (playerWon ? "Вы забираете карты!" : "Компьютер забирает карты!") << std::endl;
    }

    static void showWar() {
        std::cout << "СПОР! Выкладываем по дополнительной карте..." << std::endl;
    }

    static void showGameOver(bool playerWon) {
        std::cout << (playerWon ? "Поздравляем! Вы выиграли!" : "К сожалению, вы проиграли.") << std::endl;
    }

    static void waitForNextMove() {
        std::cout << "\nНажмите Enter для следующего хода...";
        std::cin.ignore();
        std::cin.get();
    }
};