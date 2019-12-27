#include "Ground.hpp"

using namespace std;
using namespace physx;

void Ground::initialize() noexcept(false){
	createMaterial();
	createShape();
	createActor();

	return;
}

void Ground::createMaterial() noexcept(false){
	material_ = PxGetPhysics().createMaterial(DEFAULT_STATIC_FRICTION_, DEFAULT_DYNAMIC_FRICTION_, DEFAULT_RESTITUTION_);
	return;
}

void Ground::createShape() noexcept(false){
	PxPlaneGeometry geometry;
	shape_ = PxGetPhysics().createShape(geometry, *material_);
}

void Ground::createActor() noexcept(false){
	actor_ = PxCreateStatic(PxGetPhysics(), transform_, *shape_);
	return;
}