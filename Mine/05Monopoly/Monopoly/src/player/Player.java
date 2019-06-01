package player;

import java.util.LinkedList;
import java.util.Scanner;
import java.util.Vector;

import state.NormalState;
import state.State;
import state.StateType;
import strategy.EqualMoveStrategy;
import strategy.MoveStrategy;
import visitor.Visitor;
import block.Block;
import game.Game;
import map.DirectionID;
import skill.Skill;

public abstract class Player {
	public int x;
	public int y;
	public int direction;
	public float money;
	protected int step;

	protected LinkedList<State> states = new LinkedList<State>();
	protected Vector<Skill> skillVector = new Vector<Skill>();
	protected MoveStrategy moveStrategy; // strategy should be initialized in the son class's cons

	protected int originalX;
	protected int originalY;
	protected int playerId;
	protected String playerName;
	protected String describe; // how to show the player in the map
	protected boolean isHuman;

	public Player(int id) {
		this.playerId = id;
		this.moveStrategy = new EqualMoveStrategy(this);
		this.isHuman = false;
		this.direction = DirectionID.DIR_DOWN;
		this.money = 10000; // initialize the money to $10000, everyone is the same
	}

	public abstract void doAction();

	public String getName() {
		return this.playerName;
	}

	public String show() {
		return this.describe;
	}

	public int getID() {
		return this.playerId;
	}

	public void backHome() {
		this.x = this.originalX;
		this.y = this.originalY;
	}

	public Block getCurrentBlock() {
		Block currentBlock = null;
		Vector<Block> blocks = Game.getGame().getCurrentMap().getBlockVector();
		for (Block tempBlock : blocks) {
			if ((tempBlock.getRow() == this.x) && (tempBlock.getCol() == this.y)) {
				currentBlock = tempBlock;
				break;
			}
		}
		return currentBlock;
	}

	public void move() {
		this.checkState();
		for (State state : states) {
			state.operate();
		}
		Game.getGame().check(); //
		moveStrategy.move();
	}

	public void goOnMoving(int step) {
		moveStrategy.setStep(step);
		moveStrategy.move();
		moveStrategy.setStep(this.step);
	}

	public void useSkill(Skill skill) {
		int targetPlayerID = 0;
		if (this.isHuman) {
			Game.getGame().getDevice().drawLn("\nplease input the target player id:");
			Scanner scanner = new Scanner(System.in);
			targetPlayerID = scanner.nextInt();
		}

		skill.execute(targetPlayerID);
		this.removeSkill(skill);
	}

	public void addSkill(Skill skill) {
		skillVector.add(skill);
	}

	public Vector<Skill> getSkillVector() {
		return this.skillVector;
	}
	
	private void removeSkill(Skill skill) {
		for (Skill tempSkill : this.skillVector) {
			if (tempSkill.getSkillName().equals(skill.getSkillName())) {
				this.skillVector.remove(tempSkill);
				break;
			}
		}
	}

	private void checkState() {
		// cause every state has a duration,
		// and the duration is always weighted by turn.
		// if the turn is larger than 0, this means state is lasting.
		// in the other hand, if the turn is smaller than 0, this
		// means state should be changed
		for (State state : states) {
			if (state.getTurn() <= 0) {
				states.remove(state);
			}
		}
		
		if (states.size() == 0) {
			// if there is no state in state queue, this means extra state 
			// affection has passed off. So it's time to back to normal state
			// key word 'this' in state constructor means current object
			// This means it is changed according to which object you instantiate
			states.add(new NormalState(this));
		}
	}

	public void addState(State state) {
		// when the Player is applied some skills,
		// new state should be added to the state queue
		if (states.size() == 1 && states.getFirst().getStateType().equals(StateType.NORMAL)) {
			states.clear();
		}
		states.add(state);
		
		if (state.getStateType().equals(StateType.NORMAL)) {
			// if the adding state is normal state, this means 
			// player uses a skill which can clear off all his 
			// state applied on him
			states.clear();
			states.add(new NormalState(this));
		}
	}
	
	public int getStep() {
		return this.step;
	}
	
	public MoveStrategy getMoveStrategy() {
		return moveStrategy;
	}
	
	public void setHuman(boolean isHuman) {
		this.isHuman = isHuman;
		if (isHuman) {
			// if set to Human
			this.step = 3;
			this.x = this.originalX = 0;
			this.y = this.originalY = 0;
			this.describe = "[" + this.playerId + "]";
		} else {
			this.step = 2;
			this.x = this.originalX = 1;
			this.y = this.originalY = 0;
			this.describe = "(" + this.playerId + ")";
		}
	}
	
	public boolean getIsHuman() {
		return isHuman;
	}
	
	public abstract void accept(Visitor visitor);
}
