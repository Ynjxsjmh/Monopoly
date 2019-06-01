public class GameTestDrive {
	public static void main(String[] args){
        Game game = Game.getGame();
		game.init();
        game.run();
    }
}