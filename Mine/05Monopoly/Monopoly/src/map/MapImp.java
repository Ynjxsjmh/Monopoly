package map;
import java.util.*;
import block.Block;
import block.WallBlock;
import game.Game;
import player.Player;

public class MapImp {
	protected Vector<Block> blocks;
	protected int row;
	protected int col;

	MapImp(int r, int c) {
		row = r;
		col = c;
		blocks = new Vector<Block>();
	}

	public void show() {
		Block[][] blockList = new Block[row][col];

		Block block = new WallBlock();
		for (int i = 0; i < blockList.length; i++){
			for (int j = 0; j < blockList[i].length; j++) {
				blockList[i][j] = block;
			}
		}

		for (Block specificBlock : blocks) {
			blockList[specificBlock.getRow()][specificBlock.getCol()] = specificBlock;
		}
		
		Queue<Player> players = Game.getGame().players;
		int[][] playerNumInBlock = new int[row][col];
		
		for (Player player : players) {
			playerNumInBlock[player.x][player.y] ++;
		}
		
		int maxNum = 0;
		int rowMax = 0;
		int colMax = 0;
		for (int i = 0; i < playerNumInBlock.length; i++) {
			for (int j = 0; j < playerNumInBlock[i].length; j++) {
				if (playerNumInBlock[i][j] > maxNum) {
					maxNum = playerNumInBlock[i][j];
					rowMax = i;
					colMax = j;
				}
			}
		}
		
		int tempMaxNum = maxNum;
		String indent = "";
		while (--tempMaxNum > 0) {
			indent += "   ";
		}
		
		for (int i = 0; i < blockList.length; i++) {
			System.out.println("\n");
            for (int j = 0; j < blockList[i].length; j++){
            	boolean flag = false;
            	for (Player player:players) {
            		if ((player.x == i) && (player.y == j)) {
            			System.out.print(player.show());
            			if (maxNum != 1 && (i != rowMax || j != colMax)) {
							System.out.print(indent);
						}
            			flag = true;
            		}
            	}
            	
            	if(!flag) {
            		System.out.print(" "+blockList[i][j].toString()+" "+indent);
            	}
            }
        }
	}

	public void addBlock(Block block) {
		blocks.add(block);
	}

	public Block getBlock(int index){
		return blocks.get(index);
	}

	public void setBlockVector(Vector<Block> blockVector) {
		blocks = blockVector;
	}
	
	public Vector<Block> getblockVector() {
		return blocks;
	}

	public int getRow() {
		return row;
	}

	public int getCol() {
		return col;
	}
}