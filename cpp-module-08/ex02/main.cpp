/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:53:44 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/26 19:15:30 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int	main(void)
{
	{
		std::cout << "Using MutantStack" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);

		// Custom tests
		std::cout << "Custom tests" << std::endl;
		MutantStack<int> mstack2;
		mstack2.push(1);
		mstack2.push(2);
		mstack2.push(3);

		MutantStack<int>::iterator it2 = mstack2.begin();
		MutantStack<int>::iterator ite2 = mstack2.end();
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
	}

	{
		std::cout << "Using std::list" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}

		// Custom tests
		std::cout << "Custom tests" << std::endl;
		std::list<int> mstack2;
		mstack2.push_back(1);
		mstack2.push_back(2);
		mstack2.push_back(3);

		std::list<int>::iterator it2 = mstack2.begin();
		std::list<int>::iterator ite2 = mstack2.end();
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
	}

	return (0);
}
