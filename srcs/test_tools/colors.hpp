/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:53:23 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/04 14:53:31 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

# define COLOR_RESET "\033[0m"
# define COLOR_RED "\033[1;31m"
# define COLOR_BLUE "\033[1;34m"
# define COLOR_GREEN "\033[1;32m"
# define COLOR_WHITE "\033[1;37m"
# define COLOR_YELLOW "\033[1;93m"

# define COLOR_RED_(str) COLOR_RED << str << COLOR_RESET
# define COLOR_BLUE_(str) COLOR_BLUE << str << COLOR_RESET
# define COLOR_GREEN_(str) COLOR_GREEN << str << COLOR_RESET
# define COLOR_WHITE_(str) COLOR_WHITE << str << COLOR_RESET
# define COLOR_YELLOW_(str) COLOR_YELLOW << str << COLOR_RESET

#endif
