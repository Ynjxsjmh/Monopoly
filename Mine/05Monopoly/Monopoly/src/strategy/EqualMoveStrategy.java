package strategy;

import java.util.Random;
import java.util.Vector;
import block.Block;
import block.BlockType;
import game.Game;
import map.DirectionID;
import player.Player;

public class EqualMoveStrategy extends MoveStrategy {
	// Each direction has the same possibility to go
	// inDir is NULL
	public EqualMoveStrategy(Player currentPlayer) {
		super(currentPlayer);
	}

	@Override
	public void move() {
		Block currentBlock = this.currentPlayer.getCurrentBlock();

		Block nextBlock = currentBlock;

		int currentDirection = this.currentPlayer.direction;
		int count = 0;

		while (true) {
			Vector<Integer> possibleDirection = new Vector<Integer>();
			for (int i = currentDirection; i < (currentDirection + DirectionID.DIR_COUNT - 1); i++) {
				int adjust = i;
				if (i > 4) {
					adjust = i - 4;
				}

				if (nextBlock.getNeighbor(adjust) != null) {
					possibleDirection.add(adjust);
				}
			}
			// if the possibleDirection contains the opposite direction, remove it
			// but if the possibleDirection only contains the opposite direction, remain it
			if ((possibleDirection.contains(Game.getGame().getDirectionMap().get(currentDirection)))
					&& (possibleDirection.size() > 1)) {
				possibleDirection.remove(Game.getGame().getDirectionMap().get(currentDirection));
			}

			int num = possibleDirection.size();
			int min = 1;
			Random random = new Random();
			int choose = random.nextInt(num) % (num - min + 1) + min;
			currentDirection = possibleDirection.get(choose - 1);

			nextBlock = nextBlock.getNeighbor(currentDirection);
			if (nextBlock.getBlockType().equals(BlockType.BAR_BLOCK)) {
				break;
			}

			count++;
			if (count >= this.step) {
				break;
			}
		}

		nextBlock.blockEffect(currentPlayer);
		currentPlayer.direction = currentDirection;
		currentPlayer.x = nextBlock.getRow();
		currentPlayer.y = nextBlock.getCol();
	}
}
