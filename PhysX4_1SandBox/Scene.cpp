#include "Scene.hpp"

using namespace std;
using namespace physx;

bool Scene::simulateStep() noexcept(false){
	return(property_.simulateStep(1.0f / simulaton_frequency_));
}

void Scene::addStaticActor(PxRigidStatic& actor) noexcept(false){
	property_.scene_->addActor(actor);
	return;
}

void Scene::addDynamicActor(PxRigidDynamic& actor) noexcept(false){
	property_.scene_->addActor(actor);
	return;
}