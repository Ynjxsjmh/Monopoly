package skill;

public class MagicMgr {
	
	private static MagicMgr uniqueMagicMgr = new MagicMgr();
	private Magic[] magics = new Magic[MagicType.values().length];

	private MagicMgr() {
		// All of the Magic's member variables connected with Player is null
		// So attention should be attached that Player should be set before use Magic.
		magics[MagicType.RETURN_MAGIC.ordinal()] = new ReturnMagic(null);
		magics[MagicType.FREEZE_MAGIC.ordinal()] = new FreezeMagic(null);
		magics[MagicType.HURT_MAGIC.ordinal()] = new HurtMagic(null);
	}
	
	public static MagicMgr getMagicMgr() {
		return uniqueMagicMgr;
	}
	
	public Magic getMagic(MagicType MagicType) {
		return magics[MagicType.ordinal()];
	}
}
