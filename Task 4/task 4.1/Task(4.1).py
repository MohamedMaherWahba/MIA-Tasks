import random
 
 
class Villain:
    def __init__(self, name):
        self.name = name
        self.health = 100
        self.energy = 500
        self.shield = 0
 
    def attack(self, weapon, opponent):
        if self.energy >= weapon.energy:
            self.energy -= weapon.energy
            opponent.defend(weapon.damage)
        else:
            print(f"{self.name} doesn't have enough energy to use {weapon.name}.")
 
    def defend(self, damage):
        if self.shield > 0:
            reduced_damage = damage * (1 - self.shield)
            self.health -= reduced_damage
            print(f"{self.name} used a shield and reduced the damage.")
        else:
            self.health -= damage
            print(f"{self.name} received {damage} damage.")
 
    def display_status(self):
        print(f"{self.name}'s Health: {self.health}")
        print(f"{self.name}'s Energy: {self.energy}")
        print(f"{self.name}'s Shield: {self.shield}")
 
 
class Weapon:
    def __init__(self, name, energy, damage, resources):
        self.name = name
        self.energy = energy
        self.damage = damage
        self.resources = resources
 
 
class Shield:
    def __init__(self, name, energy, save, resources):
        self.name = name
        self.energy = energy
        self.save = save
        self.resources = resources
 
 
class GruWeapon(Weapon):
    def __init__(self, name, energy, damage, resources, description):
        super().__init__(name, energy, damage, resources)
        self.description = description
 
 
class GruShield(Shield):
    def __init__(self, name, energy, save, resources, description):
        super().__init__(name, energy, save, resources)
        self.description = description
 
 
class VectorWeapon(Weapon):
    def __init__(self, name, energy, damage, resources, description):
        super().__init__(name, energy, damage, resources)
        self.description = description
 
 
class VectorShield(Shield):
    def __init__(self, name, energy, save, resources, description):
        super().__init__(name, energy, save, resources)
        self.description = description
 
 
def play_game():
    gru = Villain("Gru")
    vector = Villain("Vector")
 
    freeze_gun = GruWeapon(
        "Freeze Gun",
        50,
        11,
        float("inf"),
        "Minions occasionally wield freeze ray guns that shoot a freezing beam to immobilize opponents temporarily.",
    )
    electric_prod = GruWeapon(
        "Electric Prod",
        88,
        18,
        5,
        "Minions might use electric prods to deliver mild shocks to enemies, stunning them momentarily.",
    )
    mega_magnet = GruWeapon(
        "Mega Magnet",
        92,
        10,
        3,
        "Minions utilize a mega magnet to attract or repel metal objects, potentially disrupting enemy vehicles or equipment.",
    )
    kalman_missile = GruWeapon(
        "Kalman Missile",
        120,
        20,
        1,
        "This unavoidable Missile created for enormous distraction",
    )
 
    energy_projected_barrier_gun = GruShield(
        "Energy Projected Barrier Gun",
        20,
        0.4,
        float("inf"),
        "The spaceship's shields create an invisible, energy-projected barrier around the vehicle. This barrier absorbs and dissipates energy-based attacks such as lasers, beams, and plasma shots.",
    )
    selective_permeability = GruShield(
        "Selective Permeability",
        50,
        0.9,
        2,
        "The shields can be programmed to allow certain objects, signals, or energies to pass through while blocking others. This can be useful for communication or specific tactical maneuvers.",
    )
 
    laser_blasters = VectorWeapon(
        "Laser Blasters",
        40,
        8,
        float("inf"),
        " Vector's primary weapon would be powerful laser blasters attached to his flying pod. These blasters emit focused energy beams that can slice through obstacles and damage enemy vehicles.",
    )
    plasma_grenades = VectorWeapon(
        "Plasma Grenades",
        56,
        13,
        8,
        "Vector could use plasma grenades that explode on impact, releasing fiery energy bursts that deal significant damage to enemy vehicles caught in the blast radius.",
    )
    sonic_resonance_cannon = VectorWeapon(
        "Sonic Resonance Cannon",
        100,
        22,
        3,
        "Fires powerful sonic waves that can shatter enemy shields and disrupt their systems, temporarily incapacitating them.",
    )
 
    energy_net_trap = VectorShield(
        "Energy Net Trap",
        15,
        0.32,
        float("inf"),
        "Vector's pod might have the ability to deploy an energy net that ensnares enemy vehicles, temporarily immobilizing them and leaving them vulnerable to Vector's other attacks.",
    )
    quantum_deflector = VectorShield(
        "Quantum Deflector",
        40,
        0.8,
        3,
        "Manipulates quantum states to create a deflection field, causing enemy projectiles to miss the spaceship by a slight margin in the quantum realm.",
    )
 
    villains = [gru, vector]
 
    round_count = 1
    while True:
        print(f"Round {round_count}")
        print("-----------")
 
        for villain in villains:
            print(f"{villain.name}'s Turn")
            print("----------------")
 
            weapon = random.choice(
                [freeze_gun, electric_prod, mega_magnet, kalman_missile]
            )
            shield = (
                random.choice([energy_projected_barrier_gun, selective_permeability])
                if villain == gru
                else random.choice([energy_net_trap, quantum_deflector])
            )
 
            villain.attack(weapon, vector)
            vector.display_status()
 
            if vector.health <= 0:
                print(f"{gru.name} wins!")
                return
 
            villain.display_status()
            print("----------------")
 
        round_count += 1
 
 
play_game()