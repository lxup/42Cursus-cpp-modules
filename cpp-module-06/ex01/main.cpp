/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:43:29 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/19 17:17:17 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		data;
	Data		*ptr;
	Data		*deserialized;
	uintptr_t	raw;

	data.number = 42;
	data.valid = true;
	ptr = &data;
	std::cout << "Data number: " << ptr->number << std::endl;
	std::cout << "Data valid: " << ptr->valid << std::endl;
	std::cout << "Data address: " << ptr << std::endl;
	raw = Serializer::serialize(ptr);
	std::cout << "Raw address: " << raw << std::endl;
	deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized number: " << deserialized->number << std::endl;
	std::cout << "Deserialized valid: " << deserialized->valid << std::endl;
	std::cout << "Change number from deserialized to 21" << std::endl;
	deserialized->number = 21;
	std::cout << "Data number: " << ptr->number << std::endl;
	return (0);
}
