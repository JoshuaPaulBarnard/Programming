package mainFiles;

public class Player {
	//private variables
	private String firstName;
	private String lastName;
	private String fullName;
	private int level;
	private int xPoints;
	private int selectedSlot; //Should only ever be 1, 2, or 3
	private int healthPoints;
	private boolean isMale;
	private int[] traitAmount = {10, 10, 10, 10, 10};
	private String[] traitName = {"Strength", "Inteligence", "Speech", "Luck", "Skill"};
	private Weapon w1;
	private Weapon w2;
	
	//Constructors
	Player() {
		firstName = "John";
		lastName = "Smith";
		fullName = firstName + " " + lastName;
		level = 1;
		xPoints = 0;
		selectedSlot = 1;
		healthPoints = 100;
		isMale = true;
	}
	
	Player( String fname, String lname, boolean m ) {
		firstName = fname;
		lastName = lname;
		fullName = firstName + " " + lname;
		healthPoints = 100;
		level = 1;
		xPoints = 0;
		selectedSlot = 1;
		isMale = m;
	}
	
	//Setters
	public void setFirstName(String fname) {
		this.firstName = fname;
		this.createFullName();
	}
	
	public void setLastName(String lname) {
		this.lastName = lname;
		this.createFullName();
	}
	
	public void setLevel(int l) {
		this.level = l;
	}
	
	public void setXPoints(int x) {
		this.xPoints = x;
	}
	
	public void setTraitAmount(int st, int in, int sp, int lu, int sk) {
		this.traitAmount[0] = st;
		this.traitAmount[1] = in;
		this.traitAmount[2] = sp;
		this.traitAmount[3] = lu;
		this.traitAmount[4] = sk;
	}
	
	public void setSelectedSlot(int s) {
		if (s > 3 || s < 0) {
			System.out.println("Error");
		} else {
			this.selectedSlot = s;
		}
	}
	
	public void setHealthPoints(int hp) {
		this.healthPoints = hp;
	}
	
	public void setIsMale(boolean m) {
		this.isMale = m;
	}
	
	//Getters
	public String getFirstName() {
		return this.firstName;
	}
	
	public String getLastName() {
		return this.lastName;
	}
	
	public String getFullName() {
		return this.fullName;
	}
	
	public int getLevel() {
		return this.level;
	}
	
	public int getXPoints() {
		return this.xPoints;
	}
	
	public int[] getTraitAmount() {
		return this.traitAmount;
	}
	
	public String[] getTraitName() {
		return this.traitName;
	}
	
	public int getSelectedSlot() {
		return this.selectedSlot;
	}
	
	public int getHealthPoints() {
		return this.healthPoints;
	}
	
	public boolean getIsMale() {
		return isMale;
	}
	
	//Methods
	private void createFullName() {
		this.fullName = this.firstName + " " + this.lastName;
	}
	
	public void collectWeapon(int sl, String n, double d, double rt, double a, int sc, int rl) {
		if (this.level >= rl) {
			if (sl == 1) {
				w1 = new Weapon(n, d, rt, a, sc, rl);
				System.out.println("The weapon " + w1.getName() + " was added to slot 1.");
			} else if (sl == 2) {
				w2 = new Weapon(n, d, rt, a, sc, rl);
				System.out.println("The weapon " + w2.getName() + " was added to slot 2.");
			} else {
				System.out.println("Error, item not added to either slot 1 or 2. Please try again!");
			}
		} else { 
			System.out.println("You can't collect this weapon! You don't have a high enough level!");
		}
	}
	
	public void attack(Enemy e) {
		if (this.selectedSlot == 1) {
			if (w1.canShoot()) {
				if (w1.doesHit()) {
					int damage = (int)((w1.getDamage() * (this.traitAmount[0] - 9)) - e.getDefensePoints()); //Equation for damage
					e.setHealthPoints(e.getHealthPoints() - damage);
					System.out.println("You hit the " + e.getName() + " for " + damage + " health points.");
					if (e.isDead()) {
						this.xPoints = this.xPoints + e.getXPointsReward();
						this.canLevelUp();
						System.out.println("You killed the " + e.getName() + " and received " + e.getXPointsReward() + " experience points as a reward!");
						e = null;
					} else {
						System.out.println("You missed!");
					}
				}
			} else {
				System.out.println("You have no bullets!");
			}
		} else if (this.selectedSlot == 2){
			if (w2.canShoot()) {
				if (w2.doesHit()) {
					int damage = (int)((w2.getDamage() * (this.traitAmount[0] - 9)) - e.getDefensePoints());
					e.setHealthPoints(e.getHealthPoints() - damage);
					System.out.println("You hit the " + e.getName() + " for " + damage + " health points.");
					if (e.isDead()) {
						this.xPoints = this.xPoints + e.getXPointsReward();
						this.canLevelUp();
						System.out.println("You killed the " + e.getName() + " and received " + e.getXPointsReward() + " experience points as a reward!");
						e = null;
					}
				} else {
					System.out.println("You missed!");
				}
			} else {
				System.out.println("You have no bullets!");
			}
		} else {
			//To make hand weapons
		}
	}
	
	public void canLevelUp() {
		//Make level up files
	}
	
	public boolean isDead() {
		if (this.healthPoints < 0) {
			return true;
		} else { return false; }
	}
}