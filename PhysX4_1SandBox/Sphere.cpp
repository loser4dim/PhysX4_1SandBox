#include "Sphere.hpp"

using namespace std;
using namespace physx;

const bool Sphere::initialize() noexcept(false){
	if(!createMaterial()){
		return(false);
	}
	if(!createShape()){
		return(false);
	}
	//TODO
	if(!createActor(6, 1)){
		return(false);
	}

	return(true);
}

const bool Sphere::createMaterial() noexcept(false){
	material_ = PxGetPhysics().createMaterial(DEFAULT_STATIC_FRICTION_, DEFAULT_DYNAMIC_FRICTION_, DEFAULT_RESTITUTION_);
	if(material_ == nullptr){
		return(false);
	}
	material_->setFrictionCombineMode(PxCombineMode::eMAX);
	return(true);
}

const bool Sphere::createShape() noexcept(false){
	PxSphereGeometry geometry;
	geometry.radius = radius_;
	shape_ = PxGetPhysics().createShape(geometry, *material_);
	if(shape_ == nullptr){
		return(false);
	}
	return(true);
}

const bool Sphere::createActor(const physx::PxU32 pos_it, physx::PxU32 velo_it) noexcept(false){
	actor_ = PxCreateDynamic(PxGetPhysics(), transform_, *shape_, density_);
	if(actor_ == nullptr){
		return(false);
	}
	actor_->setSolverIterationCounts(pos_it, velo_it);
	return(true);
}