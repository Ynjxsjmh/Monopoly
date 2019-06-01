package strategy;

import java.util.Random;
import java.util.Vector;

import block.Block;
import game.Game;
import map.DirectionID;
import player.Player;

public class DifferentMoveStrategy extends MoveStrategy {
	// Each direction has the different possibility to go
	// inDir is not NULL
	// rules are as follow:
	// 
	public DifferentMoveStrategy(Player currentPlayer) {
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
					adjust = i-4;
				}
				
				if (nextBlock.getNeighbor(adjust) != null) {
						possibleDirection.add(adjust);
				}
			}
			// if the possibleDirection contains the opposite direction, remove it.
			if ((possibleDirection.contains(Game.getGame().getDirectionMap().get(currentDirection)))
					&& (possibleDirection.size()>1)) {
				possibleDirection.remove(Game.getGame().getDirectionMap().get(currentDirection));
			}
			int num = possibleDirection.size();
			int min = 1;

			Random random = new Random();
			int possibility = random.nextInt(100);
			
			if (possibleDirection.contains(currentDirection)) {
				if (num == 3) {
					if (possibility < 50) {
						break;
					} else {
						possibleDirection.remove(currentDirection);
						num = possibleDirection.size();
						currentDirection = possibleDirection.get(random.nextInt(num)%(num-min+1) + min-1);
					}
				} else if (num == 2) {
					if (possibility < 60) {
						break;
					} else {
						possibleDirection.remove(currentDirection);
						num = possibleDirection.size();
						currentDirection = possibleDirection.get(random.nextInt(num)%(num-min+1) + min-1);
					}
				}
			} else {
				// if current direction is not available, other direction gets the same possibility
				currentDirection = possibleDirection.get(random.nextInt(num)%(num-min+1) + min-1);
			}

			nextBlock = nextBlock.getNeighbor(currentDirection);
			if (nextBlock.blockEffect(currentPlayer)) {
				break;
			}
			
			count++;
			if (count == this.step) {
				break;
			}
		}
		
		nextBlock.blockEffect(currentPlayer);
		currentPlayer.direction = currentDirection;
		currentPlayer.x = nextBlock.getRow();
		currentPlayer.y = nextBlock.getCol();
	}
}
