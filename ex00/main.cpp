/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 01:41:27 by mawako            #+#    #+#             */
/*   Updated: 2025/12/23 21:20:04 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a("MOYRA");
	ClapTrap	b("GENJI");
	ClapTrap	c(b);
	a.attack("GENJI");
	b.takeDamage(0);
	b.attack("MOYRA");
	a.takeDamage(0);
	b.beRepaired(1000);
	c.attack("GENJI");
}
