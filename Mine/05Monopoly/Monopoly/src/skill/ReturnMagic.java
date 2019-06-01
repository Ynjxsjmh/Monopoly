package skill;

import player.Player;

public class ReturnMagic extends Magic {
	// set the player back where it starts
	public ReturnMagic(Player executePlayer) {
		super(executePlayer);
		this.skillType = SkillType.MAGIC;
		this.magicName = MagicType.RETURN_MAGIC;
		this.skillName = this.magicName.toString();
	}

	@Override
	public void execute(int targetPlayerNum) {
		executePlayer.backHome();
	}
}
