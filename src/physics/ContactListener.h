/* 
 * File:   ContactListener.h
 * Author: Koura
 *
 * Created on 17 May 2015, 14:56
 */

#ifndef CONTACTLISTENER_H
#define	CONTACTLISTENER_H

#include "../utils/PropertyUtil.h"
#include "Box2D/Box2D.h"

class ContactListener : public b2ContactListener {
public:
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
};

#endif	/* CONTACTLISTENER_H */

