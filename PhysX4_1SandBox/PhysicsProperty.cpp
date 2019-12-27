#include "PhysicsProperty.hpp"

using namespace std;
using namespace physx;

const bool PhysicsProperty::simulateStep(PxReal time) noexcept(false){
	scene_->simulate(time);
	return(scene_->fetchResults(true));
}

const bool PhysicsProperty::initialize(const float_t gravity) noexcept(false){
	if(!createFoundation()){
		return(false);
	}
	if(!createPVD()){
		return(false);
	}
	if(!createPhysics()){
		return(false);
	}
	if(!createCooking()){
		return(false);
	}

	if(!PxInitExtensions(*physics_, pvd_)){
		return(false);
	}

	if(!createDispacher()){
		return(false);
	}
	if(!createScene(gravity)){
		return(false);
	}
	if(!createPVDClient()){
		return(false);
	}

	return(true);
}

const bool PhysicsProperty::createFoundation() noexcept(false){
	foundation_ = PxCreateFoundation(PX_PHYSICS_VERSION, allocator_, error_callback_);

	if(foundation_ == nullptr){
		return(false);
	}
	return(true);
}

const bool PhysicsProperty::createPVD() noexcept(false){
	pvd_ = PxCreatePvd(*foundation_);

	if(pvd_ == nullptr){
		return(false);
	}

	return(pvd_->connect(*PxDefaultPvdSocketTransportCreate(LOCAL_HOST_NAME_, PORT_NUM_, TIME_OUT_), PxPvdInstrumentationFlag::eALL));
}

const bool PhysicsProperty::createPhysics() noexcept(false){
	physics_ = PxCreatePhysics(PX_PHYSICS_VERSION, *foundation_, PxTolerancesScale(), false, pvd_);
	if(physics_ == nullptr){
		return(false);
	}

	return(true);
}

const bool PhysicsProperty::createCooking() noexcept(false){
	PxCookingParams cooking_param(physics_->getTolerancesScale());
	cooking_param.buildGPUData = true;

	cooking_ = PxCreateCooking(PX_PHYSICS_VERSION, *foundation_, cooking_param);
	if(cooking_ == nullptr){
		return(false);
	}

	return(true);
}

const bool PhysicsProperty::createDispacher() noexcept(false){
	dispatcher_ = PxDefaultCpuDispatcherCreate(thread_num_);
	if(dispatcher_ == nullptr){
		return(false);
	}

	return(true);
}

const bool PhysicsProperty::createScene(const float_t gravity) noexcept(false){
	PxSceneDesc descriptor(physics_->getTolerancesScale());
	descriptor.gravity = PxVec3(0.0f, gravity, 0.0f);

	descriptor.cpuDispatcher = dispatcher_;
	descriptor.filterShader = PxDefaultSimulationFilterShader;
	scene_ = physics_->createScene(descriptor);

	if(scene_ == nullptr){
		return(false);
	}

	return(true);
}

const bool PhysicsProperty::createPVDClient() noexcept(false){
	PxPvdSceneClient* const client = scene_->getScenePvdClient();

	if(client == nullptr){
		return(false);
	}

	client->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_CONSTRAINTS, true);
	client->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_CONTACTS, true);
	client->setScenePvdFlag(PxPvdSceneFlag::eTRANSMIT_SCENEQUERIES, true);

	return(true);
}