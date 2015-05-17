#include "ContactListener.h"
#include <iostream>

//Checks if feet are connecting with a boundary object, such as the ground
void ContactListener::BeginContact(b2Contact* contact) {
    void* fixtureUserData = contact->GetFixtureA()->GetUserData();
    if ((int64_t) fixtureUserData == 1) {
        PropertyUtil::incrementContacts();
    }
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if ((int64_t) fixtureUserData == 1) {
        PropertyUtil::incrementContacts();
    }
}
//Marks that hero's feet are no longer touching a boundary object
void ContactListener::EndContact(b2Contact* contact) {
    void* fixtureUserData = contact->GetFixtureA()->GetUserData();
    if ((int64_t) fixtureUserData == 1)
        PropertyUtil::decreaseContacts();

    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if ((int64_t) fixtureUserData == 1)
        PropertyUtil::decreaseContacts();
}