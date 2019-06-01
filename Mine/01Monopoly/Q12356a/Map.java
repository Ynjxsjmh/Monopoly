import java.util.ArrayList;

public abstract class Map {
    protected Block[][] blockList;
	protected BlockFactory blockFactory;
    protected String name;

    public Map(BlockFactory blockFactory){
		this.blockFactory = blockFactory;
		initBlockList();
	}

    /**
	* œ‘ æMap
	*/
    public void show() {
        for (int i = 0; i < blockList.length; i++) {
			System.out.println();
            for (int j = 0; j < blockList[i].length; j++){
                System.out.print(blockList[i][j].toString());
            }
        }
    }

	protected abstract void initBlockList();
}