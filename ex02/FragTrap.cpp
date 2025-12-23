/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 03:01:03 by mawako            #+#    #+#             */
/*   Updated: 2025/12/23 22:14:41 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	this->_dead = false;
	std::cout << "[Frag] " << this->_name << " Appeared!\n";
	std::cout << this->_name << " is TARON!\n";
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	std::cout << "[Frag] " << this->_name << " Coppied!\n";
}

FragTrap::~FragTrap()
{
	std::cout << "[Frag] " << this->_name << " Destroyed!\n";
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	ClapTrap::operator=(other);
	return (*this);
}

void		FragTrap::attack(const std::string& target)
{
	if (!this->_dead && this->_energyPoints != 0)
	{
		if (this->_name == "GENJI")
			std::cout << "[TARON] " << this->_name << " *DragonBlade* " << target << ", " << this->_attackDamage << " DMG!\n";
		else
			std::cout << "[TARON] " << this->_name << " ATTACKED " << target << ", " << this->_attackDamage << " DMG!\n";
		this->_energyPoints--;
		std::cout << "[TARON] " << this->_name << " Energy is " << this->_energyPoints << ".\n";
	}
	else if (this->_dead)
	{
		std::cout << "[TARON] " << this->_name << "...?\n";
		std::cout << "[TARON] " << "There's no response.\n";
		std::cout << "[TARON] " << "It's just a corpse.\n";
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "[TARON] " << this->_name << " ATTACKED " << target << "!\n";
		std::cout << "[TARON] " << "...But not enough EP!\n";
	}
}

void		FragTrap::takeDamage(unsigned int amount)
{
	if (amount != 0 && this->_hitPoints > (int)amount)
	{
		std::cout << "[TARON] " << this->_name << " was ATTACKED!\n";
		this->_hitPoints -= amount;
		std::cout << "[TARON] " << this->_name << "'s HP is " << this->_hitPoints << "!\n";
	}
	else if (amount == 0)
	{
		std::cout << "[TARON] " << this->_name << " was ATTACKED!\n";
		std::cout << "[TARON] " << "*DEFLECTED*\n";
	}
	else if (this->_hitPoints <= (int)amount)
	{
		std::cout << "[TARON] " << this->_name << " was ATTACKED!\n";
		std::cout << "[TARON] " << this->_name << " SMAAAASH!!\n";
		this->_hitPoints = 0;
		this->_dead = true;
	}
}

void		FragTrap::beRepaired(unsigned int amount)
{
	if (!this->_dead && amount != 0 && this->_energyPoints != 0)
	{
		std::cout << "[TARON] " << this->_name << " get healed!\n";
		this->_hitPoints += amount;
		std::cout << "[TARON] " << this->_name << "'s HP is " << this->_hitPoints << "!\n";
		this->_energyPoints--;
		std::cout << "[TARON] " << this->_name << " Energy is " << this->_energyPoints << ".\n";
	}
	else if (this->_dead)
	{
		std::cout << "[TARON] " << this->_name << "...?\n";
		std::cout << "[TARON] " << "There's no response.\n";
		std::cout << "[TARON] " << "It's just a corpse.\n";
	}
	else if (amount == 0)
	{
		std::cout << "[TARON] " << this->_name << " is pinging too much!\n";
		std::cout << "[TARON] " << "I need healing.\n";
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "[TARON] " << this->_name << " has no EP!\n";
	}
}

void		FragTrap::highFiveGuys()
{
	std::cout << "HIGH FIVE!\n";
}
