package map;
public class FlagMap extends Map {
	/**
	* This Map looks like a flag.
	*
	*	A A A A A
	*	B   B   B 
	*	C   C C C
	*	D   D   D
	*	A A A A A B B B
	*/
    public FlagMap(MapImp aImp) {
		super(aImp);
        name = "FlagMap";
    }
}