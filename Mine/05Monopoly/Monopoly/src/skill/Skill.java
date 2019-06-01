package skill;

import player.Player;
import state.StateType;

public abstract class Skill {
	// Skill is only an abstract class which is used
	// to lower the complexity of Player.userSkill().
	// So the specific realization of Skill in his 
	// son class such as the constructor and execute function
	
	protected SkillType skillType;
	protected StateType stateType;
	protected String skillName;
	protected Player executePlayer;
	
	// Here shows the use of the Command Pattern
	public abstract void execute(int targetPlayerNum);

	public SkillType getSkillType() {
		return this.skillType;
	}
	
	public StateType getStateType() {
		return this.stateType;
	}
	
	public String getSkillName() {
		return this.skillName;
	}
	
	public void setExecutePlayer(Player executePlayer) {
		this.executePlayer = executePlayer;
	}
}
