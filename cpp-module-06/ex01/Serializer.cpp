/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:41:15 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/17 12:44:07 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(Serializer const &src) { (void)src; }

Serializer::~Serializer(void) {}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	Data		*ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}
