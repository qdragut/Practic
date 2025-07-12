#include <deque>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class GameModel {
private:
    std::deque<int> playerDeck;
    std::deque<int> computerDeck;
    bool gameOver;

public:
    GameModel() : gameOver(false) {}

    void initDecks() {
        int deck[36];
        for (int i = 0; i < 36; i++) {
            deck[i] = 6 + (i % 9);
        }

        srand(time(0));
        for (int i = 0; i < 36; i++) {
            int j = rand() % 36;
            std::swap(deck[i], deck[j]);
        }

        for (int i = 0; i < 18; i++) {
            playerDeck.push_back(deck[i]);
            computerDeck.push_back(deck[i + 18]);
        }
    }

    void playRound() {
        if (playerDeck.empty() || computerDeck.empty()) {
            gameOver = true;
            return;
        }

        int playerCard = playerDeck.front();
        int computerCard = computerDeck.front();

        if (playerCard > computerCard) {
            playerDeck.push_back(playerCard);
            playerDeck.push_back(computerCard);
        }
        else if (computerCard > playerCard) {
            computerDeck.push_back(playerCard);
            computerDeck.push_back(computerCard);
        }
        else {
            handleWar();
        }

        playerDeck.pop_front();
        computerDeck.pop_front();
    }

    void handleWar() {
        std::deque<int> tempDeck;
        tempDeck.push_back(playerDeck.front());
        tempDeck.push_back(computerDeck.front());

        if (playerDeck.size() < 2 || computerDeck.size() < 2) {
            gameOver = true;
            return;
        }

        tempDeck.push_back(playerDeck.front()); playerDeck.pop_front();
        tempDeck.push_back(computerDeck.front()); computerDeck.pop_front();

        int playerOpen = playerDeck.front();
        int computerOpen = computerDeck.front();

        if (playerOpen > computerOpen) {
            while (!tempDeck.empty()) {
                playerDeck.push_back(tempDeck.front());
                tempDeck.pop_front();
            }
        }
        else {
            while (!tempDeck.empty()) {
                computerDeck.push_back(tempDeck.front());
                tempDeck.pop_front();
            }
        }
    }

    bool isGameOver() const { return gameOver; }
    int getPlayerDeckSize() const { return playerDeck.size(); }
    int getComputerDeckSize() const { return computerDeck.size(); }
    int getPlayerTopCard() const { return playerDeck.front(); }
    int getComputerTopCard() const { return computerDeck.front(); }
};