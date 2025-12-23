/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 01:41:27 by mawako            #+#    #+#             */
/*   Updated: 2025/12/23 21:26:36 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	a("MOYRA");
	ScavTrap	b("GENJI");
	ScavTrap	c(b);
	a.attack("GENJI");
	b.takeDamage(0);
	b.attack("MOYRA");
	a.takeDamage(0);
	b.beRepaired(1000);
	b.guardGate();
	c.attack("GENJI");
	c.guardGate();
}
