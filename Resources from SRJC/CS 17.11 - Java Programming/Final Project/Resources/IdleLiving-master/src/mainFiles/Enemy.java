package mainFiles;

public class Enemy {
	//Private Variables
	private String name;
	private int healthPoints;
	private int defensePoints;
	private int attackPoints;
	private double attackSpeed;
	private int xPointsReward;
	
	//Constructors
	public Enemy() {
		name = "Zombie";
		healthPoints = 10;
		defensePoints = 0;
		attackPoints = 2;
		attackSpeed = 1.5;
		xPointsReward = 10;
	}
	
	public Enemy(String n, int hp, int dp, int ap, double as, int xp) {
		name = n;
		healthPoints = hp;
		defensePoints = dp;
		attackPoints = ap;
		attackSpeed = as;
		xPointsReward = xp;
	}
	
	//Setters
	public void setName(String s) {
		this.name = s;
	}
	
	public void setHealthPoints(int hp) {
		this.healthPoints = hp;
	}
	
	public void setDefensePoints(int dp) {
		this.defensePoints = dp;
	}
	
	public void setAttackPoints(int ap) {
		this.attackPoints = ap;
	}
	
	public void setAttackSpeed(double as) {
		this.attackSpeed = as;
	}
	
	public void setXPointsReward(int xp) {
		this.xPointsReward = xp;
	}

	//Getters
	public String getName() {
		return this.name;
	}
	
	public int getHealthPoints() {
		return this.healthPoints;
	}
	
	public int getDefensePoints() {
		return this.defensePoints;
	}
	
	public int getAttackPoints() {
		return this.attackPoints;
	}
	
	public double getAttackSpeed() {
		return this.attackSpeed;
	}
	
	public int getXPointsReward() {
		return this.xPointsReward;
	}
	
	
	//Methods
	public void attackPlayer() {
		
	}
	
	public boolean isDead() {
		if (this.healthPoints < 0) {
			return true;
		} else { return false; }
	}
}
