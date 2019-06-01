import java.util.ArrayList;

public class abstract Map {
    protected Block[][] blockList;
	protected BlockFactory blockFactory;
    private String name;
	
	public Map(BlockFactory blockFactory){
		this.blockFactory = blockFactory;
		initBlockList();
	}
	
	/**
	* 显示Map
	*/
    public void show() {
        for (int i = 0; i < blockList.length; i++) {
            for (int j = 0; j < blockList[i].length; j++){
                System.out.println(blockList.toString());
            }
        }
    }
	
	protected abstract initBlockList(){
	}
}