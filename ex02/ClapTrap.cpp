/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:56:32 by mawako            #+#    #+#             */
/*   Updated: 2025/12/16 15:43:01 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), dead(false)
{
	std::cout << this->_name << " joined the match.\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " left the match.\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->dead && this->_energyPoints != 0)
	{
		if (this->_name == "GENJI")
			std::cout << "[OVERWATCH] " << this->_name << " *DragonBlade* " << target << ", " << this->_attackDamage << " DMG!\n";
		else
			std::cout << "[OVERWATCH] " << this->_name << " ATTACKED " << target << ", " << this->_attackDamage << " DMG!\n";
		this->_energyPoints--;
		std::cout << "[OVERWATCH] " << this->_name << " Energy is " << this->_energyPoints << ".\n";
	}
	else if (this->dead)
	{
		std::cout << "[OVERWATCH] " << this->_name << "...?\n";
		std::cout << "[OVERWATCH] " << "There's no response.\n";
		std::cout << "[OVERWATCH] " << "It's just a corpse.\n";
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "[OVERWATCH] " << this->_name << " ATTACKED " << target << "!\n";
		std::cout << "[OVERWATCH] " << "...But not enough EP!\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount != 0 && this->_hitPoints > (int)amount)
	{
		std::cout << "[OVERWATCH] " << this->_name << " was ATTACKED!\n";
		this->_hitPoints -= amount;
		std::cout << "[OVERWATCH] " << this->_name << "'s HP is " << this->_hitPoints << "!\n";
	}
	else if (amount == 0)
	{
		std::cout << "[OVERWATCH] " << this->_name << " was ATTACKED!\n";
		std::cout << "[OVERWATCH] " << "*DEFLECTED*\n";
	}
	else if (this->_hitPoints <= (int)amount)
	{
		std::cout << "[OVERWATCH] " << this->_name << " was ATTACKED!\n";
		std::cout << "[OVERWATCH] " << this->_name << " SMAAAASH!!\n";
		this->_hitPoints = 0;
		this->dead = true;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->dead && amount != 0 && this->_energyPoints != 0)
	{
		std::cout << "[OVERWATCH] " << this->_name << " get healed!\n";
		this->_hitPoints += amount;
		std::cout << "[OVERWATCH] " << this->_name << "'s HP is " << this->_hitPoints << "!\n";
		this->_energyPoints--;
		std::cout << "[OVERWATCH] " << this->_name << " Energy is " << this->_energyPoints << ".\n";
	}
	else if (this->dead)
	{
		std::cout << "[OVERWATCH] " << this->_name << "...?\n";
		std::cout << "[OVERWATCH] " << "There's no response.\n";
		std::cout << "[OVERWATCH] " << "It's just a corpse.\n";
	}
	else if (amount == 0)
	{
		std::cout << "[OVERWATCH] " << this->_name << " is pinging too much!\n";
		std::cout << "[OVERWATCH] " << "I need healing.\n";
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "[OVERWATCH] " << this->_name << " has no EP!\n";
	}
}
