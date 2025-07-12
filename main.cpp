class GameModel;
class GameView;

class GameController {
private:
    GameModel model;

public:
    void startGame() {
        model.initDecks();

        while (!model.isGameOver()) {
            GameView::showGameState(model.getPlayerDeckSize(), model.getComputerDeckSize());
            GameView::waitForNextMove();

            model.playRound();

            if (!model.isGameOver()) {
                GameView::showCards(model.getPlayerTopCard(), model.getComputerTopCard());
                bool playerWon = model.getPlayerTopCard() > model.getComputerTopCard();
                GameView::showRoundResult(playerWon);
            }
        }

        GameView::showGameOver(model.getPlayerDeckSize() > 0);
    }
};

int main() {
    GameController controller;
    controller.startGame();
    return 0;
}