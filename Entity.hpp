/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:58:28 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/12 12:58:30 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
#define ENTITY_H

class IEntity
{
    public:
        virtual ~IEntity() {};
        virtual void move() = 0;
        virtual void tick();

  
};

#endif //ENTITY_H

