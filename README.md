In this module I had to demonstrate inheritance in C++98 OOP. I had to structure my files as header files and source files.  

# TASKS

---

**Ex00:**

Implement a class called ClapTrap that will have the following private attributes initialized
to the values specified in brackets:

- Name, which is passed as parameter to a constructor
- Hit points (10), represent the health of the ClapTrap
- Energy points (10)
- Attack damage (0)

Add the following public member functions to the ClapTrap:

- void attack(const std::string& target);
- void takeDamage(unsigned int amount);
- void beRepaired(unsigned int amount);

When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
or energy points left.

In all of these member functions, you have to print a message to describe what hap-
pens. For example, the attack() function may display something like (of course, without
the angle brackets):
ClapTrap <name> attacks <target>, causing <damage> points of damage!

---

**Ex01:**

You will now script a derived robot. It will be named ScavTrap and will inherit the constructors and destructor from ClapTrap. However, its constructors, destructor and attack() will print different messages.

Note that proper construction/destruction chaining must be shown in your tests. When a ScavTrap is generated, the program starts by building a ClapTrap.
ScavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and
must initialize them to:

- Name, which is passed as parameter to a constructor
- Hit points (100), represent the health of the ClapTrap
- Energy points (50)
- Attack damage (20)

ScavTrap will also have its own special capacity:

	void guardGate();

This member function will display a message informing that ScavTrap is now in Gate
keeper mode. Add more tests to your program.

---

**Ex02:**

Now, implement a FragTrap class that inherits from ClapTrap. It is very similar to
ScavTrap. However, its construction and destruction messages must be different. Proper
construction/destruction chaining must be shown in your tests. When a FragTrap is
created, the program starts by building a ClapTrap. Destruction is in reverse order.
Same things for the attributes, but with different values this time:

- Name, which is passed as parameter to a constructor
- Hit points (100), represent the health of the ClapTrap
- Energy points (100)
- Attack damage (30)

FragTrap has a special capacity too:

	void highFivesGuys(void);

This member function displays a positive high fives request on the standard output.
Again, add more tests to your program.

---
