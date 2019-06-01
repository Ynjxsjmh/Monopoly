import java.util.*;

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

		for (int i = 0; i < blockList.length; i++) {
			System.out.println();
            for (int j = 0; j < blockList[i].length; j++){
                System.out.print(blockList[i][j].toString());
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

	public int getRow() {
		return row;
	}

	public int getCol() {
		return col;
	}
}