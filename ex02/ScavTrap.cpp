/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:24:50 by mawako            #+#    #+#             */
/*   Updated: 2025/12/16 15:44:11 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->dead = false;
	std::cout << this->_name << " is BLACKWATCH!\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "DESTROYED!\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->dead && this->_energyPoints != 0)
	{
		if (this->_name == "GENJI")
			std::cout << "[BLACKWATCH] " << this->_name << " *DragonBlade* " << target << ", " << this->_attackDamage << " DMG!\n";
		else
			std::cout << "[BLACKWATCH] " << this->_name << " ATTACKED " << target << ", " << this->_attackDamage << " DMG!\n";
		this->_energyPoints--;
		std::cout << "[BLACKWATCH] " << this->_name << " Energy is " << this->_energyPoints << ".\n";
	}
	else if (this->dead)
	{
		std::cout << "[BLACKWATCH] " << this->_name << "...?\n";
		std::cout << "[BLACKWATCH] " << "There's no response.\n";
		std::cout << "[BLACKWATCH] " << "It's just a corpse.\n";
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "[BLACKWATCH] " << this->_name << " ATTACKED " << target << "!\n";
		std::cout << "[BLACKWATCH] " << "...But not enough EP!\n";
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (amount != 0 && this->_hitPoints > (int)amount)
	{
		std::cout << "[BLACKWATCH] " << this->_name << " was ATTACKED!\n";
		this->_hitPoints -= amount;
		std::cout << "[BLACKWATCH] " << this->_name << "'s HP is " << this->_hitPoints << "!\n";
	}
	else if (amount == 0)
	{
		std::cout << "[BLACKWATCH] " << this->_name << " was ATTACKED!\n";
		std::cout << "[BLACKWATCH] " << "*DEFLECTED*\n";
	}
	else if (this->_hitPoints <= (int)amount)
	{
		std::cout << "[BLACKWATCH] " << this->_name << " was ATTACKED!\n";
		std::cout << "[BLACKWATCH] " << this->_name << " SMAAAASH!!\n";
		this->_hitPoints = 0;
		this->dead = true;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (!this->dead && amount != 0 && this->_energyPoints != 0)
	{
		std::cout << "[BLACKWATCH] " << this->_name << " get healed!\n";
		this->_hitPoints += amount;
		std::cout << "[BLACKWATCH] " << this->_name << "'s HP is " << this->_hitPoints << "!\n";
		this->_energyPoints--;
		std::cout << "[BLACKWATCH] " << this->_name << " Energy is " << this->_energyPoints << ".\n";
	}
	else if (this->dead)
	{
		std::cout << "[BLACKWATCH] " << this->_name << "...?\n";
		std::cout << "[BLACKWATCH] " << "There's no response.\n";
		std::cout << "[BLACKWATCH] " << "It's just a corpse.\n";
	}
	else if (amount == 0)
	{
		std::cout << "[BLACKWATCH] " << this->_name << " is pinging too much!\n";
		std::cout << "[BLACKWATCH] " << "I need healing.\n";
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "[BLACKWATCH] " << this->_name << " has no EP!\n";
	}
}
void	ScavTrap::guardGate()
{
	std::cout << "[BLACKWATCH] " << this->_name << " IS NOW GUARDIAN MODE...\n";
}
