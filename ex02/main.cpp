/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 01:41:27 by mawako            #+#    #+#             */
/*   Updated: 2025/12/16 05:07:54 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	a("MOYRA");
	ScavTrap	b("GENJI");
	FragTrap	c("DOOM-FIST");
	a.attack("GENJI");
	b.takeDamage(0);
	b.attack("MOYRA");
	c.attack("GENJI");
	a.takeDamage(0);
	b.beRepaired(1000);
	c.takeDamage(2);
	b.guardGate();
	c.highFiveGuys();
}
