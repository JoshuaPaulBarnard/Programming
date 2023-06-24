package mainFiles;

import java.util.Random;

public class Weapon {
	//private Variables
	private double damage;
	private String name;
	private int requiredLevel;
	private int shotCapacityMax;
	private int shotCapacity;
	private double reloadTime;
	private double accuracy;
	private Random gen = new Random();
	
	//Constructors
	public Weapon() {
		damage = 0;
		name = "none";
		requiredLevel = 0;
		shotCapacityMax = 0;
		shotCapacity = shotCapacityMax;
		reloadTime = 0;
		accuracy = 0;
	}
	
	public Weapon(String n, double d, double rt, double a, int sc, int rl) {
		name = n;
		damage = d;
		reloadTime = rt;
		shotCapacityMax = sc;
		shotCapacity = shotCapacityMax;
		requiredLevel = rl;
		accuracy = a;
	}
	
	//Setters
	public void setDamage(double d) {
		this.damage = d;
	}
	
	public void setName(String n) {
		this.name = n;
	}
	
	public void setReqLevel(int rl) {
		this.requiredLevel = rl;
	}
	
	public void setShotCapacityMax(int shm) {
		this.shotCapacityMax = shm;
	}
	
	public void setShotCapacity(int sc) {
		this.shotCapacity = sc;
	}
	
	public void setReloadTime(double rt) {
		this.reloadTime = rt;
	}
	
	public void setAccuracy(double a) {
		this.accuracy = a;
	}
	
	//Getters
	public double getDamage() {
		return damage;
	}
	
	public String getName() {
		return name;
	}
	
	public int getReqLevel() {
		return requiredLevel;
	}
	
	public int getShotCapacityMax() {
		return shotCapacityMax;
	}
	
	public int getShotCapactiy() {
		return shotCapacity;
	}
	
	public double getReloadTime() {
		return reloadTime;
	}
	
	public double getAccuracy() {
		return accuracy;
	}
	
	//Methods
	
	public void reload() {
		long start = System.currentTimeMillis();
		while ((start - System.currentTimeMillis()) < (reloadTime * 1000)) {
		}
		shotCapacity = shotCapacityMax;
	}
	
	public boolean canShoot() {
		if (shotCapacity > 0) {
			return true;
		} else { 
			return false;
		}
	}
	
	public boolean doesHit() {
		shotCapacity--;
		int hit = (int)(gen.nextDouble() * 100) + 1;
		if (hit < ((int)(this.accuracy * 100) + 1)) {
			return true;
		} else { return false; }
	}
	
}
