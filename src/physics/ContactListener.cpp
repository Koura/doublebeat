#include "ContactListener.h"
#include <iostream>

int numFootContacts = 0;

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

void ContactListener::EndContact(b2Contact* contact) {
    void* fixtureUserData = contact->GetFixtureA()->GetUserData();
    if ((int64_t) fixtureUserData == 1)
        PropertyUtil::decreaseContacts();

    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if ((int64_t) fixtureUserData == 1)
        PropertyUtil::decreaseContacts();
}