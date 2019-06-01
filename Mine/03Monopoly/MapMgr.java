public class MapMgr {
	public Map currentMap;

    protected static MapMgr uniqueMapMgr = new MapMgr();

    protected MapMgr() {
        
    }

    public static MapMgr getMapMgr(){
        //if (uniqueMenuMgr == null) {
        //    uniqueMenuMgr = new MenuMgr();
        //}
        return uniqueMapMgr;
    }

    public Map createMap(MapType mapType) {
        if (mapType == MapType.REGULARMAP) {
            MapBuilder commonMapBuilder = new CommonMapBuilder();
			MapDirector mapDirector = new MapDirector();
			currentMap = mapDirector.createMap(commonMapBuilder);
		}
		else if(mapType == MapType.SUNMAP) {
			MapBuilder commonMapBuilder = new CommonMapBuilder();
			MapDirector sunMapDirector = new SunMapDirector();
			currentMap = sunMapDirector.createMap(commonMapBuilder);
		} else if(mapType == MapType.FLAGMAP){
			MapBuilder commonMapBuilder = new CommonMapBuilder();
			MapDirector flagMapDirector = new FlagMapDirector();
			currentMap = flagMapDirector.createMap(commonMapBuilder);
		} else {
			currentMap = null;
		}
		return currentMap;
    }
}