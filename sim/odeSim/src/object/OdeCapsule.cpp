//
// Created by kangd on 15.02.18.
//

#include "OdeCapsule.hpp"

ode_sim::object::OdeCapsule::OdeCapsule(double radius,
                                  double height,
                                  double mass,
                                  dWorldID worldID,
                                  dSpaceID spaceID,
                                  benchmark::CollisionGroupType collisionGroup,
                                  benchmark::CollisionGroupType collisionMask)
    : OdeSingleBodyObject(worldID, spaceID) {


  // body
  body_ = dBodyCreate(worldID);

  // geometry
  geometry_ = dCreateCapsule(spaceID, radius, height);
  dGeomSetBody(geometry_, body_);

  // material prop
  dGeomSetData(geometry_, &matrialProp_);

  // collision group
  dGeomSetCategoryBits(geometry_, collisionGroup);
  dGeomSetCollideBits(geometry_, collisionMask);

  // position and orientation
  dMatrix3 R;
  dRSetIdentity(R);
  dBodySetPosition(body_, 0, 0, 0);
  dBodySetRotation(body_, R);

  // mass and local inertia
  dMassSetCapsuleTotal(&mass_, mass, 3, radius, height);
  dBodySetMass(body_, &mass_);

  // gyroscopic effect
  dBodySetGyroscopicMode(body_, true);

}
