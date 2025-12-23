/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 01:41:27 by mawako            #+#    #+#             */
/*   Updated: 2025/12/23 22:18:03 by mawako           ###   ########.fr       */
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

	FragTrap	d(c);

	b.guardGate();
	c.highFiveGuys();
	d.attack("GENJI");
	d.takeDamage(2);
	c.takeDamage(2);
}
